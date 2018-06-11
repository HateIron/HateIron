# <center>lua</center>

[TOC]

## 一、安装包

```powershell
一、玩客云 > 分区1 > onecloud > tools > lua-5.3.4.tar.gz

二、https://www.lua.org/download.html
```



## 二、依赖包

> [ncurses.html](./ncurses.html)
>
> [readline.html](./readline.html)



## 三、安装

###1、PC机安装

```powershell
make linux ; make install
```



### 2、交叉编译

```powershell
一、更改 Makefile  中的编译器CC，ar 工具为指定工具链
二、指定依赖包 ncurses 和 readline 的头文件。以及 lib 路径
```

### 3、交叉编译中出现意外，支队 `-Wl -E`参数即可

```powershell
Makefile 中明明带上了 -static 选项，明确要求编译成静太库。但是实际编译出来的却是动态的。

通过 file 命令查看，如：
[root@localhost bin]# file mesg
mesg: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.32, BuildID[sha1]=2bb790035ffda6d6875fcfb271af8dc18e3e0535, stripped

最后将 Makefile 中 -Wl -E 两个参数删除，竟然意外的好了。
此问题在 ppc 的交叉编译环境上没有表现出来，面在 arm 上表现出来了
```



##四、Lua 文件是怎样接收参数的

```lua
for i,v in ipairs(arg) do
    print ("arg[".. i .. "] is " .. v)
end

function test()
    print ("arg[-3]=",arg[-3])
    print ("arg[-2]=",arg[-2])
    print ("arg[-1]=",arg[-1])
    print ("arg[ 0]=",arg[ 0])
    print ("arg[ 1]=",arg[ 1])
    print ("arg[ 2]=",arg[ 2])
end
test()

--> 以上为 test.lua 的内容：
[wishcell@localhost lua]$ lua test.lua 1 2 3
arg[1] is 1
arg[2] is 2
arg[3] is 3
arg[-3]=        nil
arg[-2]=        nil
arg[-1]=        lua
arg[ 0]=        test.lua
arg[ 1]=        1
arg[ 2]=        2
[wishcell@localhost lua]$

```



