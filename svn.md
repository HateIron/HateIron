#<center>svn</center>

[TOC]

# 一、[SVN1.9.4  新版安装教程](./2018-01/linux_subversion-1.9.4_包含依赖插件和说明文档.zip)（因基本可用，自己未整理）

>### 1、 下载 svn 软件包和依赖包
>
>### 2、安装 依赖软件包 
>
>```shell
>tar zxvf apr-1.5.1.tar.gz  
>cd apr-1.5.1/  
>./configure --prefix=/usr/local/apr  
>make 
>make install  
>cd ../   
>cd apr-util-1.5.1/  
>./configure --prefix=/usr/local/apr-util --with-apr=/usr/local/apr  
>make 
>make install  
>```
>
>后面其他的依赖软件包安装过程基本一样，解压 、配置、编译、安装
>
>### 3、安装 svn
>
>注意这里是 SVN 和 sqlite 解压到一起再安装的
>
>```shell
>tar xvf subversion-1.9.3.tar.gz  
>tar xvf sqlite-amalgamation.tar.gz  
>mv sqlite-amalgamation ./subversion-1.9.3/sqlite-amalgamation  
>cd subversion-1.9.3 
>./configure --prefix=/usr/local/svn --with-apr=/usr/local/apr --with-apr-util=/usr/local/apr-util --without-berkeley-db 
>```
>
>```
>在编译安装subvision时，提示configure: error: Subversion requires SQLite， 原因是需要依赖Sqlite。
>解决方法：下载sqlite-3.6.13 ，解压后，进入sqlite目录，复制sqlite3.c到subvision源码文件sqlite-amalgamation目录下，如果没有sqlite-amalgamation目录，手动新建一个即可。
>```
>
>```shell
>make 
>make install  
>```
>
>至此svn安装完毕!
>
>### 4、修改环境变量 
>
>```shell
>vi /etc/profile  
>文件末尾加入: 
>PATH=$PATH:/usr/local/svn/bin  
>export PATH  
>使环境变量生效
>source /etc/profile
>```
>
>###5、检测是否安装成功
>
>```shell
>svnserve --version  
># 显示如下信息则表示安装成功。
># svnserve, version 1.9.3
>```
>
>### 6、开启防火墙 SVN 端口
>
>```shell
>iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 9999 -j ACCEPT  
>保存防火墙设置 
>/etc/rc.d/init.d/iptables save  
>```
>
>### 7、创建 svn 库 www
>
>```shell
>mkdir -p /var/svn/  
>cd /var/svn/  
>/var/svn/svnadmin create www  
>cd www/conf/  
>ls  
># 有3个 当前项目配置文件
># authz   passwd   svnserve.conf
>```
>
>### 8、配置版本库信息
>
>```shell
>vi svnserve.conf  
>修改：去掉注释符 
>anon-access = none  
>auth-access = write  
>password-db = passwd  
>authzauthz-db = authz  
>realm = www  
>这里要注意：每一行的都要你顶头，不能有空格，不然会报错
>定义版本库访问权限： 
># vi authz  
>添加： （这里可以用用户组设置权限r：read w：wirte）
>[/]  
>用户名= rw
>设定用户密码： 
># vi passwd  
>添加（用户名=密码）： 
>用户名= 123456
>```
>
>### 9、启动 SVN
>
>```shell
>给这个 www 建立一个 svn 自带的 svnserve：
>svnserve -d -r /var/svn/svnadmin
>
>最后给这个svn库使用启动命令:
>svnserve -d --listen-port 8089 -r /var/svn/svnadmin/www
>注意：后面启动系统后给这个svn库启动的时候就用此命令。
>查看是否启动成功
>ps -ef | grep svnserve
>客户端就可以进行资源库的访问，svn访问路径为svn://XXX.XXX.XXX.XXX:8089。
>```
>
>###10、[Linux下SVN自动更新web](http://blog.csdn.net/lgm252008/article/details/7026426)
>
>```shell
>第一步:建立你的web程序目录和版本库目录
>mkdir /data/webwww/project1
>svnadmin create /data/svnwww/project1
>
>进入/data/webwww/project1目录。
>svn co testsvn svn://192.168.1.110:8080/project1/branch/v1.0
>//检出一份版本库文件到当前目录 /data/webwww/project1
>
>第二步:在项目库的 hooks/ 目录下新建 post-commit 文件 【钩子脚本】
>添加脚本内容如下：
>#!/bin/sh
>/usr/local/bin/svn up --username=webdev --password=123456 --no-auth-cache --non-interactive /data/webwww/project1 > /dev/null
>
>#要更新的目录
>/data/webwww/project1
>
>第三步:让post-commit有执行的权限,并将checkout的项目相关权限和宿主改一下
>chmod 777 post-commit
>chown -R www:www ./.svn
>chown -R www:www ./.svn/*
>chown -R www:www ./.svn/
>chown -R www:www ./.svn
>chown -R www:www ./
>
>
>第四步:这里就已经完成了，第四步就是测试了。
>```
>
>```shell
>我们知道要把svn的内容更新到web目录需要手动的svn up，为了可以在修改完代码提交到SVN服务器后,WEB服务器直接同步，需要配置SVN的钩子。
>1.打开hooks目录,可以看到有一个post-commit.tmpl文件,这是一个模板文件,复制一份放在此目录下,命名为post-commit，不要后缀，
>里面原有的代码全部注释掉.这里可以执行shell命令,每次commit完成后都会调用此文件.
>文件内容为
>#!/bin/sh 
>export LANG=zh_CN.UTF-8   #字符集，与服务器一致，可执行locale命令查看
>/usr/local/svn/bin/svn update --username test --password 111111 /www/yun
>说明:
>#!/bin/sh   说明是执行shell命令
>export LANG=zh_CN.GBK 是为了解决svn post commit 中文乱码，设置本地化编码,SVN默认是UTF-8编码,如果不设置将会出现错误,而执行不成功,错误标识为svn: Can't convert string from native encoding to 'UTF-8'
>/usr/bin/svn 	#svn安装的bin目录
>/var/www/myproject  #要更新的目录
>如果提示:post-commit hook failed (exit code 255) with no output赋予post-commit文件可执行权限
>如果您的默认编码就是UTF-8的，要上传中文文件，先将文件另存为UTF-8格式在提交
>让post-commit有执行的权限  chmod 777 post-commit
>现在可以去客户端提交看看是否成功
>
>```
>
>### 11、linux 下常用 svn 命令
>
>```shell
>svn checkout svn://192.168.1.1/pro/domain
>svn add file
>svn commit -m "add test file for my test" test.php
>svn lock -m "lock test file" test.php // svn unlock PATH
>svn update -r m path  //svn update -r 200 test.php
>svn status path
>svn status -v path
>svn status
>svn diff
>svn revert
>svn delete path -m "delete test fle"  简写：svn (del, remove, rm)
>svn delete svn://192.168.1.1/pro/domain/test.php -m "delete test file"
>svn ci -m 'delete test file‘
>svn log path
>svn info path   例如：svn info test.php
>svn diff -r m:n path
>svn diff -r 200:201 test.php 简写：svn di
>svn merge -r m:n path
>svn merge -r 200:205 test.php（将版本200与205之间的差异合并到当前文件，但是一般都会产生冲突，需要处理一下）
>svn help
>svn help ci
>svn list path 简写：svn ls 显示path目录下的所有属于版本库的文件和目录
>```
>
>```shell
>svn mkdir: 创建纳入版本控制下的新目录。
>用法: 1、mkdir PATH...
>   2、mkdir URL...
>创建版本控制的目录。
>1、每一个以工作副本 PATH 指定的目录，都会创建在本地端，并且加入新增调度，以待下一次的提交。
>2、每个以URL指定的目录，都会透过立即提交于仓库中创建。
>在这两个情况下，所有的中间目录都必须事先存在。
>```
>
>```shell
>恢复本地修改: svn revert
>
>svn switch (sw): 更新工作副本至不同的URL。
>用法: 1、switch URL [PATH]
>   2、switch --relocate FROM TO [PATH...]
>1、更新你的工作副本，映射到一个新的URL，其行为跟“svn update”很像，也会将服务器上文件与本地文件合并。这是将工作副本对应到同一仓库中某个分支或者标记的方法。
>2、改写工作副本的URL元数据，以反映单纯的URL上的改变。当仓库的根URL变动(比如方案名或是主机名称变动)，但是工作副本仍旧对映到同一仓库的同一目录时使用这个命令更新工作副本与仓库的对应关系。
>```
>
>```shell
>svn resolved: 移除工作副本的目录或文件的“冲突”状态。
>用法: resolved PATH...
>注意: 本子命令不会依语法来解决冲突或是移除冲突标记；它只是移除冲突的相关文件，然后让 PATH 可以再次提交。
>```
>
>```shell
>svn cat 目标[@版本]...如果指定了版本，将从指定的版本开始查找。
>svn cat -r PREV filename > filename (PREV 是上一版本,也可以写具体版本号,这样输出结果是可以提交的)
>```
>
>
>
>

#二、[2018-02-11 7:38] svn 客户端进行`svn log`时报错怎么办

> #### 进行 svn log 操作时，老是提示 offline，然后无法查看 log。
>
> 解决方案：
>
> ​	首先切换到服务器，打开配置文件
>
> ```shell
> vim /home/svn_root/repository/conf/svnserve.conf
> ```
>
> 然后将 anon-access=none。 这一句配好。它的默认值是 anon-access=read，要改掉

# 三、 `svn`入库

```powershell
# svn status ./
# svn add ./ --force
# svn ci
```

