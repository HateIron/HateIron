# GDB

[TOC]

### 一、 项目编译中遇到奇怪问题，gdb 无法跟踪代码，问题解决

```powershell
(gdb)l
Line number 2 outof range
./path/code/serial.c has 1 lines
(gdb)l 1
1 ^M#include<sys/types.h>^M$include<sys/stat.h>^M//#include<sys/time.h>^M//#include<sys/ioctrl.h>^M#include<unistd.h>^M<termios.h>^M#...
```

> #### 查看出问题所在，在`gdb`下面输入`l`命令时，报错`Line number 2 outof range ./path/code/serial.c has 1 lines`，但是输入`l 1`或者`l 2`时，有杂乱的输出。
>
> 显然是代码换行出了问题
>
> #### 于是用vim 打开，`set ff=unix`，然后把`^M`替换成`\r`
>
> ```powershell
> ^M在 windows的 vim 上没有生成成功，但是在 linux 下成功了
> 就是按 ctrl-v然后回车，替换命令为
>  :%s/^M/\r/g
> ```
>
> 只是不知为什么 `dos2unix`工具为什么在这时候失灵



## 二、 gdb 中代码跟踪时，宏无法打印问题

```powershell
在 Makefile 中加入参数 -g3 和 --gdwarf-2 ，这样就可以在 gdb 中打印宏了
```

