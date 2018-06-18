#<center>jenkins</center>

[TOC]

##一、jenkins 参数化构建

```shell
1、选择参数化构建，然后选择字符串参数,分别填上变量名和默认值
2、变量名/默认值分别为
	 name :tag1   = sss
	 name :tag2   = bbb
3、在构建脚本中填写如下内容，即可打印出 tag1 / tag2 的默认值
command:
	echo $tag1
	echo $tag2
```



##二、jenkins 用 python 脚本实现时，如何接收构建军参数

```python
#!/usr/bin/python
import os,sys
tag1 = os.getenv("tag1")
tag2 = os.getenv("tag2")
print "tag1=%s tag2=%s"%(tag1, tag2)
```



##三、如何远程触发参数化构建

> ### 远程参数化命令，老是收到出错提示：
>
> ```
> No Valid crumb was included in the request
> ```
>
> 解决办法：
>
> ​	到 jenkins 系统管理中，取消`启用安全`，取消`跨站点请求伪造`
>
> 命令的正确写法：
>
> ```shell
> curl -X GET "http://192.168.1.122:8080/job/TestPara/buildWithParameters?token=mail_token&prj_name=aa_prj&result=succ" -uroot:root
> ```
>
> 此命令中，token=mail_token 一项，token是在触发器里面配置的，token 和 -u 选项可以省略

###添加文件名，作为参数

```shell
curl -X GET "http://192.168.1.122:8080/job/TestPara/buildWithParameters?token=mail_token&prj_name=aa_prj&result=succ" -F "input=@tag.txt" -uroot:root
```

> #### 实际上，jenkins 接收到的 input ，也只是一个字符串，值为`tag.txt`，并没有里面的内容，而 input 需要在参数里面添加，在字符串参数后面添加一个文件参数即可



## 四、jenkins 设置每2小时构建一次

```powershell
0	１	＊	＊	＊　＃１点
0	３	＊	＊	＊　＃３点
0	５	＊	＊	＊　＃５点
```

#五、linux启动`jenkins`

```powershell
一、首先要有 jenkins.war 包
# java -jar ./jenkins.war --controlPort=8001 --httpPort=8080 --logfile=/var/log/jenkins.log
```

# 六、 jenkins 依赖于 jdk1.8

```powershell
jdk1.8下载路径：
	http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html
```

<iframe src="http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html" width="900px" height="400px" boarder="3px" scrolling="yes"></iframe>

# 七、CentOS升级最新的 GCC确编译器

## **1、** **获取安装包并解压** 

```powershell
wget http://ftp.gnu.org/gnu/gcc/gcc-6.1.0/gcc-6.1.0.tar.bz2
tar -jxvf gcc-6.1.0.tar.bz2
当然，http://ftp.gnu.org/gnu/gcc  里面有所有的gcc版本供下载，最新版本已经有6.1.0啦.
建议下载.bz2的压缩包,文件更小,下载时间更少.
```

##**2、** **下载供编译需求的依赖项**

```powershell
参考文献[1]中说：这个神奇的脚本文件会帮我们下载、配置、安装依赖库，可以节约我们大量的时间和精力。
cd gcc-6.1.0
./contrib/download_prerequisites
```

## 3**、** **建立一个目录供编译出的文件存放** 

```
mkdir gcc-build-6.1.0
cd gcc-build-6.1.0
```

##4、 生成`Makefile`文件 

```
../configure -enable-checking=release -enable-languages=c,c++ -disable-multilib
```

## **5、** **编译** 

```powershell
make -j4
-j4选项是make对多核处理器的优化，如果不成功请使用 make，相关优化选项可以移步至参考文献[2]
```

##6、安装

```powershell
make install
(安装需要root权限!)
查看安装
ls /usr/local/bin | grep gcc
```

## 7、重启，然后查看 gcc 版本号

```
gcc -v
```

##8、 写个C++11 特性的程序段 测试

##**9、升级gcc，生成的动态库没有替换老版本gcc的动态库** 

```powershell
源码编译升级安装了gcc后，编译程序或运行其它程序时，有时会出现类似/usr/lib64/libstdc++.so.6: version `GLIBCXX_3.4.21' not found的问题。这是因为升级gcc时，生成的动态库没有替换老版本gcc的动态库导致的，将gcc最新版本的动态库替换系统中老版本的动态库即可解决。
```

- ### 9.1 运行以下命令检查动态库 

```powershell
strings /usr/lib64/libstdc++.so.6 | grep GLIBC

从输出可以看出，gcc的动态库还是旧版本的。说明出现这些问题，是因为升级gcc时，生成的动态库没有替换老版本gcc的动态库。
```

- ### 9.2 执行以下命令，查找编译`gcc`时生成的最新动态库 

```powershell
find / -name "libstdc++.so*"

将上面的最新动态库libstdc++.so.6.0.22复制到/usr/lib64目录下

cd /usr/lib64

cp /root/Downloads/gcc-6.1.0/gcc-build-6.1.0/stage1-x86_64-pc-linux-gnu/libstdc++-v3/src/.libs/libstdc++.so.6.0.22 ./
```

- ### 9.3 删除原来链接

```
rm -rf libstdc++.so.6
```

- ###9.4 将默认库的软连接指向最新动态库

```
ln -s libstdc++.so.6.0.22 libstdc++.so.6
```

- ### 9.5 默认动态库升级完成。重新运行以下命令检查动态库 

```powershell
strings /usr/lib64/libstdc++.so.6 | grep GLIBC
可以看到 输出有"GLIBCXX_3.4.21" 了
```

