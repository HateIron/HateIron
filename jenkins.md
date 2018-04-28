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



