#<center>串口手册</center>

[TOC]

## 1、DB9 针脚用作 `232/485`定义

```shell
       5    4    3    2     1
         9     8   7    6
```

> 各引脚定义为：
>
> ​	2 ： 发送
>
> ​        3：接收
>
> ​        5：地
>
> 其它引脚无定义



## 2、`232/485`两台电脑直连时,连接方式

```shell
A机          B机
2  <------>   3
3  <------>   2
5  <------>   5
```

## 3、`232/485`一端口为DB9，另一端为水晶头的制作

```
DB9的连接，按标准定义接线：                          水晶头568B接法（使用中间四根，也可自行定义）
2  -->  发送（白绿） -----------------------------------------发送（白绿）
3  -->  接收（蓝）   -----------------------------------------接收（蓝）
5  -->  地（白蓝，橙）----------------------------------------地（白蓝，橙）
其它->  无连接

所以从水晶头上看，只接了中间四根：   绿白、橙、蓝、蓝白（发/地/收/地）
```

## 4、水晶头

```
568A标准:
	白绿，绿，白橙，蓝，白蓝，橙，白棕，棕
	
568B标准:
	白橙，橙，白绿，蓝，白蓝，绿，白棕，棕。
```



## 5、通用DB9/RJ45连接方法

## 6、windows 上的串口驱动

```

```



## 7、[linux 串口驱动(转载)](http://blog.csdn.net/w282529350/article/details/7378388)

###例一、

```c
//串口相关的头文件    
#include<stdio.h>      /*标准输入输出定义*/    
#include<stdlib.h>     /*标准函数库定义*/    
#include<unistd.h>     /*Unix 标准函数定义*/    
#include<sys/types.h>     
#include<sys/stat.h>       
#include<fcntl.h>      /*文件控制定义*/    
#include<termios.h>    /*PPSIX 终端控制定义*/    
#include<errno.h>      /*错误号定义*/    
#include<string.h>    
     
     
//宏定义    
#define FALSE  -1    
#define TRUE   0    
     
/*******************************************************************  
* 名称：                  UART0_Open  
* 功能：                打开串口并返回串口设备文件描述  
* 入口参数：        fd    :文件描述符     port :串口号(ttyS0,ttyS1,ttyS2)  
* 出口参数：        正确返回为1，错误返回为0  
*******************************************************************/    
int UART0_Open(int fd,char* port)    
{    
       
    fd = open( port, O_RDWR|O_NOCTTY|O_NDELAY);    
    if (FALSE == fd)    
    {    
        perror("Can't Open Serial Port");    
        return(FALSE);    
    } 
    //恢复串口为阻塞状态                                   
    if(fcntl(fd, F_SETFL, 0) < 0)    
    {    
        printf("fcntl failed!\n");    
        return(FALSE);    
    }         
    else    
    {    
        printf("fcntl=%d\n",fcntl(fd, F_SETFL,0));    
    }    
    //测试是否为终端设备        
    if(0 == isatty(STDIN_FILENO))    
    {    
        printf("standard input is not a terminal device\n");    
        return(FALSE);    
    }    
    else    
    {    
        printf("isatty success!\n");    
    }                  
    printf("fd->open=%d\n",fd);    
    return fd;    
}    
/*******************************************************************  
* 名称：                UART0_Close  
* 功能：                关闭串口并返回串口设备文件描述  
* 入口参数：        fd    :文件描述符     port :串口号(ttyS0,ttyS1,ttyS2)  
* 出口参数：        void  
*******************************************************************/    
     
void UART0_Close(int fd)    
{    
    close(fd);    
}    
     
/*******************************************************************  
* 名称：                UART0_Set  
* 功能：                设置串口数据位，停止位和效验位  
* 入口参数：        fd        串口文件描述符  
*                              speed     串口速度  
*                              flow_ctrl   数据流控制  
*                           databits   数据位   取值为 7 或者8  
*                           stopbits   停止位   取值为 1 或者2  
*                           parity     效验类型 取值为N,E,O,,S  
*出口参数：          正确返回为1，错误返回为0  
*******************************************************************/    
int UART0_Set(int fd,int speed,int flow_ctrl,int databits,int stopbits,int parity)    
{    
       
    int   i;    
    int   status;    
    int   speed_arr[] = { B115200, B19200, B9600, B4800, B2400, B1200, B300};    
    int   name_arr[] = {115200,  19200,  9600,  4800,  2400,  1200,  300};    
             
    struct termios options;    
       
    /*tcgetattr(fd,&options)得到与fd指向对象的相关参数，并将它们保存于options,该函数还可以测试配置是否正确，该串口是否可用等。若调用成功，函数返回值为0，若调用失败，函数返回值为1.  
    */    
    if( tcgetattr( fd,&options)  !=  0)    
    {    
        perror("SetupSerial 1");        
        return(FALSE);     
    }    
      
    //设置串口输入波特率和输出波特率    
    for ( i= 0;  i < sizeof(speed_arr) / sizeof(int);  i++)    
    {    
        if  (speed == name_arr[i])    
        {                 
            cfsetispeed(&options, speed_arr[i]);     
            cfsetospeed(&options, speed_arr[i]);      
        }
    }         
       
    //修改控制模式，保证程序不会占用串口    
    options.c_cflag |= CLOCAL;    
    //修改控制模式，使得能够从串口中读取输入数据    
    options.c_cflag |= CREAD;    
      
    //设置数据流控制    
    switch(flow_ctrl)    
    {    
          
        case 0 ://不使用流控制    
              options.c_cflag &= ~CRTSCTS;    
              break;       
          
        case 1 ://使用硬件流控制    
              options.c_cflag |= CRTSCTS;    
              break;    
        case 2 ://使用软件流控制    
              options.c_cflag |= IXON | IXOFF | IXANY;    
              break;    
    }    
    //设置数据位    
    //屏蔽其他标志位    
    options.c_cflag &= ~CSIZE;    
    switch (databits)    
    {      
        case 5:    
                 options.c_cflag |= CS5;    
                 break;    
        case 6:    
                 options.c_cflag |= CS6;    
                 break;    
        case 7:        
                 options.c_cflag |= CS7;    
                 break;    
        case 8:        
                 options.c_cflag |= CS8;    
                 break;      
        default:       
                 fprintf(stderr,"Unsupported data size\n");    
                 return (FALSE);     
    }    
    //设置校验位    
    switch (parity)    
    {      
        case 'n':    
        case 'N': //无奇偶校验位。    
                 options.c_cflag &= ~PARENB;     
                 options.c_iflag &= ~INPCK;        
                 break;     
        case 'o':      
        case 'O'://设置为奇校验        
                 options.c_cflag |= (PARODD | PARENB);     
                 options.c_iflag |= INPCK;                 
                 break;     
        case 'e':     
        case 'E'://设置为偶校验      
                 options.c_cflag |= PARENB;           
                 options.c_cflag &= ~PARODD;           
                 options.c_iflag |= INPCK;          
                 break;    
        case 's':    
        case 'S': //设置为空格     
                 options.c_cflag &= ~PARENB;    
                 options.c_cflag &= ~CSTOPB;    
                 break;     
        default:      
                 fprintf(stderr,"Unsupported parity\n");        
                 return (FALSE);     
    }     
    // 设置停止位     
    switch (stopbits)    
    {      
        case 1:       
                 options.c_cflag &= ~CSTOPB; break;     
        case 2:       
                 options.c_cflag |= CSTOPB; break;    
        default:       
                       fprintf(stderr,"Unsupported stop bits\n");     
                       return (FALSE);    
    }    
       
    //修改输出模式，原始数据输出    
    options.c_oflag &= ~OPOST;    
      
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);    
    //options.c_lflag &= ~(ISIG | ICANON);    
       
    //设置等待时间和最小接收字符    
    options.c_cc[VTIME] = 1;/*读取一个字符等待1*(1/10)s时间单位100ms,即0.1秒
    */
    options.c_cc[VMIN] = 1; /* 读取字符的最少个数为1 */    
       
    //如果发生数据溢出，接收数据，但是不再读取 刷新收到的数据但是不读    
    tcflush(fd,TCIFLUSH);    
       
    //激活配置 (将修改后的termios数据设置到串口中）    
    if (tcsetattr(fd,TCSANOW,&options) != 0)      
    {    
        perror("com set error!\n");      
        return (FALSE);     
    }    
    return (TRUE);     
}    
/*******************************************************************  
* 名称：                UART0_Init()  
* 功能：                串口初始化  
* 入口参数：        fd       :  文件描述符     
*               speed  :  串口速度  
*                              flow_ctrl  数据流控制  
*               databits   数据位   取值为 7 或者8  
*                           stopbits   停止位   取值为 1 或者2  
*                           parity     效验类型 取值为N,E,O,,S  
*                        
* 出口参数：        正确返回为1，错误返回为0  
*******************************************************************/    
int UART0_Init(int fd, int speed,int flow_ctrl,int databits,int stopbits,int parity)    
{    
    int err;    
    //设置串口数据帧格式    
    if (UART0_Set(fd,19200,0,8,1,'N') == FALSE)    
    {                                                             
        return FALSE;    
    }    
    else    
    {    
        return  TRUE;    
    }    
}    
     
/*******************************************************************  
* 名称：                  UART0_Recv  
* 功能：                接收串口数据  
* 入口参数：        fd                  :文件描述符      
*                              rcv_buf     :接收串口中数据存入rcv_buf缓冲区中  
*                              data_len    :一帧数据的长度  
* 出口参数：        正确返回为1，错误返回为0  
*******************************************************************/    
int UART0_Recv(int fd, char *rcv_buf,int data_len)    
{    
    int len,fs_sel;    
    fd_set fs_read;    
       
    struct timeval time;    
       
    FD_ZERO(&fs_read);    
    FD_SET(fd,&fs_read);    
       
    time.tv_sec = 10;    
    time.tv_usec = 0;    
       
    //使用select实现串口的多路通信    
    fs_sel = select(fd+1,&fs_read,NULL,NULL,&time);    
    printf("fs_sel = %d\n",fs_sel);    
    if(fs_sel)    
    {    
        len = read(fd,rcv_buf,data_len);    
        printf("I am right!(version1.2) len = %d fs_sel = %d\n",len,fs_sel);    
        return len;    
    }    
    else    
    {    
        printf("Sorry,I am wrong!");    
        return FALSE;    
    }         
}    
/********************************************************************  
* 名称：                  UART0_Send  
* 功能：                发送数据  
* 入口参数：        fd                  :文件描述符      
*                              send_buf    :存放串口发送数据  
*                              data_len    :一帧数据的个数  
* 出口参数：        正确返回为1，错误返回为0  
*******************************************************************/    
int UART0_Send(int fd, char *send_buf,int data_len)    
{    
    int len = 0;    
       
    len = write(fd,send_buf,data_len);    
    if (len == data_len )    
    {
        return len;    
    }         
    else       
    {
        tcflush(fd,TCOFLUSH);    
        return FALSE;    
    }
} 
     
int main(int argc, char **argv)    
{    
    int fd;               //文件描述符    
    int err;              //返回调用函数的状态    
    int len;                            
    int i;    
    char rcv_buf[100];           
    //char send_buf[20]="tiger john";    
    char send_buf[20]="tiger john";  
    if(argc != 3)    
    {    
        printf("Usage: %s /dev/ttySn 0(send data)/1 (receive data) \n",argv[0]);    
        return FALSE;    
    }    
    fd = UART0_Open(fd,argv[1]); //打开串口，返回文件描述符    
    do  
    {    
        err = UART0_Init(fd,19200,0,8,1,'N');    
        printf("Set Port Exactly!\n");    
    }while(FALSE == err || FALSE == fd);    
       
    if(0 == strcmp(argv[2],"0"))    
    {    
        for(i = 0;i < 10;i++)    
        {    
            len = UART0_Send(fd,send_buf,10);    
            if(len > 0)    
                printf(" %d time send %d data successful\n",i,len);    
            else    
                printf("send data failed!\n");    
                              
            sleep(2);    
        }    
        UART0_Close(fd);                 
    }    
    else    
    {                                          
        while (1) //循环读取数据    
        {      
            len = UART0_Recv(fd, rcv_buf,99);    
            if(len > 0)    
            {    
                rcv_buf[len] = '\0';    
                printf("receive data is %s\n",rcv_buf);    
                printf("len = %d\n",len);    
            }    
            else    
            {    
                printf("cannot receive data\n");    
            }    
            sleep(2);    
        }
        UART0_Close(fd);     
    }    
}    
```



### 例二、此例可单独在PC上成功运行

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <type.h>
#include <serial.h>
#include <parser.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

bool serial_debug = false;
int fd = 0;

#define BYTE unsigned char
int speed_arr[] = {B115200, B38400, B57600,
                   B19200,  B9600,  B4800,
				   B2400,   B1200,  B300};
				   
int name_arr    = {115200,  38400,  57600,
				   19200,   9600 ,  4800,
				   2400,    1200,   300};
				   
static void usage(void)
{
	printf("usage:\n");
	printf("####### Are you root? ########\n");
	printf("serial [port name] [baudrate]\n");
	printf("port name : ttyS0 ttyS1 ttyS2 ...\n");
	printf("baudrate  : 4800, 9600, ... 57600... 230400\n");
}

int SetParity(int fd, int DataBits, int StopBits, int Parity)
{
	struct termios options;
	if (tcgetattr(fd, &options) != 0)
	{
		perror("configure serial check 1, failed!\n");
		return -1;
	}
	options.c_cflag &= ~CSIZE;
	
	switch (DataBits)
	{
		case 7:
			options.c_cflag |= CS7;
			break;
		case 8:
			options.c_cflag |= CS8;
			break;
		default:
			fprintf(st
			derr, "can't get bit size!\n");
			return -1;
	}
	
	switch (Parity)
	{
		case 'n':
		case 'N':
			options.c_cflag &= ~PARENB; /* clear parity enable */
			options.c_iflag &= ~INPCK ; /* enable parity checking */
			break;
		case 'o':
		case 'O':
			options.c_cflag |= (PARODD | PARENB); /* set parity to odd */
			options.c_iflag |= INPCK ;            /* disable parity checking */
			break;
		case 'e':
		case 'E':
			options.c_cflag |=   PARENB;  /* enable parity */
			options.c_cflag &=  ~PARODD ; /* use odd parity checking */
			options.c_iflag |=  INPCK ; /* use odd parity checking */
			break;
		case 's':
		case 'S':
			options.c_cflag &= ~PARENB; 
			options.c_iflag &= ~CSTOPB ;
			break;
		default:
			fprintf(stderr, "can't get check bit\n");
			return -1;
	}
	
	switch (StopBits)
	{
		case 1：
			options.c_iflag &= ~CSTOPB ;
			break;
			
		case 2:
			options.c_iflag |= CSTOPB ;
			break;
		default:
			fprintf(stderr, "can't get stop bit\n");
			return -1;
	}
	
	/* set input parity option */
	if (Parity != 'n')
	{
		options.c_iflag |= INPCK;
	}
	
	options.c_cc[VTIME] = 3; /* set one char timeout , unit is 100ms==0.1s */
	options.c_cc[VMIN]  = 6; /* at least get 6 charactor, read function will break */

	tcflush(fd, TCIFLUSH);
	
	if (tcsetattr(fd, TCSANOW, &options) != 0)
	{
		perror("configure serial check 2, failed!\n");
		return -1;
	}
	return 0;	
}	

bool serial_config(int8_t *port_name, u_int32_t baud)
{
	printf("serial port %s init (baudrate = %d) ...\n", port_name, baud);
	char comName[32] = "/dev/";
	strcat(comName, port_name);
	fd = open(comName, O_RDWR);
	if (-1 == fd)
	{
		printf("%s open failed!\n", comName);
		return false;
	}
	
	/* setup the serial port */
	if (!set_up_serial_port(fd, baud))
	{
		printf("setup serial port failed!\n");
		return false;
	}
	
	if (SetParity(fd, 8, 1, (int)'S') < 0)
	{
		printf("parity check configure failed ! \n");
		return false;
	}
	printf(" serial port configure succ!\n");
	return true;	
}

static void serial_close(void)
{
	if (fd)
	{
		close(fd);
	}
}

u_int16_t serial_send_data(u_int8_t *send_buf, u_int32_t data_len)
{
	int len = write(fd, send_buf, data_len);
	if (len == data_len)
	{
		return len;
	}
	else
	{
		tcflush(fd, TCOFLUSH);
		return 0;
	}
	return 0;
}

u_int32_t serial_recv_data(u_int8_t *recv_buf, 
						   u_int32_t len,
						   u_int32_t tout)
{
	struct timeval tv    = {0, 10*1000}; //10ms
	fd_set         rdfds;
	int            ret   = 0;
	int            iRead = 0;
	BYTE           tmpBuff[256] = {0};

	memset(recv_buf, 0, sizeof(recv_buf));
	memset(tmpBuff,  0, sizeof(tmpBuff));
	
	FD_ZERO(&rdfds);
	FD_SET(fd, &rdfds);
	
	ret = select(fd+1, &rdfds, NULL, NULL, &tv);
	if (ret < 0)
	{
		printf("select error %d !\n", ret);
		return iRead;
	}
	if (FD_ISSET(fd, &rdfds))
	{
		memset(tmpBuff, 0, sizeof(tmpBuff));
		iRead = read(fd, tmpBuff, sizeof(tmpBuff));
		if (iRead > 0)
		{
			comm_usleep(20);
			iRead = iRead > 256 ? 256 : iRead;
			memcpy(recv_buf, tmpBuff, iRead)；
		}
		else
		{
			printf("\nread error\n");
		}
	}
	return iRead;	
}
```



## 8、linux 命令行操作串口，详细参数

### A、stty 命令

#### 1、stty -a

```shell
# 查看当前注册终端的设置情况
[wishcell@localhost ~]$ stty -a
speed 38400 baud; rows 51; columns 100; line = 0;
intr = ^C; quit = ^\; erase = ^?; kill = ^U; eof = ^D; eol = <undef>; eol2 = <undef>;
swtch = <undef>; start = ^Q; stop = ^S; susp = ^Z; rprnt = ^R; werase = ^W; lnext = ^V; flush = ^O;
min = 1; time = 0;
-parenb -parodd -cmspar cs8 -hupcl -cstopb cread -clocal -crtscts
-ignbrk -brkint -ignpar -parmrk -inpck -istrip -inlcr -igncr icrnl ixon -ixoff -iuclc -ixany -imaxbel
-iutf8
opost -olcuc -ocrnl onlcr -onocr -onlret -ofill -ofdel nl0 cr0 tab0 bs0 vt0 ff0
isig icanon iexten echo echoe echok -echonl -noflsh -xcase -tostop -echoprt echoctl echoke
```

#### 2、`stty -ixon`

> #####将流控制设置为 OFF，前面有负号`-`，表示清除（禁止）该选项。如果无负号，则被设置

#### 3、`stty ixon`

> #####将流控制设置为 ON

#### 4、`stty ixon 1200`

> #####设置终端波特率为1200，并将流控制设置为 ON

####5、stty 参数`parenb`使终端进行奇偶校验，`-parenb`则禁止检验

####6、stty 使用总览

```
stty [-F device] [--file=device] [SETTING] ...
stty [-F device] [--file=device] [-a|--all]
stty [-F device] [--file=device] [-g|--save]
```

详细参数描述

```shell
-a, --all
　　以可读的格式打印当前的所有设置
-g, --save
　　以终端可读的格式打印当前的所有设置
　　
　　以终端可读的格式打印当前的所有设置
　　-F, --file
　　打开指定的设备,并用此设备作为输入来代替标准输入
　　--help
　　显示帮助并退出
　　--version
　　显示版本信息并退出
　　选项-在SETTING之前使用这些选项将被视为无效 星号*表明是非POSIX设置.以下是一些系统定义了的     
    可用设置：
　　特殊字符
　　* dsusp CHAR CHAR表示输入满时，发一个停止信号给终端
　　eof CHAR
　　CHAR表示一个文件结束 (结束输入)
　　eol CHAR
　　CHAR表示当前行结束
　　* eol2 CHAR CHAR是另一个表示结束当前行的字符
　　erase CHAR
　　CHAR表示擦除最后一个输入字符
　　intr CHAR
　　CHAR表示发一个中断信号
　　kill CHAR
　　CHAR表示擦除当前行
　　* lnext CHAR CHAR表示输入下一个字符
　　quit CHAR
　　CHAR表示发出一个退出信号
　　* rprnt CHAR CHAR表示刷新当前行
　　start CHAR
　　CHAR表示在停止输出后重新开始输出
　　stop CHAR
　　CHAR表示停止输出
　　susp CHAR
　　CHAR表示发送一个终端停止信号
　　* swtch CHAR CHAR表示切换到不同的外壳层
　　* werase CHAR CHAR表示擦除已经输入的最后一个单词
　　特殊设置
　　N
　　把输入和输出的波特率设为N
　　* cols N 通知内核终端有N列
　　* columns N 与cols N 相同
　　ispeed N
　　设置输入速度为N
　　* line N 用行约束规则N
　　min N
　　用 -icanon, 设置一次完整的读操作最小为N个字符
　　ospeed N
　　设置输出速度为N
　　* rows N 通知内核终端有N行
　　* size 根据内核打印出终端的行数和列数
　　speed
　　打印出终端的速度
　　time N
　　同时用 -icanon, 设置读超时为十分之N秒
　　控制设置
　　[-]clocal
　　关闭解调器的控制信号
　　[-]cread
　　允许接收输入
　　* [-]crtscts 允许 RTS/CTS 的握手
　　csN
　　把字符长度设为N, N 为[5..8]
　　[-]cstopb
　　对每字符使用两个停止位 (一个带有 `-')
　　[-]hup
　　当最后一个进程关闭终端后，发一个挂起信号
　　[-]hupcl
　　同 [-]hup
　　[-]parenb
　　在输出中产生奇偶校验位，并要求在输入中也有奇偶校验位
　　[-]parodd
　　设置奇校验 (偶校验用 `-')
　　输入设置:
　　[-]brkint
　　暂停并产生中断信号
　　[-]icrnl
　　将回车解释为换行
　　[-]ignbrk
　　忽略中断信号
　　[-]igncr
　　忽略回车符
　　[-]ignpar
　　忽略有奇偶校验错的字符
　　* [-]imaxbel 对一个字符产生嘟叫，但不刷新已满的输入缓冲区
　　[-]inlcr
　　将换行解释为回车
　　[-]inpck
　　打开输入奇偶校验
　　[-]istrip
　　清除输入字符的高位（第8位）
　　* [-]iuclc 将大写字符转换成小写字符
　　* [-]ixany 使任何字符都重新开始输出（而 不仅仅是重新输出字符能实现此功能）
　　[-]ixoff
　　打开发送开始/停止字符的开关
　　[-]ixon
　　打开XON/XOFF的流量控制
　　[-]parmrk
　　标记奇偶校验错误 (使用255-0-character 字符序列)
　　[-]tandem
　　同 [-]ixoff
　　输出设置:
　　* bsN 回退延迟, N 为 [0..1]
　　* crN 回车延迟, N 为 [0..3]
　　* ffN 换页延迟, N 为 [0..1]
　　* nlN 换行延迟, N 为 [0..1]
　　* [-]ocrnl 将回车解释为换行
　　* [-]ofdel 使用删除字符来填充，而不是用空字符填充
　　* [-]ofill 使用填充字符，不使用定时延迟
　　* [-]olcuc 将小写字符转换成大写
　　* [-]onlcr 将换行解释为回车-换行
　　* [-]onlret 换行执行一次回车
　　* [-]onocr 不在第一列打印回车
　　[-]opost
　　postprocess 输出
　　* tabN 水平tab键延迟, N 为 [0..3]
　　* tabs 同tab0
　　* -tabs 同tab3
　　* vtN 垂直方向tab键延迟。。。, N 为 [0..1]
　　本地设置:
　　[-]crterase
　　将擦除字符显示为：退格-空格-退格
　　* crtkill 根据echoprt和echoe的设置去除所有行
　　* -crtkill 根据echoctl和echok设置去除所有行
　　* [-]ctlecho 在头部符号中显示控制字符'^c')
　　[-]echo
　　显示输入字符
　　* [-]echoctl 同 [-]ctlecho
　　[-]echoe
　　同[-]crterase
　　[-]echok
　　在一个杀死字符后显示一个换行
　　* [-]echoke 同 [-]crtkill
　　[-]echonl
　　即使不显示其它字符也换行
　　* [-]echoprt 向后显示在 '' 和 '/'之间的擦除字符
　　[-]icanon
　　打开 erase, kill, werase, 和 rprnt 这些特殊字符
　　[-]iexten
　　打开 非POSIX 特殊字符
　　[-]isig
　　打开中断，退出和挂起这些特殊字符
　　[-]noflsh
　　在中断和退出这些特殊字符后禁止刷新
　　* [-]prterase 同 [-]echoprt
　　* [-]tostop 停止试图写终端的后台作业
　　* [-]xcase 与icanon同时使用, 表示用`'退出大写状态
　　综合设置:
　　* [-]LCASE 同 [-]lcase
　　cbreak
　　同 -icanon
　　-cbreak
　　同 icanon
　　cooked
　　同 brkint ignpar istrip icrnl ixon opost isig icanon, eof 和 eol字符被设为默认值
　　-cooked
　　同 raw
　　crt
　　同 echoe echoctl echoke
　　dec
　　同 echoe echoctl echoke -ixany intr ^c erase 0177 kill ^u
　　* [-]decctlq 同 [-]ixany
　　ek
　　将擦除，杀死字符设为它们的默认值
　　evenp
　　同 parenb -parodd cs7
　　-evenp
　　同 -parenb cs8
　　* [-]lcase 同 xcase iuclc olcuc
　　litout
　　同 fB-parenb -istrip -opost cs8
　　-litout
　　同 parenb istrip opost cs7
　　nl
　　同 -icrnl -onlcr
　　-nl
　　同 icrnl -inlcr -igncr onlcr -ocrnl -onlret
　　oddp
　　同 parenb parodd cs7
　　-oddp
　　同 -parenb cs8
　　[-]parity
　　同 [-]evenp
　　pass8
　　同 -parenb -istrip cs8
　　-pass8
　　同 parenb istrip cs7
　　raw
　　同 -ignbrk -brkint -ignpar -parmrk -inpck -istrip -inlcr -igncr-icrnl -ixon -ixoff -iuc lc -ixany -imaxbel -opost -isig -icanon-xcase min 1 ti me 0
　　-raw
　　同 cooked
　　sane
　　同 cread -ignbrk brkint -inlcr -igncr icrnl -ixoff -iuclc -ixanyimaxbel opost -olcuc -ocrnl onlcr -onocr -onlret -ofill -ofdel nl0cr0 tab0 bs0 vt0 ff 0 isig icanon iexten echo echoe echok -echonl-noflsh -xcase -tostop -echoprt echoctl echoke, 所有特殊字符 使用缺省值.
　　本命令处理连接到标准输入的终端行.如不带参数,则输出波特率, 行的约束规则,以及与健全 的stty相背离的设置.在设置中,CHAR 是逐字读取的, 或是象 ^c, 0x37, 0177 或127这样的 编码; 特殊值 ^-或未定义被用来禁止特殊字符.
```

####7、详细参数说明

```shell

控制模式	 
clocal	假定一行没有调制解调器控制。
-clocal	假定一行带有调制解调器控制。
cread	启用接收器。
-cread	禁用接收器。
cstopb	每个字符选择两个停止位。
-cstopb	每个字符选择一个停止位。
cs5, cs6, cs7, cs8	选择字符大小。
hup,hupcl	最后关闭时挂起拨号连接。
-hup,-hupcl	最后关闭时不挂起拨号连接。
parenb	启用奇偶性校验的生成和检测。
-parenb	禁用奇偶性校验的生成和检测。
parodd	选择奇校验。
-parodd	选择偶校验。
0	立即挂起电话线路。
speed	将工作站输入和输出速度设置为指定的 speed 数（以位/秒为单位）。并不是所有的硬件接口都支持所有的速度。speed 的可能值有：50、75、110、134、200、300、600、1200、1800、2400、4800、9600、19200、19.2、38400、38.4、exta 和  extb。
注:
exta、19200 和19.2 是同义词；extb、38400 和38.4 是同义词。
ispeed speed	将工作站输入速度设置为指定的 speed 数（以位/秒为单位）。并不是所有的硬件接口都支持所有的速度，而且并不是所有的硬件接口都支持该选项。speed 的可能值与speed 选项相同。
ospeed speed	将工作站输出速度设置为指定的 speed 数（以位/秒为单位）。并不是所有的硬件接口都支持所有的速度，而且并不是所有的硬件接口都支持该选项。speed 的可能值与speed 选项相同。
 
输入模式
brkint	中断时发出 INTR 信号。
-brkint	中断时不发出 INTR 信号。
icrnl	输入时将 CR 映射为 NL。
-icrnl	输入时不将 CR 映射为 NL。
ignbrk	输入时忽略 BREAK。
-ignbrk	输入时不忽略 BREAK。
igncr	输入时忽略 CR。
-igncr	输入时不忽略 CR。
ignpar	忽略奇偶错误。
-ignpar	不忽略奇偶错误。
inlcr	输入时将 NL 映射为 CR。
-inlcr	输入时不将 NL 映射为 CR。
inpck	启用奇偶校验。
-inpck	禁用奇偶校验。
istrip	将输入字符剥离到 7 位。
-istrip	不将输入字符剥离到 7 位。
iuclc	将大写字母字符映射为小写。
-iuclc	不将大写字母字符映射为小写。
ixany	允许任何字符重新启动输出。
-ixany	只允许 START（Ctrl-Q 按键顺序）重新启动输出。
ixoff	当输入队列接近空或满时，发送 START/STOP 字符。
-ixoff	不发送 START/STOP 字符。
ixon	启用 START/STOP 输出控制。一旦启用 START/STOP 输出控制，您可以按下 Ctrl-S 按键顺序暂停向工作站的输出，也可按下 Ctrl-Q 按键顺序恢复输出。
-ixon	禁用 START/STOP 输出控制。
imaxbel	当输入溢出时，回送 BEL 字符并且废弃最后的输入字符。
-imaxbel	当输入溢出时，废弃所有输入。
parmrk	标记奇偶错误。
-parmrk	不标记奇偶错误。
 
输出方式
bs0, bs1	为退格符选择延迟样式（bs0 表示没有延迟）。
cr0, cr1, cr2, cr3	为 CR 字符选择延迟样式（cr0 表示没有延迟）。
ff0, ff1	为换页选择延迟样式（ff0 表示没有延迟）。
nl0, nl1	为 NL 字符选择延迟样式（nl0 表示没有延迟）。
ofill	使用延迟填充字符。
-ofill	使用延迟定时。
ocrnl	将 CR 字符映射为 NL 字符。
-ocrnl	不将 CR 字符映射为 NL 字符。
olcuc	输出时将小写字母字符映射为大写。
-olcuc	输出时不将小写字母字符映射为大写。
onlcr	将 NL 字符映射为 CR-NL 字符。
-onlcr	不将 NL 字符映射为 CR-NL 字符。
onlret	在终端 NL 执行 CR 功能。
-onlret	在终端 NL 不执行 CR 功能。
onocr	不在零列输出 CR 字符。
-onocr	在零列输出 CR 字符。
opost	处理输出。
-opost	不处理输出；即忽略所有其它输出选项。
ofdel	使用 DEL 字符作为填充字符。
-ofdel	使用 NUL 字符作为填充字符。
tab0, tab1, tab2	为水平制表符选择延迟样式（tab0 表示没有延迟）。
tab3	扩展制表符至多个空格。
vt0, vt1	为垂直制表符选择延迟样式（vt0 表示没有延迟）。
 
本地模式
echo	回送每个输入的字符。
-echo	不回送字符。
echoctl	以 ^X（Ctrl-X）回送控制字符，X 是将 100 八进制加到控制字符代码中给出的字符。
-echoctl	不以 ^X（Ctrl-X）回送控制字符。
echoe	以“backspace space backspace”字符串回送 ERASE 字符。
注:
该模式不保持对列位置的跟踪，因此您可能在擦除制表符和转义序列等符号时得到意外的结果。
-echoe	不回送 ERASE 字符，只回送退格符。
echok	在 KILL 字符后回送 NL 字符。
-echok	在 KILL 字符后不回送 NL 字符。
echoke	通过擦除输出行上的每个字符，回送 KILL 字符。
-echoke	只回送 KILL 字符。
echonl	回送 NL 字符。
-echonl	不回送 NL 字符。
echoprt	以 /（斜杠）和 \ (反斜杠) 向后回送擦除的字符。
-echoprt	不以 /（斜杠）和 \ (反斜杠) 向后回送擦除的字符。
icanon	启用规范输入（规范输入允许使用 ERASE 和 KILL 字符进行输入行的编辑）。请参阅 AIX 5L Version 5.2 Communications Programming Concepts 中的 Line Discipline Module (ldterm) 中关于canonical mode input 的讨论。
-icanon	禁用规范输入。
iexten	指定从输入数据中识别实现性定义的功能。要识别以下控制字符，需要设置 iexten：eol2、dsusp、reprint、discard、werase、lnext。与这些模式关联的功能也需要设置iexten：imaxbel、echoke、echoprt、echoctl。
-iexten	指定从输入数据中识别实现性定义的功能。
isig	启用对特殊控制字符（INTR、SUSP 和 QUIT）的字符检查。
-isig	禁用对特殊控制字符（INTR、SUSP 和 QUIT）的字符检查。
noflsh	不清除 INTR、SUSP 或 QUIT 控制字符之后的缓冲区。
-noflsh	清除 INTR、SUSP 或 QUIT 控制字符之后的缓冲区。
pending	下次读操作暂挂或输入到达时，要重新输入从原始模式转换为规范模式后被暂挂的输入。暂挂是一个内部状态位。
-pending	没有文本暂挂。
tostop	为背景输出发出 SIGTOU 信号。
-tostop	不为背景输出发出 SIGTOU 信号。
xcase	在输入中回送大写字符，并在输出显示的大写字符之前加上 \ (反斜杠)。
-xcase	不在输入时回送大写字符。
硬件流量控制模式
这些选项是对 《X/Open 可移植性指南，发行版 4》 标准的扩展。
cdxon	输出时启用 CD 硬件流量控制模式。
-cdxon	输出时禁用 CD 硬件流量控制模式。
ctsxon	输出时启用 CTS 硬件流量控制模式。
-ctsxon	输出时禁用 CTS 硬件流量控制模式。
dtrxoff	输入时启用 DTR 硬件流量控制模式。
-dtrxoff	输入时禁用 DTR 硬件流量控制模式。
rtsxoff	输入时启用 RTS 硬件流量控制模式。
-rtsxoff	输入时禁用 RTS 硬件流量控制模式。
控制指定
要将一个控制字符指定到某字符串中，请输入：
	stty Control String
	
其中，Control 参数可以是 INTR、QUIT、ERASE、KILL、EOF、EOL、EOL2、START、STOP、SUSP、DSUSP、
REPRINT、DISCARD、WERASE、LNEXT、MIN 或 TIME 参数。（使用字符 MIN 和 TIME 时，请加上 -icanon 选项。）
注:
MIN 和 TIME 的值解释为整数值，而不是字符值。
String 参数可以是任何单一的字符，比如 c。以下内容为控制赋值的示例：
	stty STOP c
另一种指定控制字符的方法可以是：输入一个字符序列，它是由一个  \^ (反斜杠，插入记号) 后面跟着一个单一字符组成的。如果跟在 ^ （插入记号）后的单一字符是下表的^c（插入记号 c）栏中列出的字符之一，将设置相应的控制字符值。例如，要使用 ?（问号）字符指定 DEL 控制字符，请输入字符串\^?（反斜杠，插入记号，问号），如下：
	stty ERASE \^?
stty 中的插入记号控制字符
^c	    替换值  ^c   	 替换值	^c	  替换值
a, A	<SOH>	l, L	<FF>	w, W	<ETB>
b, B	<STX>	m, M	<CR>	x, X	<CAN>
c, C	<ETX>	n, N	<SO>	y, Y	<EM>
d, D	<EOT>	o, O	<SI>	z, Z	<SUB>
e, E	<ENQ>	p, P	<DLE>	[		<ESC>
f, F	<ACK>	q, Q	<DC1>	\		<FS>
g, G	<BEL>	r, R	<DC2>	]		<GS>
h, H	<BS>	s, S	<DC3>	^		<RS>
i, I	<HT>	t, T	<DC4>	_		<US>
j, J	<LF>	u, U	<NAK>	?		<DEL>
k, K	<VT>	v, V	<SYN>	@		<NUL>

组合模式	 
cooked	请参阅 -raw 选项。
ek	分别将 ERASE 和 KILL 字符设置为 Ctrl-H 和 Ctrl-U 按键顺序。
evenp	启用 parenb 和 cs7。
-evenp	禁用 parenb 并设置 cs8。
lcase,LCASE	设置 xcase，iuclc 和olcuc。在工作站只以大写字符使用。
-lcase,-LCASE	设置 -xcase、-iuclc 和-olcuc。
nl	设置 -icrnl 和-onlcr。
-nl	设置 icrnl、 onlcr、-inlcr、-igncr、-ocrnl和-onlret。
oddp	启用 parenb、 cs7 和 parodd。
-oddp	禁用 parenb 并设置 cs8。
parity	请参阅 evenp 选项。
-parity	请参阅 -evenp 选项。
sane	将参数重新设置为合理的值。
raw	允许原始模式输入（不包括输入处理，例如 erase、kill 或 interrupt）；传回奇偶（校验）位。
-raw	允许规范输入方式。
tabs	保留制表符。
-tabs,tab3	打印时将制表符替换为空格。
窗口大小	 
cols n,columns n	将终端（窗口）大小记录为有 n 列。
rows n	将终端（窗口）大小记录为有 n 行。
size	将终端（窗口）大小打印到标准输出（先是行，再是列）中。
```

####8、示例

```shell
115200波特率 8数据位 1停止位 无校验位
stty -F /dev/ttyS0 speed 115200  cs8 -parenb -cstopb
```

####9、获取串口号

```
在Linux系统中一切皆为文件，所以串口端口号也不例外，都是以设备文件的形式出现。也就是说我们可以用访问文本文件的命令来访问它们。

a. 一般串口都是以/dev/ttyS#的格式显示，所以第一个连接的串口就是/dev/ttyS0,第二个连接的串口就是/dev/ttyS1…以此类推。

b. USB转串口适配，没有额外驱动，它们会显示为/dev/ttyUSB#,如/dev/ttyUSB0
```

####10、配置串口属性

```
我们可以使用stty命令来更改配置串口属性(详情查看”man sty”)，比如我们设置串口/dev/ttyS0波特率为57600和odd parity，命令如下:
	stty -F /dev/ttyS0 57600 parodd
```

#### 11、串口数据读写操作

```
使用echo向串口发送数据，如:
	echo "command" > /dev/ttyUSB0
	
可以使用cat来读取串口中的数据，如
	cat /dev/ttyUSB0
	
读取数据并保存到txt文本文件中，如
	cat /dev/ttyUSB0 > file.txt
```

#### 12、解析数据

```
说到解析数据，我们可以使用一个强大的文本分析工具awk，相对于grep的查找，sed的编辑，awk在其对数据分析并生成报告时，显得尤为强大。简单来说awk就是把文件逐行的读入，以空格为默认分隔符将每行切片，切开的部分再进行各种分析处理。

awk有3个不同版本: awk、nawk和gawk，未作特别说明，一般指gawk，gawk 是 AWK 的 GNU 版本。

详细说明请参考http://www.gnu.org/software/gawk/manual/gawk.pdf

下面使用gawk举个栗子，在终端以H:M:S格式输出当前时间和来自串口的每一行前3个字符，命令如下：
	cat /dev/ttyUSB0 | gawk ’{print strftime("%T"), substr($1 ,1,3)}’
```

#### 13、后台运行

```
可以讲串口数据读写操作设置为后台进行，通过一个简单命令或者shell 脚本就可以实现。命令可以用nohup。即使关闭终端或者注销账户，进程还是在进行着，比如:
	nohup cat /dev/ttyS0 | gawk ’{substr($1 ,1,3)}’ > result.txt

使用下面命令可以删除进程，但是会删除所有的cat进程。
	killall cat
我们可以用“ps ax”来查看当前运行的进程，选择你要删除的，记下PID,删除即可，如下
	kill -9 PID
```

## 9、linux 串口抓包工具 ckermit 的安装使用

> #### 1、[下载到源码包](./2018-01/cku302.tar.Z)
>
> #### 2、解压安装
>
> ```shell
> mkdir cku
> cd ./cku
> tar -xf cku302.tar.Z
> make linux
> make install
> ```
>
> #### 官网的安装说明
>
> ```shell
> Unix Build Instructions
>
> [ Top ] [ Unix Hints & Tips ] [ Unix Installation Instructions ]
> Make a fresh directory and 'cd' to it. Example:
>   $ mkdir kermit
>   $ cd kermit
> Download the appropriate source code archive.
> If you downloaded a compressed tar file, uncompress it. Examples:
>   $ gunzip cku302.tar.gz
>   $ uncompress cku302.tar.Z
> If you downloaded a tar archive, "un-tar" it. Example:
>   $ tar xvf cku302.tar
> If you downloaded a Zip archive, unzip it. Example:
>
>   $ unzip -a cku302.zip
> Now you can delete the tar archive (or zip archive) if you wish:
>   $ rm cku302.tar                 (or rm cku302.zip)
> Read the comments at the top of the makefile to find out which target is appropriate for your computer and operating system, and then give the appropriate "make" command. Examples:
>   $ make linux                    (Linux, almost any version)
>   $ make macosx                   (Mac OS X 10.3.x or later)
>   $ make freebsd                  (FreeBSD, any version)
>
> Quick install: move the resulting 'wermit' binary to /usr/local/bin/kermit and give it the same owner, group, and permissions as minicom or cu. Move the ckuker.nr to the appropriate man page directory and rename it as appropriate, e.g. to kermit.1. For more detailed instructions, read the C-Kermit installation instructions, especially if you had trouble with any of these steps, or if you will be using C-Kermit to dial out. The most convenient way to install is to the use makefile's install target ("make install"); read about it HERE. See the configuration options guide for information about compile-time options for customizing the feature set.
> ```
>
> 
>
> #### 3、配置官网
>
> ```
> http://www.kermitproject.org/ckccfg.html#x4
> ```
>
> #### 4、使用
>
> ```shell
> # 设置配置文件 c-kermit启动时会从当前用户下查找.kermrc配置文件,所以我们先写好一个配置文件,全名为 ~/.kermrc,内容为:
>
> set line /dev/ttyUSB0  #如果使用电脑本身的串口,这里可能是ttyS0之类的 
> set speed 115200 
> set carrier-watch off 
> set handshake none 
> set flow-control none 
> robust 
> set file type bin 
> set file name mini2440.bin 
> set rec pack 1000 
> set send pack 1000 
> set window 5 
> c
>
> #.使用 kermit –c 来连接串口,如果出现乱码,请关闭终端多试几次,总会成功的-:)
> ```



## 10、串口抓包工具`jpnevulator`

### A、官网

```
https://jpnevulator.snarl.nl
```

### B、[源码包](./2018-01/jpnevulator-2.3.4.tgz)

### C、安装

```shell
tar -xf jpnevulator-2.3.4.tgz
make && make install
```

### D、用法

#### 1）、支持同时打开多串口抓包

```shell
$ jpnevulator --ascii --timing-print --tty /dev/ttyS0:SB9600d --tty "/dev/ttyUSB0:Motorola MTM800" --read
2006-05-30 13:23:49.461075: SB9600d
00 00 05 3B 0D 00 00 05                         ...;....
2006-05-30 13:23:49.461113: Motorola MTM800
00 05 3B 0D 00 00 05 3B 0D                      ..;....;.
2006-05-30 13:23:49.473074: SB9600d
3B 0D 00 00 05 3B 0D                            ;....;.
2006-05-30 13:23:49.473105: Motorola MTM800
00 12 05 06 39 00 12 05 06 39 1F 00 22 80 00 0E ....9....9.."...
$ 
```

### 2）、实战

```shell
A pc发送：
# jpnevulator --ascii --tty /dev/ttyS0:SB57600d --write
01 02 03 04 05 06 07 08 09 0A 0B  回车  #发送有一个 bug，就是0d 会被当成0a接收

# 发送方可以把 --ascii 去掉，就变成了发送十六进制数

B pc 接收：
# jpnevulator --ascii --timing-print --tty /dev/ttyS0:SB57600d --read
01 02 03 04 05 06 07 08 09 0A 0B     .....................................

#接收方也可以把 --ascii 去掉，不显示ascii 内容
```

