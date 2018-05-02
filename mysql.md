#<center>mysql</center>

[TOC]

## 一、环境安装与配置

> <a href = "./MySQL5.7_Setup_And_Cfg.html"> MySQL5.7_Setup_And_Cfg.html </a>

## 二、连接上数据库后

###1、连接数据库

```powershell
C:\Users\15900>mysql -h 127.0.0.1 -u admin -p
Enter password: ******
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 45
Server version: 5.7.20-log MySQL Community Server (GPL)

Copyright (c) 2000, 2017, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql>
```



### 2、查看已有数据库

```mysql
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sakila             |
| sys                |
| world              |
+--------------------+
6 rows in set (0.00 sec)
```

### 3、修改账号密码

> * ####A、 给root加个密码ab12。首先在DOS下进入目录mysql\bin，然后键入以下命令
>
>   ```p
>   mysqladmin -u root -password ab12
>   ```
>
>
> * ####B、再将root的密码改为djg345
>
>   ```
>   mysqladmin -u root -p ab12 password ******
>   ```

### 4、创建数据库

```powershell
创建数据库
mysql> create database my_test;
Query OK, 1 row affected (0.01 sec)

查看之
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| my_test            |
| mysql              |
| performance_schema |
| sakila             |
| sys                |
| world              |
+--------------------+
7 rows in set (0.00 sec)
```



###5、





