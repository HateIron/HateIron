# <center>ada</center>

[TOC]

## 一、ADA简介

https://baike.baidu.com/item/ada/5606819?fr=aladdin

## 二、环境安装

```powershell
打通网络:
[root@localhost ada]# yum install gcc-gnat
```



##三、`hello world`

```ada
with Ada.Text_IO; use Ada.Text_IO; 
procedure Hello is 
begin 
  Put_Line ("Hello, world!"); 
end Hello;
```

> #### 1、编译之
>
> ```powershell
> [wishcell@localhost ada]$ gcc -c -g -gnatyt a.adb
> a.adb:3:11: warning: file name does not match unit name, should be "hello.adb"
>
> 提示错误，要求把 a.adb 改名为 hello.adb
> [wishcell@localhost ada]$ mv a.adb hello.adb
>
> 再编译，采用以下两种方法编译效果相同：
> [wishcell@localhost ada]$ gcc -c -g -gnatyt hello.adb
> [wishcell@localhost ada]$ ls
> hello.adb  hello.ali  hello.o
> [wishcell@localhost ada]$
>
> 或者：
> [wishcell@localhost ada]$ gcc -c -g -gnatyt -gnatq -gnatQ -I- -gnatA hello.adb
> [wishcell@localhost ada]$ ls
> hello.adb  hello.ali  hello.o
> ```
>
> #### 2、运行之
>
> ```powershell
> 发现编译出来的文件无法运行：
> [wishcell@localhost ada]$ chmod +x ./hello.o
> [wishcell@localhost ada]$ ls
> hello.adb  hello.ali  hello.o
> [wishcell@localhost ada]$ ./hello.o
> -bash: ./hello.o: cannot execute binary file
> [wishcell@localhost ada]$
> ```
>
> #### 3、想办法弄明白原因
>
> ```powershell
> 百度了半天，没有找到完整答案。才恍然间想起明杰同志的话：yahoo
> 果然，输入 gcc ada examples，人家给出了精准答案：
> 	https://gcc.gnu.org/onlinedocs/gnat_ugn/Running-a-Simple-Ada-Program.html
>
> [wishcell@localhost ada]$ gcc -c hello.adb
> [wishcell@localhost ada]$ ls
> hello.adb  hello.ali  hello.o
>
> 这样竟然也可以编译。 -c 参数必须带上，否则编译失败。
> 然后，分别调用gnatbind 和 gnatlink 来生成可执行文件。它们的参数是 hello.ali，后缀名可省
> [wishcell@localhost ada]$ gnatbind hello
> [wishcell@localhost ada]$ ls
> b~hello.adb  b~hello.ads  hello.adb  hello.ali  hello.o
> [wishcell@localhost ada]$ gnatlink hello
> [wishcell@localhost ada]$ ls
> hello  hello.adb  hello.ali  hello.o
> [wishcell@localhost ada]$ ./hello
> Hello, world!
> [wishcell@localhost ada]$
> ```
>
> #### 4、一步得到可执行文件的方法 
>
> ```powershell
> 一步到位的方法：调用 gnatmake，它内部执行了编译、绑定、链接等动作。
> 更牛逼的是，如果代码（或者依赖）有改动，它能自动重新编译代码
>
> [wishcell@localhost ada]$ gnatmake hello.adb
> gcc -c hello.adb
> gnatbind -x hello.ali
> gnatlink hello.ali
> [wishcell@localhost ada]$ ./hello
> Hello, world!
> [wishcell@localhost ada]$
> ```



### 四、终于找到权威手册，可惜版本略老

<a href = "./gnat_ugn_unw.pdf">gnat_ugn_unw.pdf</a>



