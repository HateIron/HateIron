#<center>centos configure</center>

<span id='jump'></span>

[TOC]

## 一、CentOS IP 配置（virtual box 中为桥接网卡，混杂模式为拒绝，接入网线复选框选中）

```shell
#vi /etc/sysconfig/network-script/ifcfg-eth0
DEVICE=eth0
BOOTPROTO=static
HWADDR=;#这里是相应网卡的物理地址，通常如果检查到网卡的话就不用输入了
ONBOOT=yes
IPADDR=192.168.1.123
NETRMASK=255.255.255.0
NETWORK=192.168.1.0
BROADCAST=192.168.1.255
GATEWAY=192.168.1.254
```

##二、重启网络

```shell
#/sbin/service network restart
#/etc/init.d/network reload
```

##三、一句话配置IP

```shell
# ifconfig eth0 192.168.1.12 netmask 255.255.255.0 up
```

##四、网关修改

```shell
# route add default gw 192.168.1.2
# route del default gw 192.168.32.1

不加这一句导致拼不通外网，浪费许多时间：
	route add default gw 192.168.43.1
```

##五、打开/关闭网关

```shell
# ifconfig eth0 up
# ifconfig eth0 down
```

##六、编辑DNS

```shell
# vi /etc/resolv.conf
# nameserver 61.147.37.1
# nameserver 61.177.7.1

一般配置为下面内容后，虚拟机即可以连接 baidu.com
vi /etc/resolv.conf 
nameserver 8.8.8.8
nameserver 8.8.4.4
```

##七、编辑网关

```shell
# vi /etc/sysconfig/network
NETWORKING=yes
HOSTNAME=vmlinux
GATEWAY=192.168.1.254
```

##八、[smb.conf](http://hateiron.coding.me/2017-12/smb.conf) 标准配置

```shell
[global]
dos charset = GB2312
unix charset = GB2312
display charset = GB2312
directory mask = 0777
force directory mode = 0777
directory security mask = 0777
force directory security mode = 0777
create mask = 0777
force create mode = 0777
security mask = 0777
force security mode = 0777
workgroup = homedir
netbios = homedir
server string = linux samba server
security = user
username map = /etc/samba/smbusers

[WishCell]
    path = /home/WishCell
    browseable = yes
    security = share
    writeable = yes
    valid users = WishCell
    create mode = 0777
    force create mode = 0777
    force directory mode = 0777
```

##九、关闭防火墙，重启 samba

```shell
# setenforce 0
# sudo systemctl stop firewall.service && sudo systemctl disable firewall.service
# systemctl status smb.service
```

##十、创建新用户，并为其设置 samba

```shell
# useradd WishCell   //如果不满意，删除之：userdel WishCell
# passwd WishCell    //设置密码
# smbpasswd -a WishCell //设置 samba
# 然后编辑 /etc/samba/smb.conf
```



## 十一、vsfptd 配置

##十二、无网络情况下，CentOS7如何安装最新 Firefox

###1、首先到官网上下载最新的 Linux相应版本

> 官网`http://www.firefox.com.cn/download#more`
>
> 我是 CentOS7 x86_64环境，选择`linux 64-bit 中文版`，然后下载到相应的安装包
>
> [Firefox-latest-x86_64.tar.bz2](http://download.csdn.net/download/u013752213/10241228)

### 2、具体安装步骤

>####A、下载Linux版本的Firefox，因为我的是64位故选择的安装包是：”Firefox-latest-x86_64.tar.bz2“。
>
>#### B、解压之
>
>```shell
># tar -xf Firefox-latest-x86_64.tar.bz2
># cd firefox
>```
>
>#### C、删除系统默认安装的 firefox，通常位于 `/usr/lib64`下
>
>```shell
># rm /usr/lib64/firefox -rf
>```
>
>#### D、将当前新版 `firefox` 子目录复制到`/usr/lib64`目录下
>
>```shell
># cp ./firefox /usr/lib64
>```
>
>#### E、进入`/usr/bin`，删除其下的 `firefox` 脚本
>
>```shell
># cd /usr/bin
># rm firefox -rf
>```
>
>#### F、回到主目录或者根目录，创建一个软链接，指向 `/usr/lib64/firefox/firefox`
>
>```shell
># cd 
># ln -s /usr/lib64/firefox/firefox /usr/bin/firefox
>```
>
>#### G、查看最新版本
>
>```shell
># firefox -v
>```
>
>

## 十三、CentOS 7 下面安装极点五笔

> ###1、从百度网盘下载一份极点五笔的 `linux`安装包
>
> ### 2、解压之，得到三个文件
>
> ```shell
> #ls
> vissible.db
> vissible.gif
> vissible.txt
> # su root
> # cp vissible.db  /usr/share/ibus-table/tables
> # cp vissible.gif /usr/share/ibus-table/icons
> ```
>
> ###3、具体界面操作
>
> 右击右上角的输入法图标，弹出一对话框，选择`Region & Language Settings`，然后在 `imput source `下点击加号，找到极点五笔
>
> ### 4、将无用重复的中文/英文选项删除，保持清爽
>
> ### 5、输入法切换
>
> ​    默认输入法的切换快捷键为 'supper + space'，实际上 supper 键就是  win 键



