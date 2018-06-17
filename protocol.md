#<center>协议</center>

[TOC]

##一、485 协议



## 二、 modbus 协议



## 三、单总线协议



## 四、I2C协议



## 五、SPI协议



##六、 tcpip 



##七、SNMP

###1、snmpwalk

```powershell

snmpwalk命令则是测试系统各种信息最有效的方法,常用的方法如下:

1、snmpwalk -c public -v 1 -m ALL 10.0.1.52 .1.3.6.1.2.1.25.1 得到取得windows端的系统进程用户数等
2、snmpwalk -c public -v 1 -m ALL 10.0.1.52 .1.3.6.1.2.1.25.2.2  取得系统总内存
3、snmpwalk -c public -v 1 -m ALL 10.0.1.52 hrSystemNumUsers       取得系统用户数
4、snmpwalk -c public -v 1 -m ALL 10.0.1.52 .1.3.6.1.2.1.4.20   取得IP信息
5、snmpwalk -v 2c -c public 10.0.1.52 system  查看系统信息
6、snmpwalk -v 1 10.0.1.52 -c public ifDescr  获取网卡信息

1、snmpwalk -v 2c -c public 10.0.1.52 .1.3.6.1.2.1.25.1   得到取得windows端的系统进程用户数等

其中-v是指版本,-c 是指密钥。

snmpwalk功能很多,可以获取系统各种信息,只要更改后面的信息类型即可。如果不知道什么类型,也可以不指定,这样所有系统信息都获取到:

snmpwalk -v 2c -c public 10.0.1.52
```

### 2、snmpget / snmpgetnext

```powershell
可以将 snmpwalk 替换成 snmpget / snmpgetnext 同样可以正常工作
```



##八、`ppp`协议

|      | 7E   | FF                         | 03                       | 协议                                                         | 信息   | FCS  | 7E   |
| ---- | ---- | -------------------------- | ------------------------ | ------------------------------------------------------------ | ------ | ---- | ---- |
| 字节 | 1    | 1 (地址域，固定值，取0xff) | 1 (控制域，固定值取0x03) | 2 (0x0021表示IP分组，0x8021表示网络控制数据，0xC021表示链路控制数据，) | <=1500 | 2    | 1    |

```powershell
    PPP采用0x7E作为一帧的开始和结束标志（F）；其中地址域（A）和控制域（C）取固定值（A=FFH，C=03H） ；协议域（两个字节）取0021H表示IP分组，取8021H表示网络控制数据，取C021H表示链路控制数据；帧校验域（FCS）也为两个字节，它用于对信息域的校验。若信息域中出现7EH，则转换为（7DH，5EH）两个字符。当信息域出现7DH时，则转换为（7DH，5DH）。当信息流中出现ASCII码的控制字符（即小于20H），即在该字符前加入一个7DH字符。
```

### 1、编码

[出处](https://blog.csdn.net/wangxg_7520/article/details/2488491)，编/解码代码未经验证，慎用

```c
#define PPP_FRAME_FLAG  0x7e /* 标志字符 */
#define PPP_FRAME_ESC   0x7d /* 转义字符 */
#define PPP_FRAME_ENC   0x20 /* 编码字符 */
#define BUF_LEN 1500

/* return: bytes encoded */
int pppEncode(unsigned char * buf, int len) {
	unsigned char * pi, * po;
	int i, olen;
	unsigned char obuf[BUF_LEN];
	
	if(len > (BUF_LEN>>1)) {
		return -1;
	}
	
	memset(obuf, 0, BUF_LEN);
	pi = buf;
	po = obuf;
	olen = len;
	
	for(i=0; i<len; i++) {
	
		/* byte needs encode, encode it */
		if(*pi == PPP_FRAME_FLAG
			|| *pi == PPP_FRAME_ESC
			|| *pi < 0x20) 
		{
			*po = PPP_FRAME_ESC;
			po++;
			olen++;
			
			/* xor the 6th bit */
			*po = *pi ^ PPP_FRAME_ENC;
		}
		else {
			*po = *pi;
		}
		pi++;
		po++;
	}
	
	memcpy(buf, obuf, olen);
	
	return olen;
}
```

### 2、解码

```c
/* return: bytes decoded */

int pppDecode(unsigned char * buf, int len) {
	unsigned char * pi, *po;
	int i, olen;
	unsigned char obuf[BUF_LEN];
	
	if(len > BUF_LEN) {
		return -1;
	}
	
	memset(obuf, 0, BUF_LEN);
	pi = buf;
	po = obuf;
	olen = len;
	
	for(i=0; i<len; i++)
	{
		if(*pi == PPP_FRAME_ESC)
		{
			/* skip the escape byte */
			pi++;
			olen--;
			
			/* xor the 6th bit */
			*po = *pi ^ PPP_FRAME_ENC;
		}
		else
		{
			*po = *pi;
		}
		pi++;
		po++;
	}
	
	memcpy(buf, obuf, olen);
	
	return olen;
}
```





