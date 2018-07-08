#linux常用命令

[TOC]

#一、`tar 压缩/解压`

##1、tar -xf ./abc.tar.gz

##2、tar -cf ./abc.tar.gz ./abc

#二、解压工具

### linux 一般都是自带。windows 要么安装`mingw`，要么安装`cygwin`，都极其庞大
>所幸有 windows 版的 tar 工具 http://download.csdn.net/download/u013752213/10243530

# 三、 '*.zip'文件的解压

## 1、CentOS中zip压缩和unzip解压缩命令详解

```powershell
以下命令均在/home目录下操作
cd /home #进入/home目录
1、把/home目录下面的mydata目录压缩为mydata.zip
	zip -r mydata.zip mydata #压缩mydata目录
2、把/home目录下面的mydata.zip解压到mydatabak目录里面
	unzip mydata.zip -d mydatabak
3、把/home目录下面的abc文件夹和123.txt压缩成为abc123.zip
	zip -r abc123.zip abc 123.txt
4、把/home目录下面的wwwroot.zip直接解压到/home目录里面
	unzip wwwroot.zip
5、把/home目录下面的abc12.zip、abc23.zip、abc34.zip同时解压到/home目录里面
	unzip abc\*.zip
6、查看把/home目录下面的wwwroot.zip里面的内容
	unzip -v wwwroot.zip
7、验证/home目录下面的wwwroot.zip是否完整
	unzip -t wwwroot.zip
8、把/home目录下面wwwroot.zip里面的所有文件解压到第一级目录
	unzip -j wwwroot.zip

系统运维 温馨提醒：qihang01原创内容版权所有,转载请注明出处及原文链接
=====================================================
主要参数
-c：将解压缩的结果
-l：显示压缩文件内所包含的文件
-p：与-c参数类似，会将解压缩的结果显示到屏幕上，但不会执行任何的转换
-t：检查压缩文件是否正确
-u：与-f参数类似，但是除了更新现有的文件外，也会将压缩文件中的其它文件解压缩到目录中
-v：执行是时显示详细的信息
-z：仅显示压缩文件的备注文字
-a：对文本文件进行必要的字符转换
-b：不要对文本文件进行字符转换
-C：压缩文件中的文件名称区分大小写
-j：不处理压缩文件中原有的目录路径
-L：将压缩文件中的全部文件名改为小写
-M：将输出结果送到more程序处理
-n：解压缩时不要覆盖原有的文件
-o：不必先询问用户，unzip执行后覆盖原有文件
-P<密码>：使用zip的密码选项
-q：执行时不显示任何信息
-s：将文件名中的空白字符转换为底线字符
-V：保留VMS的文件版本信息
-X：解压缩时同时回存文件原来的UID/GID
```

#四、`*.rar`文件解压

```powershell
    首先解压rar文件需要unrar命令，要使用这种命令我们必须安装rarlinux，我们可以在终端使用yum installrar，如果没有可安装的程序包，我们可以自行下载，上网搜搜就能搜到。

    安装rarlinux，安装此程序必须使用root身份才能安装，首先我们要以root身份运行，然后打开下载目录，使用tar命令解压缩rarlinux文件，当然你可以选择解压缩的位置，为了方便，小编就解压在了当前目录。

    解压完成后我们便要安装它，首先我们要打开刚才解压的那个文件夹，然后使用make命令进行安装，我们可以看到一些安装的程序在运行，等光标移动到命令输入行，证明我们已经安装成功了。

    接来下我们就可以解压缩rar文件了，我们可以使用unrar命令来解压缩，当然首先你要确保rarlinux安装成功了，否则不能使用unrar命令。具体命令如下图所示，这样就把amp.rar里面的压缩文件都解压在了下载目录中，如果你想解压在别的地方，可以更改命令，小编就在这里阐述了

    其实还有一种更简单的解压缩方法，就是直接右键解压缩到此处（前提条件就是你必须安装了rarlinux，如果没有安装，点击解压缩会出现找不到程序），用它解压的好处就是直接把它里面的内容解压到了与它同名的文件夹中。
```

# 五、 linux 时间设置

```powershell
设置日期为 2014年6月18日：
	date -s 06/18/14
将时间设置为：14点20分50秒：
	date -s 14:20:50
```



