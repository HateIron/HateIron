# <center>关于SQL server 2017的御载</center>

[TOC]

#一、原因

> ###发现 visual studio 2013 无法连接到 sql  server 2017, 提示不兼容 
>
> ![](./pictures/visual_studio_2017_connect_SqlServer2017_1.png)
>
> ![](./pictures/visual_studio_2017_connect_SqlServer2017_2.png)
>
> ![](./pictures/visual_studio_2017_connect_SqlServer2017_3.png)





#二、御载步骤

##I、进入控制面板

![](pictures/unstore_sql_server_1.png)

## II、找到sql server2017(64位) 

![](./pictures/unstore_sql_server_2.png)

![](./pictures/unstore_sql_server_3.png)

![](./pictures/unstore_sql_server_4.png)

![](./pictures/unstore_sql_server_5.png)

![](./pictures/unstore_sql_server_6.png)

![](./pictures/unstore_sql_server_7.png)



# 三、手动删除目录

![](./pictures/unstore_sql_server_8.png)

![](./pictures/unstore_sql_server_9.png)



# 四、清理注册表

##I、删除注册表(win+R打开运行，输入regedit，回车运行，就会出来注册表编辑器。)

```powershell
1.将HKEY_LOCAL_MACHINE—SOFTWARE—Microsoft下的Microsoft SQL Server文件夹删除，以及下面截图的这几项
```



## II、

```powershell
2.将HKEY_CURRENT_USER—Software—-Microsoft下的Microsoft SQL Server文件夹全部删除
```

 

# 五、重启电脑



