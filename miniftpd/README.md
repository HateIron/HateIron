# Tachftp
Linux下ftp服务器（仿vsftpd）

### Linux下使用C语言实现的FTP服务器，实现vsftpd的绝大部分功能
* 支持主被动模式：
* 支持配置文件的自定义修改;
* 实现绝大部分FTP命令;
* 使用UNIX域协议进行nobody进程和服务进程间的通信;
* 支持文件上传/下载的断点续传;
* 支持自定义限速;
* 支持最大连接数和单IP最大连接数限制。

### 使用方法
```
make
sudo ./miniftpd

ftp 127.0.0.1 5188（配置文件中的listen_port）
```

### 联系作者
https://blog.csdn.net/nk_test/article/details/50575386
* 可以参考我的博客： http://blog.csdn.net/nk_test/article/details/50575386
* 有问题可以联系我：  acm_tach@163.com
    
