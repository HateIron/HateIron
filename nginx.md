#<center>nginx</center>

[TOC]

## 一、资源获取，源码编译

## I、资源获取

```powershell
这里有各种版本：
	http://nginx.org/download/

自己的空间
	玩客云 》分区１　》　onecloud 》 tools 》　nginx-1.9.3.tar.gz 
	玩客云 》分区１　》　onecloud 》 tools 》　nginx-1.9.5.tar.gz 
	玩客云 》分区１　》　onecloud 》 tools 》　nginx-1.9.9.tar.gz     
```

## II、编译安装

```
./configure & make & make install
```



## 二、密码配置。[来自](https://blog.csdn.net/sinat_21302587/article/details/54599135)

### 1、nginx配置文件中加入

```powershell
  location / {
    root   html;
    index  index.html index.htm index index.jpg;
    auth_basic 'Restricted';
    auth_basic_user_file htpasswd;
  }
```

###2、使用htpasswd这个工具生密码

```powershell
htpasswd -c /usr/local/nginx/conf/htpasswd UserName

UserName 就是你的用户名
/usr/local/nginx/conf/htpasswd 是密码文本存放的路径（这跟你的nginx.conf 配置文件中有关)
```



