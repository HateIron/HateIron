## 1. 获取下载地址

以下为开源的下载地址：

<http://qt-project.org/downloads>

在网页上选择符合自己机型的源码。

要下载的有两样东西。

（1）Qt Creator安装程序。
（2）Qt SDK。



## 2. Qt Creator安装

### 2.1 下载

我使用 wget 命令下载了需要的源码。

`> mkdir ~/qt-downloads`

`> cd ~/qt-downloads`

`> wget http://download.qt-project.org/official_releases/qtcreator/2.8/2.8.1/qt-creator-linux-x86-opensource-2.8.1.run`

qt-creator-linux-x86-opensource-2.8.1.run 就被下载到了 ~/qt-downloads 路径下。

### 2.2 修改文件权限

修改该文件的权限，使之有执行权限。

` chmod u+x qt-creator-linux-x86-opensource-2.8.1.run`

### **2.3 安装**

### **\****

执行bin文件开始安装Qt Create

`> sudo ./qt-creator-linux-x86-opensource-2.8.1.run`

其期，安装向导会询问安装路径，我是把文件安装到 /usr/local/ 目录下的。

完成安装之后，Applications --> Programming 菜单下就有一个 Qt Creator 的入口。点击会弹出Qt Creator 的界面



## 3. QT SDK安装

虽然安装了Qt Creator，还是不能进行工程创建、编译。还需要安装Qt SDK。

参考这篇博文：http://blog.csdn.net/siren0203/article/details/5634563

### 3.1 下载

`> cd ~/qt-downloads`

`wget http://download.qt-project.org/official_releases/qt/4.8/4.8.5/qt-everywhere-opensource-src-4.8.5.tar.gz`

获取Qt源代码，放到 qt-download，然后解压这文件。

### 3.2 解压

`> tar zxvf  qt-everywhere-opensource-src-4.8.5.tar.gz`

### 3.3 设备环境变量

解压完成之后，进入解压后的源码目录，执行以下命令：

```shell
$ QTDIR=$(pwd)
$ PATH=$QTDIR/bin:$PATH
$ MANPATH=$QTDIR/man:$MANPATH
$ LD_LIBRARY_PATH=$QTDIR/lib:$LD_LIBRARY_PATH
```

设置好了待会编译需要的环境变量。



### 3.4 配置

这段脚本的功能就是添加我们刚解压的目录中的bin,bin,man路径到环境变量中。

然后，执行配置：

`> ./configure`

当然，执行这个命令的前提是你的GCC是安装完全了的。

没有的话就要安装。

### 3.5 编译

这个过程可能要花3～5分钟。执行完成后，再编译：

`> gmake`

编译时间有一点长，我花了90分钟，稍安铁勿躁。

### 3.6 安装

`> sudo make install`

### 3.7 完成

进入 qt-downloads/qt-everywhere-commercial-src-4.8.4 的 bin 目录，执行 designer 就会出现窗口设计界面。

安装就OK了！



## 4 配置

昨天把Qt Creator与Qt SDK安装好了。但是打开Qt Creator还是建不了工程，无法进行开发工作。

![img](http://static.oschina.net/uploads/img/201301/23215504_jD1Y.png)

今天我在自己工作的电脑上也装了一个开发环境，经同事的指点，略知一二了。

找到Qt Creator的菜单[Tool]->[Option...]，点击后弹出Option对话框：

![img](http://static.oschina.net/uploads/img/201301/23215504_ZS3E.png)

在左边的列表框里选择"Build & Run"->"Qt Versions"，再点右边的"Add..."按钮，会弹出文件选择对话框。

选我们昨天编译的Qt SDK路径bin目录下的qmake文件：

![img](http://static.oschina.net/uploads/img/201301/23215505_JMgz.png)然后点击Open或双击qmake选中。

补充：昨天在 make install 的时候，我把Qt SDK安装到了 /usr/local 目录下。在这个目录下多了一个 Trolltech 的文件夹。

这个文件夹可能就是昨天安装Qt SDK时生成的。

这里的这个 qmake 也应该是可以的，可能这个还更合适一些。我个人觉得应该选这个目录下的qmake。

这个问题以后再试。（试验证明是可以的，而且本来就应该选这个qmake，而不是选安装目录下的qmake）

好，语归正传，指定了qmake后，Option对话框的显示更新了：

![img](http://static.oschina.net/uploads/img/201301/23215507_WQhI.png)

再进入Kits页：

![img](http://static.oschina.net/uploads/img/201301/23215508_R1tC.png)

注意看到光标所指的下拉选择框"Qt version"，将原来的"none"选成上图所示的Qt SDK。

点OK，完成配置并退出Option对话框。

现在可以顺利创建工程了：

![img](http://static.oschina.net/uploads/img/201301/23215509_SZ4R.png)

下面我就不再多说了，你会的。

 

