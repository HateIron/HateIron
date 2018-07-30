# <center>卡片电脑PINE64</center>

[TOC]

# 一、卡片电脑PINE64初学笔记之wifi篇

##I、来自(http://www.ituring.com.cn/article/263530)

## II、网口驱动安装

```powershell
将模块插到USB口上，通过sudo ifconfig命令没有看到wlan网络设备，看来需要自己安装驱动：
1. 首先登陆 https://wiki.debian.org/WiFi ，找到对应的芯片rtl8188eu，按照教程操作，失败。。。
2. 求助万能的google，发现在github上有一个项目，提供了这个芯片的驱动，安装方法如下

debian@pine64:~$ git clone https://github.com/lwfinger/rtl8188eu.git
debian@pine64:~$ cd rtl8188eu/
debian@pine64:~/rtl8188eu$ make ARCH=arm64 KSRC=/usr/src/linux-headers-3.10.102-0-pine64-longsleep/
debian@pine64:~/rtl8188eu$ sudo make install

驱动安装完成，然后重启，通过sudo ifconfig命令可以看到wlan0设备了。
```

## III、网络配置

```powershell
1.阅读wpa_supplicant的readme文档（vim /usr/share/doc/wpasupplicant/README.Debian.gz）
2.通过readme文档，可以发现，wpa_supplicant有两种工作模式，由于我的Pine64需要在家和公司用，需要同时支持多个热点，所以我选择了Roaming Mode；
3.首先实现文件/etc/wpa_supplicant/wpa_supplicant.conf，我的配置如下：


debian@pine64:~$ cat /etc/wpa_supplicant/wpa_supplicant.conf
update_config=1
ctrl_interface=DIR=/run/wpa_supplicant GROUP=netdev

network={
ssid="lRabbit"
scan_ssid=1
psk=052a20a5ccb289dfc4d2c066673330333e41757585d61efece5cb6dcd0bda742
id_str="home"
}

network={
ssid="Stone"
scan_ssid=1
psk=ba88787a65dfdc5119547628e1c5a37ffe4e1317d5b8eacc433d9b6b63c8251a
id_str="phone"
}

network={
ssid="EKIT-0208"
scan_ssid=1
psk=b57b31f30bba529436433ad43c4aae4e2afbdbe40adb7e6a3dbff76a0a4e4852
id_str="work"
}

 如果你对上面的psk的值有疑惑，不防在你的终端运行下wpa_passphrase ssid 12345678
 
 debian@pine64:~$ wpa_passphrase ssid 12345678
network={
ssid="ssid"
#psk="12345678"
psk=eaad613a6acdd119b76ba13a0bcdd1eab41330853eb24896bf30c6cf220b7159
}
```

## IV、 配置`/etc/network/interfaces`

```powershell
配置/etc/network/interfaces文件，在文件末尾添加如下配置，注意iface后面的设备名称要和上面那个文件中的id_str的值一一对应

allow-hotplug wlan0
iface wlan0 inet manual
wpa-driver wext
wpa-roam /etc/wpa_supplicant/wpa_supplicant.conf
wpa-mapping-script /etc/wpa_supplicant/ifupdown.sh
wpa-map default: home
wpa-map0 work
wpa-map1 phone

# school can only be chosen via 'id_str' matching
iface home inet static
address 192.168.31.200
netmask 255.255.255.0
network 192.168.31.0
broadcast 192.168.31.255
gateway 192.168.31.1

iface work inet static
address 10.63.174.53
netmask 255.255.255.0
network 10.63.174.0
broadcast 10.63.174.255
gateway 10.63.174.254

iface phone inet dhcp

最后，重启网络服务，你会看到你已经连上wifi了。
最最后，提醒各位一句，千万不要把你的wifi网口和有线网口设置在同一个网段，那酸爽，谁设谁知道！！
```















