#<center>uboot cmdline解读</center>

<span id='jump'></span>

[TOC]

###来源：`http://blog.csdn.net/shengzhadon/article/details/52766263`



## 1、最关键的数据结构定义

```c
typedef struct cmd_tbl_s    cmd_tbl_t; 

struct cmd_tbl_s {  
    char   *name;       /* Command Name         */  
    int     maxargs;    /* maximum number of arguments  */  
    int     repeatable; /* autorepeat allowed?      */  
                        /* Implementation function  */  
    int     (*cmd)(struct cmd_tbl_s *, int, int, char * const []);  
    char     *usage;     /* Usage message    (short) */  
#ifdef  CONFIG_SYS_LONGHELP  
    char        *help;      /* Help  message    (long)  */  
#endif  
  
#ifdef CONFIG_AUTO_COMPLETE  
    /* do auto completion on the arguments */  
    int     (*complete)(int argc, char * const argv[], char last_char, int maxv, char *cmdv[]);
#endif
};  
```

## 2、用宏定义的方式，定义变量

```c
/* uboot/include/linker_lists.h */
#define ll_entry_declare(_type, _name, _list)               \  
    _type _u_boot_list_2_##_list##_2_##_name __aligned(4)       \  
            __attribute__((unused,              \  
            section(".u_boot_list_2_"#_list"_2_"#_name)))  

/* uboot/include/command.h */
#define U_BOOT_CMD_MKENT_COMPLETE(_name, _maxargs, _rep, _cmd,  _usage, _help, _comp)  \  
        { #_name, _maxargs, _rep, _cmd, _usage,         \
            _CMD_HELP(_help) _CMD_COMPLETE(_comp) }  

#define U_BOOT_CMD_COMPLETE(_name, _maxargs, _rep, _cmd, _usage, _help, _comp) \  
   		 ll_entry_declare(cmd_tbl_t, _name, cmd) =           		\  
        		U_BOOT_CMD_MKENT_COMPLETE(_name, _maxargs, _rep, _cmd,  \  
                        				 _usage, _help, _comp);  

#define U_BOOT_CMD(_name, _maxargs, _rep, _cmd, _usage, _help)      \  
    U_BOOT_CMD_COMPLETE(_name, _maxargs, _rep, _cmd, _usage, _help, NULL)
      
/* uboot/common/cmd_net.c */
#if defined(CONFIG_CMD_NFS)  
	static int do_nfs(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])  
	{  
	    return netboot_common(NFS, cmdtp, argc, argv);  
	}  
	  
	U_BOOT_CMD(  
	    nfs,    3,  0,  do_nfs,  
	    "boot image via network using NFS protocol",  
	    "[loadAddress] [[hostIPaddr:]bootfilename]"  
	);  
#endif  
```

## 3、概括

> 如前所述，U_BOOT_CMD的作用就是定义一个结构体变量（struct cmd_tbl_s），并将其存放再uboot的没有被占用的section中。展开就是：
>
> ```c
> struct cmd_tbl_s _u_boot_list_2_cmd_2_##_name = {  
>         #_name, _maxargs, _rep, _cmd, _usage, _help, NULL  
>     };  
> ```
>
> 注：该变量属性是4字节对齐（__aligned(4) ），存放在未被使用的section中，并将该section命名为【".u_boot_list_2_"#name】（__attribute__((unused, section(".u_boot_list_2_"#name)))）。



##4、举例

---

命令nfs

```c
U_BOOT_CMD(  
    nfs,    3,  0,  do_nfs,  
    "boot image via network using NFS protocol",  
    "loadAddressbootfilename]"  
);  
```

即为：

```c
struct cmd_tbl_s _u_boot_list_2_cmd_2_nfs = {  
        "nfs", 3, 0, do_nfs,  
        "boot image via network using NFS protocol",  
        "[loadAddress] [[hostIPaddr:]bootfilename]", NULL  
    };  
```

将_u_boot_list_2_cmd_2_nfs变量4字节对齐存放在未被使用的uboot的section中，该section被命名为.u_boot_list_2_nfs。

## 5、简化版写法

### A、定义结构体

```c
typedef struct {
  char *name;
  char *help;
  int   argc;
  int (*func)(int argc, char **argv);
} cmd_tbl_s;
```

### B、直接用宏定义变量，将中间步骤直接省略

```c
#define PARSE_CMD_LINE(_name, _help, _argc, _func) \
	cmd_tbl_s cmd_list##_name = { 	\
	.name = #_name,                 \  //将普通字符转化为字符串变量
	.help = _help,					\  //_help 本身就是字符串传进来，无需转换
    .argc = _argc,					\
	.func = _func }
}
```

### C、应用

```c
PARSE_CMD_LINE(clean, "clean screen", 0, clean_screen);
/* 实际上定义了一个变量 cmd_list_clean */
即：
cmd_tbl_s cmd_list_clean = {"clean", "clean screen", 0, clean_screen};
```

###D、系统组成

> 通过多条 `PARSE_CMD_LINE` 宏，注册（生成）多条命令行子功能。
>
> 只需要将其追加到一个列表中即可遍历访问：
>
> cmd_tbl_s *cmd_tbl[] = 
>
> {
>
> ​	&cmd_list_clean,
>
> ​	&cmd_list_help,
>
> };

###E、系统动作

> 主函数 `main`运行一个`while(1)`列循环，然后不断监测用户输入。
>
> 如检测到用户输入了 `clean`则清空屏幕。
>
> ​	或者其它命令，解析成命令和相应参数