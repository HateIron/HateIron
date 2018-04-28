# rpm 相关操作命令



##1、yum install CCache报错，要求导入公钥

```
rpm --import public.gpg.key
#rpm --import /etc/pki/rpm-gpg/RPM-GPG-KEY-CentOS-7
```



## 2、rpm 卸载及安装

```
卸载：
rpm -qa | grep vim
rpm -e vim-x11-7.4.160-1.el7.x86-64   #普通卸载
rpm -e --nodeps vim-minimal           #强制卸载

安装,先到/mnt/cdrom/Packages中，用 ls | grep vim 查看有哪些安装包，或者都不用管，直接用 yum 安装
yum install vim
它会自动解决依赖关系
```

