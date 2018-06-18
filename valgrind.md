#<center>valgrind</center>

[TOC]

# 一、工具获取

# 二、`valgrind`组成

##1、`Memcheck `

一切对malloc()/free()/new/delete的调用都会被捕获。所以，它能检测以下问题 :

- 1.对未初始化内存的使用； 
- 2.读/写释放后的内存块；
- 3.读/写超出malloc分配的内存块；  
- 4.读/写不适当的栈中内存块；  
- 5.内存泄漏，指向一块内存的指针永远丢失；  
- 6.不正确的malloc/free或new/delete匹配； 
- 7.memcpy()相关函数中的dst和src指针重叠。  

## 2、`Callgrind`  

- Callgrind收集程序运行时的一些数据，建立函数调用关系图，还可以有选择地进行cache模拟 
- 在运行结束时，它会把分析数据写入一个文件。callgrind_annotate可以把这个文件的内容转化成可读的形式。  

## 3、Cachegrind 

- Cache分析器，它模拟CPU中的一级缓存I1，Dl和二级缓存，能够精确地指出程序中cache的丢失和命中 
- 如果需要，它还能够为我们提供cache丢失次数，内存引用次数，以及每行代码，每个函数，每个模块，整个程序产生的指令数。这对优化程序有很大的帮助。 

##4、Helgrind 

- 它主要用来检查多线程程序中出现的竞争问题。 
- Helgrind寻找内存中被多个线程访问，而又没有一贯加锁的区域，这些区域往往是线程之间失去同步的地方，而且会导致难以发掘的错误。 
- Helgrind实现了名为“Eraser”的竞争检测算法，并做了进一步改进，减少了报告错误的次数。 
- Helgrind仍然处于实验阶段 

## 5、Massif 

- 堆栈分析器，它能测量程序在堆栈中使用了多少内存，告诉我们堆块，堆管理块和栈的大小。 
- Massif能帮助我们减少内存的使用，在带有虚拟内存的现代系统中，它还能够加速我们程序的运行，减少程序停留在交换区中的几率 

## 6、lackey 

- 小工具，较少用到，没有介绍

## 7、nulgrind 

- 只是为开发者展示如何创建一个工具 

## 8、**DRD**  

- 与 helpgrind 类似，也是用于监测进程的，只是技术不同，所以可以发现不同的问题
- 

# 二、安装

```
./configure, make, make install 
```



# 三、使用（官网http://valgrind.org/docs/manual/quick-start.html#quick-start.intro）

## 1、常规检测内存使用有无异常

### A、源码如下

```c
  #include <stdlib.h>

  void f(void)
  {
     int* x = malloc(10 * sizeof(int));
     x[10] = 0;        // problem 1: heap block overrun
  }                    // problem 2: memory leak -- x not freed

  int main(void)
  {
     f();
     return 0;
  }
```

```powershell
[wishcell@localhost c]$ gcc -g ./tt.c  -o tt
[wishcell@localhost c]$ valgrind --leak-check=yes ./tt
==6963== Memcheck, a memory error detector
==6963== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==6963== Using Valgrind-3.12.0 and LibVEX; rerun with -h for copyright info
==6963== Command: ./tt
==6963==
==6963== Invalid write of size 4
==6963==    at 0x40054B: f (tt.c:6)
==6963==    by 0x40055B: main (tt.c:11)
==6963==  Address 0x51f9068 is 0 bytes after a block of size 40 alloc'd | 第6行所用到的内存是在刚
==6963==    at 0x4C29BE3: malloc (vg_replace_malloc.c:299)              | 刚分配的40个字节之后。
==6963==    by 0x40053E: f (tt.c:5)                                     | 意思是说这不是分配的内存
==6963==    by 0x40055B: main (tt.c:11)
==6963==
==6963==
==6963== HEAP SUMMARY:
==6963==     in use at exit: 40 bytes in 1 blocks
==6963==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==6963==
==6963== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==6963==    at 0x4C29BE3: malloc (vg_replace_malloc.c:299)
==6963==    by 0x40053E: f (tt.c:5)   |这里说第５行申请的内存全部泄漏掉了。因为没有释放操作
==6963==    by 0x40055B: main (tt.c:11)
==6963==
==6963== LEAK SUMMARY:
==6963==    definitely lost: 40 bytes in 1 blocks
==6963==    indirectly lost: 0 bytes in 0 blocks
==6963==      possibly lost: 0 bytes in 0 blocks
==6963==    still reachable: 0 bytes in 0 blocks
==6963==         suppressed: 0 bytes in 0 blocks
==6963==
==6963== For counts of detected and suppressed errors, rerun with: -v
==6963== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
[wishcell@localhost c]$ cat tt.c -n
     1    #include <stdlib.h>
     2
     3    void f(void)
     4    {
     5       int* x = malloc(10 * sizeof(int));
     6       x[10] = 0;        // problem 1: heap block overrun
     7    }                    // problem 2: memory leak -- x not freed
     8
     9    int main(void)
    10    {
    11       f();
    12       return 0;
    13    }
[wishcell@localhost c]$
```



# 四、深入研究

## 1、massif 用法

- 源码，同上例

```c
#include <stdlib.h>
void f(void)
{
   int* x = malloc(10 * sizeof(int));
   x[10] = 0;        // problem 1: heap block overrun
}                    // problem 2: memory leak -- x not freed
int main(void)
{
   f();
   return 0;
}
```

```powershell
[wishcell@localhost c]$ gcc -g ./tt.c  -o tt
[wishcell@localhost c]$ valgrind --tool=massif ./tt
[wishcell@localhost c]$ valgrind --tool=massif ./tt
==7238== Massif, a heap profiler
==7238== Copyright (C) 2003-2015, and GNU GPL'd, by Nicholas Nethercote
==7238== Using Valgrind-3.12.0 and LibVEX; rerun with -h for copyright info
==7238== Command: ./tt
==7238==
==7238==

执行后会得到一个文件：massif.out.7238，用命令 ms_print 查看之，可以看到内存的收支情况：
[wishcell@localhost c]$ ms_print massif.out.7238
--------------------------------------------------------------------------------
Command:            ./tt
Massif arguments:   (none)
ms_print arguments: massif.out.7238
--------------------------------------------------------------------------------

     B
   56^                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
     |                                                                       :
   0 +----------------------------------------------------------------------->ki
     0                                                                   106.2

Number of snapshots: 2
 Detailed snapshots: []

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  0              0                0                0             0            0
  1        108,733               56               40            16            0
[wishcell@localhost c]$ 
```

## 2、unbuntu 下有个漂亮的可视化工具，查看massif输出

```
http://blog.csdn.net/unix21/article/details/9330571
```

<iframe src="https://blog.csdn.net/unix21/article/details/9330571" width="900px" height="800px" scrolling="yes"></iframe>

