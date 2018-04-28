#<center>nginx</center>

[TOC]

## 一、源码编译



## 二、密码配置

```powershell
https://blog.csdn.net/sinat_21302587/article/details/54599135
```

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



