# <center>easylogger </center>

[TOC]

# 一、源码下载



# 二、对easylogger 二次开发研究。

结论：必须开启异步模式，否则打印频繁时，容易丢数据。经测异步模式，打印间隔在 5ms 以上就不会有问题

```powershell
异步 buffer 明显有字符拼接不顺畅，放大延时到5ms以上，就没有问题了。加一句 usleep(5*1000)即可

经细查，发现输出到屏幕上既然完好，为何输出到文件乱七八糟？

原来EasyLogger采用了一个大的缓冲 buffer.

每次只使用其中一部分，而后面部分并没有进行 memset，所以他在输出到屏幕时，采用了 printf("%.*s", size, log); .* 即是指定长度为 size, log 为很长的一个数组地址。
```

```c
#include <malloc.h>
#include <elog.h>

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

#define SCROLL_FILE_SZ  (1024*1024*2)
#define SCROLL_BLOCK_SZ (1024*2)

static pthread_mutex_t output_lock;
typedef struct
{
    FILE *pLogHandle;
    int   cursor;
    char *pScrollerBuf;
}ScrollerStruct;

ScrollerStruct g_Scroller = {NULL, 0, NULL};
/**
 * EasyLogger port initialize
 *
 * @return result
 */
char fileBuff[1024*40] = {0};
ElogErrCode elog_port_init(void)
{
    ElogErrCode result = ELOG_NO_ERR;
    struct stat statbuf;
    if (0 != stat("./log",&statbuf))
    {
        statbuf.st_size = 0;
    }
    pthread_mutex_init(&output_lock, NULL);
   if (NULL == g_Scroller.pLogHandle)
    {
        g_Scroller.pLogHandle = fopen("./log", "a+");
        if (NULL == g_Scroller.pLogHandle)
        {
            printf("g_Scroller.pLogHandle init fail!\n");
            return result;
        }
setbuf(g_Scroller.pLogHandle, fileBuff);
        g_Scroller.cursor = (int)statbuf.st_size;
	    printf("g_Scroller.cursor init to %d\n", g_Scroller.cursor);
        g_Scroller.pScrollerBuf = (char *)malloc(SCROLL_FILE_SZ);
        if (NULL == g_Scroller.pScrollerBuf )
        {
            printf("g_Scroller.pScrollerBuf  init fail!\n");
            return result;
        }
    }
    return result;
}
int scrl_tm = 0;
static void scroll_log()
{
    size_t  read_len = 0;
    int     fno      = fileno(g_Scroller.pLogHandle);
    memset(g_Scroller.pScrollerBuf, 0, SCROLL_FILE_SZ);
    fseek(g_Scroller.pLogHandle, SCROLL_BLOCK_SZ, SEEK_SET);
    read_len = fread(g_Scroller.pScrollerBuf, 1,
                     SCROLL_FILE_SZ,
                     g_Scroller.pLogHandle);
    rewind(g_Scroller.pLogHandle);
    printf("have scrolled %d times \n", scrl_tm++);
    fwrite(g_Scroller.pScrollerBuf, 1,
           read_len, g_Scroller.pLogHandle);
    g_Scroller.cursor = read_len;
    fflush(g_Scroller.pLogHandle);
    if (ftruncate(fno, g_Scroller.cursor) < 0)
    {
        perror("ftruncate failed\n");
        exit(0);
    }
}
int g_TerminalDbg=0;
void elog_port_output(const char *log, size_t size)
{
    FILE     *pFile   = NULL;
    int      fno      = fileno(g_Scroller.pLogHandle);
    struct stat statbuf;
    /* output to terminal */
    if (1 == g_TerminalDbg)
    {
        printf("%.*s", size, log);
        return;
    }
    if ( g_Scroller.cursor > SCROLL_FILE_SZ)
    {
        scroll_log();
    }
    fwrite(log, 1, strlen(log),g_Scroller.pLogHandle);
    fflush(g_Scroller.pLogHandle);
    g_Scroller.cursor += (size + 1);
}
void elog_port_output_lock(void) {
    pthread_mutex_lock(&output_lock);
}

void elog_port_output_unlock(void) {
    pthread_mutex_unlock(&output_lock);
}

const char *elog_port_get_time(void) {
    static char cur_system_time[24] = { 0 };
    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep);
    if (p == NULL) {
        return "";
    }
    snprintf(cur_system_time, 18, "%02d-%02d %02d:%02d:%02d", p->tm_mon + 1, p->tm_mday,
            p->tm_hour, p->tm_min, p->tm_sec);
    return cur_system_time;
}
const char *elog_port_get_p_info(void) {
    static char cur_process_info[10] = { 0 };
    snprintf(cur_process_info, 10, "pid:%04d", getpid());
    return cur_process_info;
}
const char *elog_port_get_t_info(void) {
    static char cur_thread_info[10] = { 0 };
    snprintf(cur_thread_info, 10, "tid:%04ld", pthread_self());
    return cur_thread_info;
}
```

