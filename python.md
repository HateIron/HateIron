#<center>python</center>

[TOC]

## 一、python 发邮件

## 二、python jenkins 模块

```
一个人的 blog
	https://www.cnblogs.com/znicy/p/5498609.html
python jenkins 官网：
	https://pypi.pytho.org/pypi/python-jenkins/ 无法打开
```

## 三、python 多进程

## 四、python 日志模块

## 五、python serial 串口 模块

## 六、python re 正则表达式模块

```python
$ python
iPython 2.7.14 (default, Oct 31 2017, 21:12:13)
[GCC 6.4.0] on cygwin
Type "help", "copyright", "credits" or "license" for more information.
>>> import re
>>> line = "there were 27 failures of 100"
>>> print line
there were 27 failures of 100
>>> print re.match(r"there were ([0-9]+) failures of ([0-9]+)", line, re.M|re.I).group(1)
27
>>> print re.match(r"there were ([0-9]+) failures of ([0-9]+)", line, re.M|re.I).group(2)
100
>>> print re.match(r"there were ([0-9]+) failures of ([0-9]+)", line, re.M|re.I).group(0)
there were 27 failures of 100
>>>
```

## 七、python shutil 模块

```
http://www.cnblogs.com/BigFishFly/p/6337058.html
```



##八、时间模块

### 1、获取当前时间

```python
import time
currTime = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
print currTime #2018-02-14 09:07:15
```



##九、python 图片文字识别提取

###1、版本要求：python3，我安装了3.6.2

### 2、依赖的模块

```
#PIL 安装失败
C:\Programs\Python\Python36>Scripts\pip install PIL
Collecting PIL
  Could not find a version that satisfies the requirement PIL (from versions: )
No matching distribution found for PIL

# 转而安装 pillow
C:\Programs\Python\Python36>Scripts\pip install pillow
Collecting pillow
  Downloading Pillow-5.0.0-cp36-cp36m-win_amd64.whl (1.6MB)
    100% |████████████████████████████████| 1.6MB 340kB/s
Installing collected packages: pillow
Successfully installed pillow-5.0.0

# 或者下载好 .whl 后再安装：
	pip install some-package.whl
```

```shell
C:\Programs\Python\Python36>Scripts\pip3.6.exe install pytesseract
Collecting pytesseract
  Downloading pytesseract-0.2.0.tar.gz (154kB)
    100% |████████████████████████████████| 163kB 40kB/s
Requirement already satisfied: Pillow in c:\programs\python\python36\lib\site-packages (from pytesseract)
Installing collected packages: pytesseract
  Running setup.py install for pytesseract ... done
Successfully installed pytesseract-0.2.0
```



### 3、linux 下使用 `easy_install`安装 pip

```shell
[root@localhost python]# easy_install pip
[root@localhost python]# whereis pip
pip: /usr/bin/pip /usr/bin/pip2.7
[root@localhost python]#

# 然后，在 linux 上再运行命令
[root@localhost python]# pip install pillow
Collecting pillow

  Downloading Pillow-5.0.0-cp27-cp27mu-manylinux1_x86_64.whl (5.8MB)
    100% |████████████████████████████████| 5.9MB 88kB/s
Installing collected packages: pillow
Successfully installed pillow-5.0.0

[root@localhost python]# pip install pillow
Requirement already satisfied: pillow in /usr/lib64/python2.7/site-packages
[root@localhost python]#
```



## 十、python 获取本机IP/MAC

###1、在 linux 环境上运行 getMac.py

```python
[wishcell@localhost python]$
[wishcell@localhost python]$ cat getMac.py

import uuid
def get_mac_address():
    mac=uuid.UUID(int = uuid.getnode()).hex[-12:]
    return ":".join([mac[e:e+2] for e in range(0,11,2)])
print get_mac_address()
[wishcell@localhost python]$ python getMac.py
08:00:27:d0:02:13
[wishcell@localhost python]$
```

### 2、在 windows Cygwin 环境运行相同代码，效果完全一致

```python
$ cat getMac.py

import uuid
def get_mac_address():
    mac=uuid.UUID(int = uuid.getnode()).hex[-12:]
    return ":".join([mac[e:e+2] for e in range(0,11,2)])
print get_mac_address()

15900@DESKTOP-CGPRCF3 /cygdrive/e/study
$ python getMac.py
0a:00:27:00:00:06
```



### 3、 linux 下专用代码，获取指定网卡的IP地址

```python
import socket
import fcntl
import struct

def get_ip_address(ifname):
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    return socket.inet_ntoa(fcntl.ioctl(
        s.fileno(),
        0x8915,  # SIOCGIFADDR
        struct.pack('256s', ifname[:15])
    )[20:24])

card_name = "enp0s3"
print "\n\ncardname(%8s) address:%s"%(card_name, get_ip_address(card_name))
card_name = "lo"
print "cardname(%8s) address:%s"%(card_name, get_ip_address(card_name))
card_name = "virbr0"
print "cardname(%8s) address:%s\n\n"%(card_name, get_ip_address(card_name))

# 运行效果：
[root@localhost python]# python getIP_by_card_name.py

cardname(  enp0s3) address:192.168.43.222
cardname(      lo) address:127.0.0.1
cardname(  virbr0) address:192.168.122.1
```



