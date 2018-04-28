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

