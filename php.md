#<center>php</center>

[TOC]

## 一、基于win10搭建php环境

```powershell
这里是基于win10配置php-7.1.0+apache2.4.23+mysql-5.7.16的介绍
```

###工具/原料

>- 环境 win10 64位（32位的电脑选择下载32位的，32位的软件能在64位的电脑运行，反之则不行，最好是下载和电脑位数匹配的）
>- php-7.1.0 php-7.1.0-Win32-VC14-x64.zip 
>- apache 2.4.23 httpd-2.4.23-win64-VC14.zip 
>- mysql-5.7.16 mysql-5.7.16-winx64.zip

###方法/步骤 1、下载相应的软件（没有装vc14的一定要安装)

>- 先去微软官网下载vc14,网址为https://www.microsoft.com/zh-cn/download/details.aspx?id=48145，这里下载中文简体的，然后下载好之后一步步安装就好了。
>- 下载apache 2.4.23， httpd-2.4.23-win64-VC14.zip，网址为http://www.apachelounge.com/download/，这里选择的是免安装版的
>- 下载php-7.1.0，php-7.1.0-Win32-VC14-x64.zip 
>   这里我们选择的是线程安全版，关于线程安全版与非线程安全版的区别可 
>  自行上网查阅相关资料，下载网址为http://windows.php.net/download/ 
>   ，最后注意选择相应位数的版本下载，这里我是下载64位的
>- 下载mysql-5.7.16，mysql-5.7.16-winx64.zip，下载网址为http://dev.mysql.com/downloads/mysql/，同样的选择64位的下载。32位的电脑下载32位的。这个软件也是免安装版的，到时候只要解压到某个文件夹就好了。

###方法/步骤2、开始安装

>* Apache我们这里下载的是zip压缩包，解压后放到合适的位置就好了，这里我们放在E盘的phptools文件夹中的ApacheServer文件夹中，这个文件夹是自己新建的，可以自己命名。
>* php 下载后也是zip包，同样解压到合适位置，我们这里也将其放在E盘的phptools文件夹下的php7.1目录下,php7.1文件夹需要自己新建
>* MySQL选择的是免安装版的，也就是Zip压缩包，这就更简单了，同样是解压到合适的位置，这里我们也将其放在E盘的phptools文件夹下的MySQL目录下,解压安装后如下图

###方法/步骤3、配置PHP

> * 首先将E:\phptools\php7.1\php.ini-production  复制一份，并重命名为php.ini；
> * 将 
>   E:\phptools\php7.1和E:\phptools\php7.1\ext加入环境变量PATH中,选中计算机，右键属性-->高级系
>    统设置 -->环境变量-->系统变量，找到Path，编辑，在其后加上;E:\phptools\php7.1;E:\phptools
>    \php7.1\ext

### 方法/步骤4、配置Apache

> * 用记事本打开E:\phptools\ApacheServer\Apache\conf
>
>   查找ServerRoot，修改ServerRoot "C:/Apache24" => ServerRoot "E:/phptools/ApacheServer/Apache"（这里输入的是你解压apache安装包后放的位置）
>
> * 查找#ServerName www.example.com:80 ，修改为 ServerName 
>   localhost:80 (去掉前面的#)，如果你的电脑的80端口已经被占用了的话，这里我们就不能用80端口了，可以修改成其它的端口，比如90。当然我们还要搜索Listen，把80端口改成90，其它的就不用修改了，只需要修改这两个地方。
>
> * 查找DocumentRoot "c:/Apache24/htdocs" ， 修改为DocumentRoot "E:/phptools/ApacheServer/Apache/htdocs" 
>
> * 查找<Directory "c:/Apache24/htdocs"> ，修改为 <Directory " E:/phptools/ApacheServer/Apache/htdocs ">
>
> * 找到DirectoryIndex index.html ，修改为 DirectoryIndex index.html index.php index.htm (这里我们添加了index.php index.htm)
>
> * 查找ScriptAlias /cgi-bin/ "c:/Apache24/cgi-bin/"  ，修改为 ScriptAlias /cgi- bin/ "E:/phptools/ApacheServer/Apache/cgi-bin"
>
> * 查找<Directory "c:/Apache24/cgi-bin"> 修改为 <Directory "E:/phptools/ApacheServer/Apache/cgi-bin/">
>
> * 最后在E:/phptools/ApacheServer/Apache/conf/httpd.conf最后一行加上
>
>   LoadModule php7_module "E:/phptools/php7.1/php7apache2_4.dll"
>
>   AddHandler application/x-httpd-php .php .html .htm
>
>   AddType application/x-http-php .php .html .htm
>
>   PHPIniDir "E:/phptools/php7.1"

###方法/步骤5、然后将Apache安装到系统服务中

> + 然后我们如果把Apache安装到系统服务中的话，我们就可以直接在系统服务中启动了。具体方法是打开任务管理器——>服务——>找到Apache，然后右键启动就好了。
> + 当然这里不安装也是可以的，只是启动Apache的时候要到E:\phptools\ApacheServer\Apache\bin\ApacheMonitor.exe中去，启动前还要运行httpd.exe

### 方法/步骤6、开启几个常用的php扩展

> - 用记事本打开E:\phptools\php7.1\php.ini
>
>   将; extension_dir = "ext"修改为 extension_dir = "ext" （去掉extension前面的分号）
>
>   将;extension=php_mbstring.dll 修改为 extension=php_mbstring.dll（去掉extension前面的分号,这是php多字节字符串扩展）
>
>   将;extension=php_mysqli.dll 修改为 extension=php_mysqli.dll（去掉extension前面的分号） 

### 方法/步骤7、MySQL的配置

```
MySQL免安装版环境配置已有朋友写过相关经验，我就不赘述了，参考

经验朋友niyikai写的经验即可。

但是这里需要注意的是5.7版本里面没有data文件夹。在启动之前需要初始化，使用cmd命令行进入bin文件夹后，再输入mysqld --initialize ,这样才能正常启动MySQL。还有密码的问题，5.7版本的MySQL随机附带了一个登录密码。这个密码在后来生成的data文件夹下。文件的名字是你的计算机名.err。

2016-12-10T16:18:50.886005Z 1 [Note] A temporary password is generated for root@localhost: fdglskdjggsl    加粗的即为登录密码。还有需要注意的是cmd命令必须是以管理员权限运行的，否则权限不够，会报错。下图就是MySQL成功启动并且登录后的界面。
```

## 二、环境配置好后，验证一下

<a href="./win10_PHP_Apache_MySQL_EnvSetup.html">win10_PHP_Apache_MySQL_EnvSetup.html</a>



## 三、第一个页面

```powershell
在 E:\phptools\ApacheServer\Apache\htdocs 目录下，建立一个 index.php ，内容如下：

<!DOCTYPE html>
<html>
<body>

<?php
echo "Hello World!<br/>";
echo strlen("Hello world!\n"); 
?>

</body>
</html>
```

> 启动 apache服务器，并浏览之
>
> ![](./pictures/apache_php_run.png)