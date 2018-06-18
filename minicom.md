# <center>minicom</center>

[TOC]

# 一、资源获取

```powershell
minicom-2.3.tar.gz
CSDN VIP 账号到期，以往下载的资料无法继续下载。好坑
```



# 二、安装

```powershell
./configure ; make ; make install
```



# 二、用法

## 1、首次使用时，会提示进入配置界面

```powershell
minicom -s 也是进行配置
```



## 2、`ctrl + A z x`退出

## 3、选中`serial port setup`，输入A，选中设备，输入E则配置波特率

## 4、选中主界面`save setup as dfl`将其保存为默认配置

## 5、异常处理

```powershell
如果启动时提示被锁。删除 /var/lock/LCK..ttyS0 即可
```





