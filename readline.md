# <center>readline</center>

[TOC]

## 一、路径

```powershell
一、玩客云 > 分区1 > onecloud > tools > ncurses-5.9.tar.gz
二、CSDN 个人下载历史查找
```



## 二、安装

### 1、依赖包

> 必须先安装 ncurses，无论 PC 机还是交叉编译



### 2、PC机安装

```
./configure ; make ; make install
```



### 3、交叉编译

```powershell
一、先进行 ./configure 配置 CPU 和操作系统
对于PPC系列CPU：
# ./configure CC=/ppc_gcc4.8.2_glibc2.18.0_multi/ppc-linux-gnu-gcc --host=ppc-linux CROSS_COMPILE=ppc-linux-gcc
对于 ARM 系列 CPU：
# ./configure CC=/arm-linux-gcc-4.3.2/arm-linux-gnu-gcc --host=arm-linux CROSS_COMPILE=arm-linux-gcc

configure 或 make 过程中会报错，需要改造 ./configure 文件：
将 6324 行 ‘if test "$cross_compiling" = yes. then’ ...
中的 yes 改为 no


二、解决编译失败问题
# make
报错：找不到 rlstdc.h
将 history.h 中的 ‘#include <readline/rlstdc.h>‘进行改造。

三、确认文件是否是目标机器的格式，用 file 命令。可以看到CPU架构、静态/动态编译
[wishcell@localhost c]$ file a.out
a.out: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.32, BuildID[sha1]=2084b5c9845cd5bcc61c1ffd9cd77a5d10e618d6, not stripped
```





