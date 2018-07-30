#<center>dos2unix</center>

[TOC]

# 一、资源获取

file:///F:/git_prj/HateIron/2018/dos2unix-6.0.1.tar.gz



# 二、描述

```powershell
它支持多种操作系统，支持dos2unix/unix2dos，在 CentOS7上成功编译安装。
```

# 三、在`debian 8`上编译安装

## I、编译失败

```powershell
root@debian:/home/debian/study/dos2unix-6.0.1# make
msgfmt -c po/de.po -o po/de.mo
make: msgfmt: Command not found
Makefile:326: recipe for target 'po/de.mo' failed
make: *** [po/de.mo] Error 127
```

## II、解决[gettext-0.18.1.1.tar.gz](./2018/gettext-0.18.1.1.tar.gz)的问题，它的编译同样也不顺利

```powershell
报错，说找不到 msgfmt,百度之，人家说是因为缺少gettext-0.18.1.1.tar.gz,于是下载一份，14M之多，
configure成功，但是 make 失败:

In file included from closeout.c:22:0:
./stdio.h:456:1: error: 'gets' undeclared here (not in a function)
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 ^
Makefile:1106: recipe for target 'closeout.o' failed
make[5]: *** [closeout.o] Error 1

然后找到 stdio.h，并将相应行注释掉
root@debian:/home/debian/study/gettext-0.18.1.1# find ./ -name stdio.h
./gettext-runtime/gnulib-lib/stdio.h
./gettext-tools/libgettextpo/stdio.h
./gettext-tools/gnulib-lib/stdio.h


将报错的456行注释掉，并注释掉有同样问题的490行：
root@debian:/home/debian/study/gettext-0.18.1.1# vi ./gettext-tools/gnulib-lib/stdio.h +456
 452 /* It is very rare that the developer ever has full control of stdin,                                  |||     _GL_STDIO_MACROEXPAND_A
 453    so any use of gets warrants an unconditional warning.  Assume it is                                 |||     dprintf
 454    always declared, since it is required by C89.  */                                                   |||     fclose
 455 #undef gets                                                                                            |||     fflush
 456 //_GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");                                 |||     gets
 457     
  
  .......
  .......
 488 _GL_CXXALIAS_RPL (fprintf, int, (FILE *fp, const char *format, ...));                                  |||     _GL_FTELL_WARN
 489 # else                                                                                                 |||     ftell
 490 //_GL_CXXALIAS_SYS (fprintf, int, (FILE *fp, const char *format, ...));                                |||     ftello
 491 # endif   
 
编译一段时间，就会再次报同样的问题，因为生成了新的 stdio.h 文件
改完三个文件，终于编译完成，然后 make install顺利完成、
```

## III、解决掉 `gettext`之后，继续前进，还是报错

```powershell
root@debian:/home/debian/study/dos2unix-6.0.1# make
msgfmt -c po/de.po -o po/de.mo
msgfmt: error while loading shared libraries: libgettextsrc-0.18.1.so: cannot open shared object file: No such file or directory
Makefile:326: recipe for target 'po/de.mo' failed
make: *** [po/de.mo] Error 127

查找 .so 文件，是存在的
root@debian:/home/debian/study/dos2unix-6.0.1# find / -name ibgettextsrc-0.18.1.so
root@debian:/home/debian/study/dos2unix-6.0.1# find / -name libgettextsrc-0.18.1.so
/home/debian/study/gettext-0.18.1.1/gettext-tools/src/.libs/libgettextsrc-0.18.1.so
/usr/local/lib/libgettextsrc-0.18.1.so
root@debian:/home/debian/study/dos2unix-6.0.1# 

百度之，说执行命令ldconfig就行，于是试了一下
root@debian:/home/debian/study/dos2unix-6.0.1# ldconfig
/sbin/ldconfig.real: /usr/local/lib/libstdc++.so.6.0.22-gdb.py is not an ELF file - it has the wrong magic bytes at the start.
root@debian:/home/debian/study/dos2unix-6.0.1# 

然后再次 make就成功了，然后make install，圆满完成：
root@debian:/home/debian/study/dos2unix-6.0.1# whereis dos2unix
dos2unix: /usr/bin/dos2unix /usr/share/man/man1/dos2unix.1
root@debian:/home/debian/study/dos2unix-6.0.1# 
```

