# <center>miniftpd</center>

[TOC]

# 一、资源来源

```
https://blog.csdn.net/nk_test/article/details/50575386
```

# 二、源码

## I、文件列表

```powershell
[wishcell@localhost Tachftp]$ ll
total 132
-rw-rw-r--. 1 wishcell wishcell   847 Jun 19 20:48 common.h
-rw-rw-r--. 1 wishcell wishcell  2534 Jun 19 20:48 ftpcodes.h
-rw-rw-r--. 1 wishcell wishcell 27857 Jun 19 20:48 ftpproto.c
-rw-rw-r--. 1 wishcell wishcell   219 Jun 19 20:48 ftpproto.h
-rw-rw-r--. 1 wishcell wishcell  2597 Jun 19 20:48 hash.c
-rw-rw-r--. 1 wishcell wishcell   461 Jun 19 20:48 hash.h
-rw-rw-r--. 1 wishcell wishcell  6763 Jun 19 20:48 main.c
-rw-rw-r--. 1 wishcell wishcell   278 Jun 19 20:48 Makefile
-rw-rw-r--. 1 wishcell wishcell  3366 Jun 19 20:48 parseconf.c
-rw-rw-r--. 1 wishcell wishcell   170 Jun 19 20:48 parseconf.h
-rw-rw-r--. 1 wishcell wishcell  3524 Jun 19 20:48 privparent.c
-rw-rw-r--. 1 wishcell wishcell   137 Jun 19 20:48 privparent.h
-rw-rw-r--. 1 wishcell wishcell  2835 Jun 19 20:48 privsock.c
-rw-rw-r--. 1 wishcell wishcell  1131 Jun 19 20:48 privsock.h
-rw-rw-r--. 1 wishcell wishcell   733 Jun 19 20:54 README.md
-rw-rw-r--. 1 wishcell wishcell   721 Jun 19 20:48 session.c
-rw-rw-r--. 1 wishcell wishcell   758 Jun 19 20:48 session.h
-rw-rw-r--. 1 wishcell wishcell  1591 Jun 19 20:48 str.c
-rw-rw-r--. 1 wishcell wishcell   310 Jun 19 20:48 str.h
-rw-rw-r--. 1 wishcell wishcell 13763 Jun 19 20:48 sysutil.c
-rw-rw-r--. 1 wishcell wishcell  1256 Jun 19 20:48 sysutil.h
-rw-rw-r--. 1 wishcell wishcell   624 Jun 19 20:48 tunable.c
-rw-rw-r--. 1 wishcell wishcell   622 Jun 19 20:48 tunable.h
```

## II、[源码如下](./miniftpd.zip)

###common.h
<iframe src="./miniftpd/common.h    " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###ftpcodes.h
<iframe src="./miniftpd/ftpcodes.h  " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###ftpproto.c
<iframe src="./miniftpd/ftpproto.c  " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###ftpproto.h
<iframe src="./miniftpd/ftpproto.h  " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###hash.c
<iframe src="./miniftpd/hash.c      " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###hash.h
<iframe src="./miniftpd/hash.h      " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###main.c 
<iframe src="./miniftpd/main.c      " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###Makefile
<iframe src="./miniftpd/Makefile    " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###parseconf.c
<iframe src="./miniftpd/parseconf.c " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###parseconf.h
<iframe src="./miniftpd/parseconf.h " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###privparent.c
<iframe src="./miniftpd/privparent.c" width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###privparent.h
<iframe src="./miniftpd/privparent.h" width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###privsock.c
<iframe src="./miniftpd/privsock.c  " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###privsock.h
<iframe src="./miniftpd/privsock.h  " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###README.md
<iframe src="./miniftpd/README.md   " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###session.c
<iframe src="./miniftpd/session.c   " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###session.h
<iframe src="./miniftpd/session.h   " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###str.c
<iframe src="./miniftpd/str.c       " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###str.h
<iframe src="./miniftpd/str.h       " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###sysutil.c
<iframe src="./miniftpd/sysutil.c   " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###sysutil.h
<iframe src="./miniftpd/sysutil.h   " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###tunable.c
<iframe src="./miniftpd/tunable.c   " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>
###tunable.h
<iframe src="./miniftpd/tunable.h   " width="1000px" height="1000px" boarder="1px" scrolling="yes"></iframe>



