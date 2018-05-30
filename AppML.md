# AppML

[TOC]

##一、简介

### 1、什么是 `<AppML>`

```powershell
<AppML> appML是一个为web应用程序设计的HTML扩展框: 

    XML 语言定义了应用的模型
    JavaScript 运行于客户端浏览器上
    PHP 或者 ASP 脚本运行于服务器上

AppML 是应用模式语言（ Application Modeling Language）。
```

###2、学习非常简单

- 超级简单的模型
- 超级简单的属性
- 超级简单的应用开发
- 运行于任何平台及任何浏览器
- 安装简单

###3、只有 HTML, JavaScript, 和 XML

```powershell
<AppML> 只需要在HTML页面中包含 JavaScript，然后再服务端上存储 XML 数据
```

###4、现代 Web 架构

`<AppML>` 是一个结合了最新的技术和现代web开发想法，使用低消耗高速简单的架构：

- 采用 MVC 架构
- 极低的带宽消耗
- 云计算的优化
- 内容完全分离
- 智能，灵活，快速的Web开发
- 高度的可扩展性和可测试性
- 简单的配置和重新配置
- 智能支持用户账号和角色

##二、使用`AppML`

### 1、先下载之 [AppML.zip](./AppmlPHP.zip)

```powershell
<AppML> 不是一个产品。 <AppML> 是一个想法。 它仅仅是在浏览器上的脚本和服务器上的脚本。

任何人都可以下载 <AppML> ，下载后可以修改基本来创建我们自己的专业web应用。 
```

| 文件名                       | 描述                 |
| ---------------------------- | -------------------- |
| appml.php (或者.htmlx)       | `<AppML> `服务端脚本 |
| appml.css                    | `<AppML>`样式文件    |
| appml.js                     | `<AppML>` 浏览器脚本 |
| appml_config.php (or .htmlx) | `<AppML>` 本地配置   |
| Images (文件夹)              | `<AppLM>` 图片样式   |

### 2、解压使用之

直接解压之，解压在了 /study/demo目录之下

### 3、重新配置数据库连接，修改`appml.config `

```
<database name="demo">
  <host>127.0.0.1</host>
  <name>mydb</name>
  <user>admin</user>
  <password>123456</password>
</database>
```

###4、在数据库 deom 中，创建自己的表

#### A、customers 表

```powershell
mysql> create table Customers (Customer VARCHAR(40), Address CHAR(40), City CHAR(40),Country CHAR(40));
Query OK, 0 rows affected (0.04 sec)

insert into Customers values("Around the Horn","120","Hanover Sq.","London 	UK");
insert into Customers values("Berglunds snabbkjøp","Berguvsvägen 8","Luleå","Sweden");
insert into Customers values("Blauer See Delikatessen","Forsterstr. 57","Mannheim","Germany");
insert into Customers values("Blondel fils","24, place Kr","Strasbourg","France");
insert into Customers values("lido Comidas preparadas","C/ Araquil, 67","Madrid","Spain");
insert into Customers values("Bottom-Dollar Markets","23 Tsawassen Blvd.","Tsawassen","Canada");

mysql> select * from customers;
+-------------------------+--------------------+-------------+-----------+
| Customer                | Address            | City        | Country   |
+-------------------------+--------------------+-------------+-----------+
| Around the Horn         | 120                | Hanover Sq. | London UK |
| Berglunds snabbkj?p     | Berguvsv?gen 8     | Lule?       | Sweden    |
| Blauer See Delikatessen | Forsterstr. 57     | Mannheim    | Germany   |
| Bottom-Dollar Markets   | 23 Tsawassen Blvd. | Tsawassen   | Canada    |
| Blondel fils            | 24, place Kr       | Strasbourg  | France    |
| lido Comidas preparadas | C/ Araquil, 67     | Madrid      | Spain     |
+-------------------------+--------------------+-------------+-----------+
6 rows in set (0.00 sec)
```



####B、创建`Suppliers`表

```powershell
mysql> create table Suppliers (Supplier VARCHAR(40), Address CHAR(40), City CHAR(40),Country CHAR(40));
Query OK, 0 rows affected (0.03 sec)

mysql> insert into Suppliers values("Exotic Liquid","49 Gilbert St.","London","UK");
mysql> insert into Suppliers values("New Orleans Cajun Delights","P.O. Box 78934","New Orleans","USA");
mysql> insert into Suppliers values("Grandma Kelly's Homestead","707 Oxford Rd.","Ann Arbor","USA");
mysql> insert into Suppliers values("Tokyo Traders","9-8 SekimaiMusashino-shi","Tokyo","Japan");
mysql> insert into Suppliers values("Cooperativa de Quesos 'Las Cabras'","Calle del Rosal 4","Oviedo","Spain");
mysql> insert into Suppliers values("Mayumi's","92 Setsuko Chuo-ku","Osaka","Japan");
mysql> insert into Suppliers values("Pavlova, Ltd.","74 Rose St. Moonie Ponds","Melbourne","Australia");
mysql> insert into Suppliers values("Specialty Biscuits, Ltd.","29 King's Way","Manchester","UK");
mysql> insert into Suppliers values("PB Kn ckebr d AB","Kaloadagatan 13","G teborg","Sweden");
mysql> insert into Suppliers values("Refrescos Americanas LTDA","Av. das Americanas 12.890","S o Paulo","Brazil");

mysql> select * from suppliers;
+------------------------------------+---------------------------+-------------+-----------+
| Supplier                           | Address                   | City        | Country   |
+------------------------------------+---------------------------+-------------+-----------+
| Exotic Liquid                      | 49 Gilbert St.            | London      | UK        |
| New Orleans Cajun Delights         | P.O. Box 78934            | New Orleans | USA       |
| Grandma Kelly's Homestead          | 707 Oxford Rd.            | Ann Arbor   | USA       |
| Tokyo Traders                      | 9-8 SekimaiMusashino-shi  | Tokyo       | Japan     |
| Cooperativa de Quesos 'Las Cabras' | Calle del Rosal 4         | Oviedo      | Spain     |
| Mayumi's                           | 92 Setsuko Chuo-ku        | Osaka       | Japan     |
| Pavlova, Ltd.                      | 74 Rose St. Moonie Ponds  | Melbourne   | Australia |
| Specialty Biscuits, Ltd.           | 29 King's Way             | Manchester  | UK        |
| PB Kn ckebr d AB                   | Kaloadagatan 13           | G teborg    | Sweden    |
| Refrescos Americanas LTDA          | Av. das Americanas 12.890 | S o Paulo   | Brazil    |
+------------------------------------+---------------------------+-------------+-----------+
10 rows in set (0.00 sec)
```

####C、创建表`Products`

```sql
mysql> create table Products (Product VARCHAR(40), QuantityPerUnit CHAR(40), UnitPrice int(4),UnitsInStock int(4));

insert into Products values ("Chai","10 boxes x 20 bags","18","39");
insert into Products values ("Chang","24 - 12 oz bottles","19","17");
insert into Products values ("Aniseed Syrup","12 - 550 ml bottles","10","13");
insert into Products values ("Chai","10 boxes x 20 bags","18","39");
insert into Products values ("Chef Anton's Gumbo Mix","36 boxes","21","0");
insert into Products values ("Grandma's Boysenberry Spread","12 - 8 oz jars","25","120");
insert into Products values ("Uncle Bob's Organic Dried Pears","12 - 1 lb pkgs.","30","15");
insert into Products values ("Northwoods Cranberry Sauce","12 - 12 oz jars","40","6");
insert into Products values ("Mishi Kobe Niku","18 - 500 g pkgs.","97","29");
insert into Products values ("Ikura","12 - 200 ml jars","31","31");
mysql> select * from products;
+---------------------------------+---------------------+-----------+--------------+
| Product                         | QuantityPerUnit     | UnitPrice | UnitsInStock |
+---------------------------------+---------------------+-----------+--------------+
| Chai                            | 10 boxes x 20 bags  |        18 |           39 |
| Chang                           | 24 - 12 oz bottles  |        19 |           17 |
| Aniseed Syrup                   | 12 - 550 ml bottles |        10 |           13 |
| Chai                            | 10 boxes x 20 bags  |        18 |           39 |
| Chef Anton's Gumbo Mix          | 36 boxes            |        21 |            0 |
| Grandma's Boysenberry Spread    | 12 - 8 oz jars      |        25 |          120 |
| Uncle Bob's Organic Dried Pears | 12 - 1 lb pkgs.     |        30 |           15 |
| Northwoods Cranberry Sauce      | 12 - 12 oz jars     |        40 |            6 |
| Mishi Kobe Niku                 | 18 - 500 g pkgs.    |        97 |           29 |
| Ikura                           | 12 - 200 ml jars    |        31 |           31 |
+---------------------------------+---------------------+-----------+--------------+
```

