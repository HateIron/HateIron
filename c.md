# C语言用例集

[TOC]

## 一、大小端判断

```c
int isBigEndian()
{
    short i = 1;
 	char *p = (char *)&i;
    return (*p == 1) ? __little : __big;
}
```



## 二、构造带参数的函数

```c
int use_func(int argc, char **argv)
{
    return 0;
}

int construct_para_func(int a)
{
    int   argc          = 2;
    char *argv[3]       = {NULL};
    int   argv_0_buf[8] = {0};
    
    argv[0] = argv_0_buf;
    sprintf(argv_0_buf, "%d", a);
    
    return use_func(argc, argv);
}
```

## 三、计算文件大小

```c
#include <sys/stat.h>  
int file_size2(char* filename)  
{  
    struct stat statbuf;  
    stat(filename,&statbuf);  
    int size=statbuf.st_size;  
    return size;  
}            
```

## 四、文件大小裁剪

```c
#include <unistd.h>    //包含ftruncate()头文件
#include <cstdio>       //包含结构体FILE头文件
int main(void)
{
    FILE *in;
    in = fopen("in.txt", "ab+");
    int a=fileno(in);
    ftruncate(a,size);
    return 0;
}
```

## 五、毫秒级打印

```c
#include <sys/time.h>  
#include <stdio.h>  
int  main(void)
{
    int i;
    struct timeval tv;
    for (i = 0; i < 4; i++)
    {
        gettimeofday(&tv, NULL);
        printf("%d\t%d\n", tv.tv_usec, tv.tv_sec);
        sleep(1);
    }
    return 0;
}
```

##六、管道 `pipe`

```

```

