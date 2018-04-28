#<center>powershell</center>

[TOC]

##一、貌似官网，不少例子，当一一尝试之

http://www.pstips.net/powershell-online-tutorials/

##二、开始尝试

### 1、管道和重定向

```powershell
启动之
C:\Users\15900>powershell
Windows PowerShell
版权所有 (C) Microsoft Corporation。保留所有权利。

无法加载 PSReadline 模块。控制台在未使用 PSReadline 的情况下运行。
PS C:\Users\15900>

 ls 默认查看当前目录内容，是按 name 升序排列的
PS C:\Users\15900> ls
    目录: C:\Users\15900
Mode                LastWriteTime         Length Name
----                -------------         ------ ----
d-----        2018/2/24      8:10                .ssh
d-----        2018/2/26      8:17                .VirtualBox
d-r---        2018/2/26      7:17                3D Objects
d-r---        2018/2/26      7:17                Contacts
d-r---        2018/2/26      7:33                Desktop
d-r---        2018/2/26      7:17                Documents
d-r---        2018/2/26      7:58                Downloads
d-r---        2018/2/26      7:17                Favorites
d-r---        2018/2/26      7:17                Links
d-r---        2018/2/26      7:17                Music
d-r---         2018/3/2      8:08                OneDrive
d-r---        2018/2/26      7:17                Pictures
d-----        2018/1/27      1:47                Roaming
d-r---        2018/2/26      7:17                Saved Games
d-r---        2018/2/26      7:17                Searches
d-r---        2018/2/27      8:08                Videos
d-----        2018/2/10     17:07                VirtualBox VMs
-a----        2018/2/26      8:15           2287 .bash_history
-a----        2018/2/25     10:29             28 .minttyrc
-a----        2018/2/26      7:41          15307 .viminfo
-a----        2018/2/10     21:09            806 _viminfo

PS C:\Users\15900>


使用管道，实现降序排列：
PS C:\Users\15900> ls | sort -Descending
    目录: C:\Users\15900
Mode                LastWriteTime         Length Name
----                -------------         ------ ----
d-----        2018/2/10     17:07                VirtualBox VMs
d-r---        2018/2/27      8:08                Videos
d-r---        2018/2/26      7:17                Searches
d-r---        2018/2/26      7:17                Saved Games
d-----        2018/1/27      1:47                Roaming
d-r---        2018/2/26      7:17                Pictures
d-r---         2018/3/2      8:08                OneDrive
d-r---        2018/2/26      7:17                Music
d-r---        2018/2/26      7:17                Links
d-r---        2018/2/26      7:17                Favorites
d-r---        2018/2/26      7:58                Downloads
d-r---        2018/2/26      7:17                Documents
d-r---        2018/2/26      7:33                Desktop
d-r---        2018/2/26      7:17                Contacts
d-r---        2018/2/26      7:17                3D Objects
-a----        2018/2/10     21:09            806 _viminfo
d-----        2018/2/26      8:17                .VirtualBox
-a----        2018/2/26      7:41          15307 .viminfo
d-----        2018/2/24      8:10                .ssh
-a----        2018/2/25     10:29             28 .minttyrc
-a----        2018/2/26      8:15           2287 .bash_history

利用管道过滤想要的内容：
PS C:\Users\15900> ls | sort -Descending Name | Format-Table Name,Mode
Name           Mode
----           ----
VirtualBox VMs d-----
Videos         d-r---
Searches       d-r---
Saved Games    d-r---
Roaming        d-----
Pictures       d-r---
OneDrive       d-r---
Music          d-r---
Links          d-r---
Favorites      d-r---
Downloads      d-r---
Documents      d-r---
Desktop        d-r---
Contacts       d-r---
3D Objects     d-r---
_viminfo       -a----
.VirtualBox    d-----
.viminfo       -a----
.ssh           d-----
.minttyrc      -a----
.bash_history  -a----
PS C:\Users\15900>

重定向到文件中
PS C:\Users\15900> ls | sort -Descending Name | Format-Table Name,Mode >a.txt
```

### 2、数学运算

```powershell
一、基础运算
PS C:\Users\15900> 1+2+3
6
PS C:\Users\15900> 0xABCD
43981
PS C:\Users\15900> 3.14*10*10
314
PS C:\Users\15900>  1+3-(2.4-5)*(7.899-4.444)
12.983
PS C:\Users\15900>

二、自动识别 KB，MB，GB，TB，PB
PS C:\Users\15900> 1pb/1tb
1024
PS C:\Users\15900> 1tb/1gb
1024
PS C:\Users\15900> 1gb/1kb
1048576
PS C:\Users\15900> 1gb/20mb*10kb
524288
PS C:\Users\15900> 1kb
1024
PS C:\Users\15900>

假如一个网站每个页面大小为80kb，统计显示每天的PV操作为800，1个月下来占用的带宽：
PS C:\pstest> 80kb*800*30/1gb
1.8310546875
```

### 3、执行外部命令，向 CMD 一样

```powershell
一、查看网络连接
	PS C:\Users\15900> netstat
	活动连接
	  协议  本地地址          外部地址        状态
	  TCP    192.168.43.230:52743   52.230.3.194:https     ESTABLISHED
	  TCP    192.168.43.230:52914   52.230.83.250:https    ESTABLISHED

二、通过IPConfig查看自己的网络配置
	PS C:\Users\15900> ipconfig
	Windows IP 配置
	以太网适配器 VirtualBox Host-Only Network:
	
	   连接特定的 DNS 后缀 . . . . . . . :
	   本地链接 IPv6 地址. . . . . . . . : fe80::80a2:c273:3fbf:9600%10
	   IPv4 地址 . . . . . . . . . . . . : 192.168.56.1
	   子网掩码  . . . . . . . . . . . . : 255.255.255.0
	   默认网关. . . . . . . . . . . . . :

三、route print 查看路由信息
	PS C:\Users\15900> route print
	===========================================================================
	接口列表
	 10...0a 00 27 00 00 0a ......VirtualBox Host-Only Ethernet Adapter
	 11...40 a3 cc b6 92 26 ......Microsoft Wi-Fi Direct Virtual Adapter
	  4...40 a3 cc b6 92 25 ......Intel(R) Dual Band Wireless-AC 8265
	  2...40 a3 cc b6 92 29 ......Bluetooth Device (Personal Area Network)
	  1...........................Software Loopback Interface 1
	  8...00 00 00 00 00 00 00 e0 Microsoft Teredo Tunneling Adapter
	===========================================================================
	
	IPv4 路由表
	===========================================================================
	活动路由:
	网络目标        网络掩码          网关       接口   跃点数
	          0.0.0.0          0.0.0.0     192.168.43.1   192.168.43.230     55
	        127.0.0.0        255.0.0.0            在链路上         127.0.0.1    331
	        127.0.0.1  255.255.255.255            在链路上         127.0.0.1    331
	  127.255.255.255  255.255.255.255            在链路上         127.0.0.1    331
	     192.168.43.0    255.255.255.0            在链路上    192.168.43.230    311
	   192.168.43.230  255.255.255.255            在链路上    192.168.43.230    311
	   192.168.43.255  255.255.255.255            在链路上    192.168.43.230    311
	     192.168.56.0    255.255.255.0            在链路上      192.168.56.1    281
	     192.168.56.1  255.255.255.255            在链路上      192.168.56.1    281
	   192.168.56.255  255.255.255.255            在链路上      192.168.56.1    281
	        224.0.0.0        240.0.0.0            在链路上         127.0.0.1    331
	        224.0.0.0        240.0.0.0            在链路上      192.168.56.1    281
	        224.0.0.0        240.0.0.0            在链路上    192.168.43.230    311
	  255.255.255.255  255.255.255.255            在链路上         127.0.0.1    331
	  255.255.255.255  255.255.255.255            在链路上      192.168.56.1    281
	  255.255.255.255  255.255.255.255            在链路上    192.168.43.230    311
	===========================================================================
	永久路由:
	  无
	
	IPv6 路由表
	===========================================================================
	活动路由:
	 接口跃点数网络目标                网关
	  1    331 ::1/128                  在链路上
	 10    281 fe80::/64                在链路上
	  4    311 fe80::/64                在链路上
	 10    281 fe80::80a2:c273:3fbf:9600/128
	                                    在链路上
	  4    311 fe80::a404:9ab2:5347:b040/128
	                                    在链路上
	  1    331 ff00::/8                 在链路上
	 10    281 ff00::/8                 在链路上
	  4    311 ff00::/8                 在链路上
	===========================================================================
	永久路由:
	  无
	PS C:\Users\15900>
	
四、查找可用的Cmd控制台命令
	Cmd.exe 通过 /c 来接收命令参数，在Cmd中help可以查看可用的命令，所以可以通过Cmd /c help 查找可用的Cmd控制台命令
	PS C:\Users\15900> cmd /c help
		有关某个命令的详细信息，请键入 HELP 命令名
		ASSOC          显示或修改文件扩展名关联。
		ATTRIB         显示或更改文件属性。
		BREAK          设置或清除扩展式 CTRL+C 检查。
		BCDEDIT        设置启动数据库中的属性以控制启动加载。
		CACLS          显示或修改文件的访问控制列表(ACL)。
		....
```

### 4、命令集









