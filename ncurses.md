# <center>ncurse</center>

[TOC]

## 一、路径

```powershell
一、玩客云 > 分区1 > onecloud > tools > ncurses-5.9.tar.gz
二、http://ftp.gnu.org/pub/gnu/ncurses/
```



## 二、安装

### 1、PC机安装

```
./configure ; make ; make install
```



### 2、交叉编译

```powershell
一、同样先进行 ./configure 配置 CPU 和操作系统
对于PPC系列CPU：
# ./configure CC=/ppc_gcc4.8.2_glibc2.18.0_multi/ppc-linux-gnu-gcc --host=ppc-linux CROSS_COMPILE=ppc-linux-gcc
对于 ARM 系列 CPU：
# ./configure CC=/arm-linux-gcc-4.3.2/arm-linux-gnu-gcc --host=arm-linux CROSS_COMPILE=arm-linux-gcc

二、解决编译失败问题
# make
报错：找到 curses.h ，搜索 mouse_trafo 锁定 1584 行：
 extern NCURSES_EXPORT(bool) mouse_trafo(int*,int*,bool);/*generated*/
然后将后面的注释删除，是由于注释引起编译错误。原因未知。

三、确认文件是否是目标机器的格式，用 file 命令。可以看到CPU架构、静态/动态编译
[wishcell@localhost c]$ file a.out
a.out: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.32, BuildID[sha1]=2084b5c9845cd5bcc61c1ffd9cd77a5d10e618d6, not stripped
```

