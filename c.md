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

# 七、C语言长/短参数

```

```

# 八、目录读取

```powershell
相关函数：open, opendir, closedir, rewinddir, seekdir, telldir, scandir

头文件：#include <sys/types.h>  
       #include <dirent.h>

定义函数：struct dirent * readdir(DIR * dir);

函数说明：readdir()返回参数dir 目录流的下个目录进入点。结构dirent 定义如下：
struct dirent
{
     ino_t d_ino; //d_ino 此目录进入点的inode
     ff_t d_off;  //d_off 目录文件开头至此目录进入点的位移
     signed short int d_reclen; //d_reclen _name 的长度, 不包含NULL 字符
     unsigned char d_type;      //d_type d_name 所指的文件类型 d_name 文件名
     har d_name[256];
 };

返回值：成功则返回下个目录进入点. 有错误发生或读取到目录文件尾则返回NULL.

附加说明：EBADF 参数dir 为无效的目录流。

 范例
 #include <sys/types.h>
 #include <dirent.h>
 #include <unistd.h>
 int main()
 {
     DIR * dir;
     struct dirent * ptr;
     int i;
     dir = opendir("/etc/rc.d");
     while((ptr = readdir(dir)) != NULL)
     {
         printf("d_name : %s\n", ptr->d_name);
     }
     closedir(dir);
 }
```

# 九、linux 下C语言实现`ls -l`功能(尚未验证)

> 来自(https://blog.csdn.net/u013007900/article/details/51019433)

```c
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>

void show_file_info(char* filename, struct stat* info_p)
{
    char* uid_to_name(), *ctime(), *gid_to_name(), *filemode();
    void mode_to_letters();
    char modestr[11];

    mode_to_letters(info_p->st_mode, modestr);

    printf("%s", modestr);
    printf(" %4d", (int) info_p->st_nlink);
    printf(" %-8s", uid_to_name(info_p->st_uid));
    printf(" %-8s", gid_to_name(info_p->st_gid));
    printf(" %8ld", (long) info_p->st_size);
    printf(" %.12s", 4 + ctime(&info_p->st_mtime));
    printf(" %s\n", filename);
}

void mode_to_letters(int mode, char str[])
{
    strcpy(str, "----------");

    if (S_ISDIR(mode))
    {
        str[0] = 'd';
    }

    if (S_ISCHR(mode))
    {
        str[0] = 'c';
    }

    if (S_ISBLK(mode))
    {
        str[0] = 'b';
    }

    if ((mode & S_IRUSR))
    {
        str[1] = 'r';
    }

    if ((mode & S_IWUSR))
    {
        str[2] = 'w';
    }

    if ((mode & S_IXUSR))
    {
        str[3] = 'x';
    }

    if ((mode & S_IRGRP))
    {
        str[4] = 'r';
    }

    if ((mode & S_IWGRP))
    {
        str[5] = 'w';
    }

    if ((mode & S_IXGRP))
    {
        str[6] = 'x';
    }

    if ((mode & S_IROTH))
    {
        str[7] = 'r';
    }

    if ((mode & S_IWOTH))
    {
        str[8] = 'w';
    }

    if ((mode & S_IXOTH))
    {
        str[9] = 'x';
    }
}

char* uid_to_name(uid_t uid)
{
    struct passwd* getpwuid(),* pw_ptr;
    static char numstr[10];

    if((pw_ptr = getpwuid(uid)) == NULL)
    {
        sprintf(numstr,"%d",uid);

        return numstr;
    }
    else
    {
        return pw_ptr->pw_name;
    }
}

char* gid_to_name(gid_t gid)
{
    struct group* getgrgid(),* grp_ptr;
    static char numstr[10];

    if(( grp_ptr = getgrgid(gid)) == NULL)
    {
        sprintf(numstr,"%d",gid);
        return numstr;
    }
    else
    {
        return grp_ptr->gr_name;
    }
}
void do_ls(char dirname[])
{
    DIR* dir_ptr;
    struct dirent* direntp;

    if ((dir_ptr = opendir(dirname)) == NULL)
    {
        fprintf(stderr, "ls2: cannot open %s \n", dirname);
    }
    else
    {
        while ((direntp = readdir(dir_ptr)) != NULL)
        {
            dostat(direntp->d_name);
        }

        close(dir_ptr);
    }
}

void dostat(char* filename)
{
    struct stat info;

    if (stat(filename, &info) == -1)
    {
        perror(filename);
    }
    else
    {
        show_file_info(filename, &info);
    }
}

int main(int ac,char* av[])
{
    if(ac == 1)
    {
        do_ls(".");
    }
    else
    {
        while(--ac)
        {
            printf("%s: \n",++*av);
            do_ls(*av);
        }
    }
}
```



# 十、C语言判断字符串是文件还是目录

```powershell
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() 
{ 
    char* fileName = "aa.txt"; 
    struct stat buf; 
    int result; 
    result = stat( fileName, &buf ); 
    if ( S_IFDIR & buf.st_mode)
    { 
        printf("folder\n"); 
    }
    else if (S_IFREG & buf.st_mode)
    { 
        printf("file\n"); 
    } 

    return 0; 
} 
```





