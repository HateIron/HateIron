#<center>python</center>

[TOC]

## 0、python 安装

```shell
[root@localhost wishcell]# yum install python
```



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

##十一、python 一键生成目录框架

```python
# --*-- coding: utf-8 --*--
import os,sys

html = ('<!DOCTYPE html>\n' 
        '\n' 
        '<html>\n'
        '{navigation}\n'
        '</html>\n')

details_header = (
        '<details class="menu" close>\n'
		'<summary>{content}</summary>\n'
		'<ul>\n'
		'\n')

details_footer = (
        '<ul>\n'
		'</details>\n')
		
li =  '<li><a href="{link}" target="showframe"> {content} </a></li>\n'
        		
print(html)
print(details_header)
print(details_footer)
print(li)

def file_scan(path):
    content = ''
    files   = os.listdir(path)
    for file in files:
        file_path = os.path.join(path, file)
        if os.path.isdir(file_path):
            content += str(details_header).format(content=file)
            content += file_scan(file_path)
            content += str(details_footer)
        else:
             content += str(li).format(link=file_path,content=file)       
    print ('-------------------------------------------')
    print (path)
    print (content)
    return content    
    
#if __name__='__main__':
content = str(details_header).format(content='root')    
content+= file_scan('root')
content+= str(details_footer)
text    = str(html).format(navigation = content)
with open('navigation.html', 'w') as f:
    f.writelines(text)    
```



## 十二、python 数据模块

### 1、python 数字 log10 方法，返回 x(x>0)基数为10的对数

```python
import math
math.log10(x)
```

## 十三、python 二进制、整数相互转化模块

### 1、整数转二进制

```python
如 bin(10)果返回字符中 '0b1010'
只留下 0、1，将 '0b'去除：
	bin(number).replace('0b','')
或者：
    bin(number)[2:]
    
>>>bin(10)
'0b1010'
```

### 2、二进制转整数

```python
>>>int(t[2:],2)
10
```

### 3、使用 struct 模块处理二进制(pack 和 unpack 用法)

```powershell
在 十四 的例子中
```



##十四、python 图形显示

```python
import numpy as np
import matplotlib.pylot as plt
import os,xdrlib,sys,shutil
import struct,socket,math

file_name = argv[1]
print "file_name is " + file_name

# shutil.copy("src","dest")

num         = 0
keyword_pos = 84

f = open(file_name,'rb')
# 从文件头开始定位游标位置
f.seek(keyword_pos, 0)

#读取关键字，但是此时的关键字是以二进制方式存储在文件中的，但是对于 python 来说，只有字符串
len_bin = f.read(4)
# 1、struct.unpack 返回的是一个结构体，所以num 后面的','不能缺少
# 2、unpack 中的 ‘I’ 表示解析成无符号整数，'i'表示有符号整数
# 3、unpack 中的第一个参数为"FMT"格式化字符吕，也可以为'5s6s3I'这样子，从后面的字符串中解析相应内容
num,=struct.unpack('I',len_bin)

# 由于文件中的数字与本机存在大小端口问题，需要转换
num = socket.ntohl(num)

x_arr = range(0, num)
y_arr = range(0, num)

# 这里的 i 的范围必须是 range(1,num-1),否则越界。
# 因为 range(i,j)返回的数组是 [i,i+1,i+2,....(num-1)-1]
for i in range(0, num-1)
    # 从文件中继续提取数据，以4字节为单位
    data_bin = f.read(4)s
    data,    = struct.unapck('I', data_bin)
    y_arr[i] = socket.ntohl(data)

# 对橫坐标数据进行单位转化
for i in range(0, num-1)
    x_arr[i] = i*3.1415926;

# 将显示画布划分成 2行 1列，当前选中的为第一行，进行相应设置
plt.subplot(211)

# 在第一个画布内，设置两个曲线数据，并指定不同颜色
# plt.plot(x_arr, y_arr, 'b-', x_arr2, y_arr2, 'g-')

#在第一个画布中指定一条数据曲线，并指定颜色
plt.plot(x_arr, y_arr, 'b-')

#指定横坐标范围
plt.xlim(0, x_arr[i])

#指定横轴代表的意义，加上一行字符串
plt.xlabel('distance')

# 指定纵轴的意义，加上一行字符串
plt.ylabel('height')

# 显示网格
plt.grid(True)

# 将显示画布划分成 2行 1列，当前选中的为第 2 行，进行相应设置
plt.subplot(212)
# 其它设置都与 第一行相似

#最后显示曲线
plt.show()
```

## 十五、十六进制打印数字

```python
# 一、十六进制打印数字
num = 10
print('%#x'%num)

# 二、打印字符串中的 16 进制
arr = '123456'
for i in arr:
    print('%#x'%ord(i))
```

##十六、python 2  和 python 3 共存问题

### 1、改名字

```powershell
将 python 改名为 python2 和 python3
```

### 2、更好的方法

```powershell
当需要python2的pip时，只需
	py -2 -m pip install xxx
当需要python3的pip时，只需
	py -3 -m pip install xxx
```

# 十七、python pandas 模块

## 1、pandas 简介

- ### 1、

````powershell
Python Data Analysis Library 或 pandas 是基于NumPy 的一种工具，该工具是为了解决数据分析任务而创建的。
````

- ### 2、

```powershell
Pandas 是python的一个数据分析包，最初由AQR Capital Management于2008年4月开发，并于2009年底开源出来，目前由专注于Python数据包开发的PyData开发team继续开发和维护，属于PyData项目的一部分。
```

- ### 3、数据结构 

```powershell
Series：一维数组，与Numpy中的一维array类似。二者与Python基本的数据结构List也很相近，其区别是：List中的元素可以是不同的数据类型，而Array和Series中则只允许存储相同的数据类型，这样可以更有效的使用内存，提高运算效率。
Time- Series：以时间为索引的Series。
DataFrame：二维的表格型数据结构。很多功能与R中的data.frame类似。可以将DataFrame理解为Series的容器。以下的内容主要以DataFrame为主。
Panel ：三维的数组，可以理解为DataFrame的容器。
Pandas 有两种自己独有的基本数据结构。读者应该注意的是，它固然有着两种数据结构，因为它依然是 Python 的一个库，所以，Python 中有的数据类型在这里依然适用，也同样还可以使用类自己定义数据类型。只不过，Pandas 里面又定义了两种数据类型：Series 和 DataFrame，它们让数据操作更简单了。
```

## 2、pandas安装

```powershell
F:\git_prj\HateIron>c:\Programs\Python\Python36\Scripts\pip.exe install pandas
Collecting pandas
  Could not find a version that satisfies the requirement pandas (from versions: )
No matching distribution found for pandas
You are using pip version 9.0.1, however version 10.0.1 is available.
You should consider upgrading via the 'python -m pip install --upgrade pip' command.

提示说 pip 版本太老，要求升级pip:

F:\git_prj\HateIron>python -m pip install --upgrade pip
Collecting pip
  Downloading https://files.pythonhosted.org/packages/0f/74/ecd13431bcc456ed390b44c8a6e917c1820365cbebcb6a8974d1cd045ab4/pip-10.0.1-py2.py3-none-any.whl (1.3MB)
    100% |████████████████████████████████| 1.3MB 6.4kB/s
Installing collected packages: pip
  Found existing installation: pip 9.0.1
    Uninstalling pip-9.0.1:
      Successfully uninstalled pip-9.0.1
Successfully installed pip-10.0.1

pip 升级成功后，继续安装 pandas:
F:\git_prj\HateIron>c:\Programs\Python\Python36\Scripts\pip.exe install pandas
Collecting pandas
  Downloading https://files.pythonhosted.org/packages/ad/0b/f65a63cccc5e37a7af983fc87a8c9e56feb4998d8877f8f2af21f40bcf3c/pandas-0.23.1-cp36-cp36m-win_amd64.whl (10.5MB)
    100% |████████████████████████████████| 10.5MB 50kB/s
Collecting python-dateutil>=2.5.0 (from pandas)
  Downloading https://files.pythonhosted.org/packages/cf/f5/af2b09c957ace60dcfac112b669c45c8c97e32f94aa8b56da4c6d1682825/python_dateutil-2.7.3-py2.py3-none-any.whl (211kB)
    100% |████████████████████████████████| 215kB 9.4kB/s
Collecting pytz>=2011k (from pandas)
  Downloading https://files.pythonhosted.org/packages/dc/83/15f7833b70d3e067ca91467ca245bae0f6fe56ddc7451aa0dc5606b120f2/pytz-2018.4-py2.py3-none-any.whl (510kB)
    100% |████████████████████████████████| 512kB 8.4kB/s
Collecting numpy>=1.9.0 (from pandas)
  Downloading https://files.pythonhosted.org/packages/0d/b7/0c804e0bcba6505f8392d042d5e333a5e06f308e019517111fbc7767a0bc/numpy-1.14.5-cp36-none-win_amd64.whl (13.4MB)
    100% |████████████████████████████████| 13.4MB 607kB/s
Collecting six>=1.5 (from python-dateutil>=2.5.0->pandas)
  Downloading https://files.pythonhosted.org/packages/67/4b/141a581104b1f6397bfa78ac9d43d8ad29a7ca43ea90a2d863fe3056e86a/six-1.11.0-py2.py3-none-any.whl
Installing collected packages: pytz, six, python-dateutil, numpy, pandas
Successfully installed numpy-1.14.5 pandas-0.23.1 python-dateutil-2.7.3 pytz-2018.4 six-1.11.0
```

##3、pandas 使用

```python
F:\git_prj\HateIron>python
Python 3.6.2 (v3.6.2:5fd33b5, Jul  8 2017, 04:57:36) [MSC v.1900 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license" for more information.
>>> from pandas import Series
>>> import pandas as pd
>>> s=Series([1,4,'ww','tt'])
>>> s
0     1
1     4
2    ww
3    tt
dtype: object
>>> s.index
RangeIndex(start=0, stop=4, step=1)
>>> s.values
array([1, 4, 'ww', 'tt'], dtype=object)
>>> s2=Series(['wangxing','man',24],index=['name','sex','age'])
>>> s2
name    wangxing
sex          man
age           24
dtype: object
>>> s2['name']
'wangxing'
>>> s2['name']='wudadiao'
>>> s2
name    wudadiao
sex          man
age           24
dtype: object
>>>
```

## 4、pandas 操作 csv

```
http://wiki.jikexueyuan.com/project/start-learning-python/312.html
```





