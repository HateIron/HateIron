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

### 1、windows 版管道

###2、 linux 版管道

```c
#include <stdio.h>

int main()
{
    FILE *pPipe        = NULL;
    char  oneLine[256] = {0};

    if ((pPipe = (FILE *)popen("ping www.baidu.com -c 3", "r")) == (FILE *)NULL)
    {
        printf("pipe create failed, pipe = %p\n", pPipe);
        return 1;
    }

    while (fgets(oneLine, sizeof(oneLine), pPipe))
    {
        if (strstr(oneLine, "100% packet loss"))
        {
              printf("network bad ...\n");
              break;
        }
        else
        {
              printf("pipe get string :%s\n", oneLine);
        }
    }
    pclose(pPipe);
}
~
运行效果如下：
[wishcell@localhost c]$ ./a.out
pipe get string :PING www.baidu.com (115.239.211.112) 56(84) bytes of data.
pipe get string :64 bytes from 115.239.211.112 (115.239.211.112): icmp_seq=1 ttl=53 time=35.3 ms
pipe get string :64 bytes from 115.239.211.112 (115.239.211.112): icmp_seq=2 ttl=53 time=66.5 ms
pipe get string :64 bytes from 115.239.211.112 (115.239.211.112): icmp_seq=3 ttl=53 time=45.4 ms
pipe get string :
pipe get string :--- www.baidu.com ping statistics ---
pipe get string :3 packets transmitted, 3 received, 0% packet loss, time 2003ms
pipe get string :rtt min/avg/max/mdev = 35.364/49.116/66.508/12.972 ms
```

