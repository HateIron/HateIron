#<center>nginx</center>

[TOC]

#一、资源获取，源码编译

##I、资源获取

```powershell
这里有各种版本：
	http://nginx.org/download/

自己的空间
	玩客云 》分区１　》　onecloud 》 tools 》　nginx-1.9.3.tar.gz 
	玩客云 》分区１　》　onecloud 》 tools 》　nginx-1.9.5.tar.gz 
	玩客云 》分区１　》　onecloud 》 tools 》　nginx-1.9.9.tar.gz     
```

##II、编译安装

```
./configure & make & make install
```

#二、密码配置。[来自](https://blog.csdn.net/sinat_21302587/article/details/54599135)

##1、nginx配置文件中加入

```powershell
  location / {
    root   html;
    index  index.html index.htm index index.jpg;
    auth_basic 'Restricted';
    auth_basic_user_file htpasswd;
  }
```

##2、使用htpasswd这个工具生密码

```powershell
htpasswd -c /usr/local/nginx/conf/htpasswd UserName

UserName 就是你的用户名
/usr/local/nginx/conf/htpasswd 是密码文本存放的路径（这跟你的nginx.conf 配置文件中有关)
```



# 三、使用 android NDK 编译 nginx

## I、CentOS7 Android studio 环境搭建

- 下载 [openssl-1.0.1c.tar.gz](玩客云》分区1》onecloud》tools》openssl-1.0.1c.tar.gz)（玩客云》分区1》onecloud》tools》openssl-1.0.1c.tar.gz）
- 下载 [nginx-1.5.9.tar.gz](玩客云》分区1》onecloud》tools》nginx-1.5.9.tar.gz)        (玩客云》分区1》onecloud》tools》nginx-1.5.9.tar.gz)
- 下载 [pcre-8.34.zip](玩客云》分区1》onecloud》tools》pcre-8.34.zip)                (玩客云》分区1》onecloud》tools》pcre-8.34.zip)
- 下载 [zlib-1.2.8.tar.gz](玩客云》分区1》onecloud》tools》zlib-1.2.8.tar.gz)            (玩客云》分区1》onecloud》tools》zlib-1.2.8.tar.gz)
- 下载 [ nginx_mod_h264_streaming-2.2.7.tar.gz](玩客云》分区1》onecloud》tools》 nginx_mod_h264_streaming-2.2.7.tar.gz)            (玩客云》分区1》onecloud》tools》 nginx_mod_h264_streaming-2.2.7.tar.gz)
- 下载[rtmp模组  nginx-rtmp-module.tar](玩客云》分区1》onecloud》tools》nginx-rtmp-module.tar)     
- - 或者采用 git 命令下载`git clone https://github.com/arut/nginx-rtmp-module`
  - 玩客云》分区1》onecloud》tools》nginx-rtmp-module.tar

## II、环境安装配置

> 在图形界面，执行安装命令
>
> ```
> [wishcell@localhost package]$ cd android-studio/
> [wishcell@localhost android-studio]$ ls
> bin  build.txt  gradle  Install-Linux-tar.txt  jre  lib  license  LICENSE.txt  NOTICE.txt  plugins
> [wishcell@localhost android-studio]$ cd bin/
> [wishcell@localhost bin]$ ls
> appletviewer.policy  fsnotifier    idea.properties  lldb     printenv.py  studio64.vmoptions  studio.sh
> format.sh            fsnotifier64  inspect.sh       log.xml  restart.py   studio.png          studio.vmoptions
> [wishcell@localhost bin]$ sh studio.sh
> ```
>
> ![](./pictures/linux_install_android_studio.png)

```powershell
前面做过很多次尝试，编译也通过了，但是去掉了很多glob和crypto的函数，导致运行的时候还是会出错，所以，本次按照正常方法，加全所有的函数，然后编译之后运行。
1)在工作目录下建立build目录 
2)准备文件，
a) 下载openssl，wget wget http://www.openssl.org/source/openssl-1.0.1f.tar.gz tar
b) 下载nginx,wget http://nginx.org/download/nginx-1.5.9.tar.gz
c) 下载pcre,wget ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/pcre-8.34.tar.gz
d) 下载zlib,wget http://www.zlib.net/zlib-1.2.8.tar.gz
e) 下载下载nginx_mod_h264,wget http://h264.code-shop.com/download/nginx_mod_h264_streaming-2.2.7.tar.gz
f) 下载rtmp模组，git clone https://github.com/arut/nginx-rtmp-module

3) 编译openssl
a) tar tar xvf openssl-1.0.1f.tar.gz
b) cd openssl-1.0.1f
c) 使用如下的配置文件
--------------------------------my_configure_openssl.sh start here-----------------------------------------
#!/bin/sh
./config no-asm shared \
--prefix=/home/zangcf/nginx_ndk/build \
--------------------------------my_configure_openssl.sh end here-----------------------------------------
d) gedit Makefile，进入修改Makefile
    the first step) 找到所有的-m64，删除
    the sencond step)找到CC= gcc，替换为CC= /opt/android-toolchain/android-14/bin/arm-linux-androideabi-gcc
    the third step)找到AR= ar $(ARFLAGS) r，替换为AR= /opt/android-toolchain/android-14/bin/arm-linux-androideabi-ar $(ARFLAGS) r
    the fourth step)找到RANLIB= /usr/bin/ranlib，替换为RANLIB= /opt/android-toolchain/android-14/bin/arm-linux-androideabi-ranlib
    the fifth step)找到NM= nm,修改为NM= /opt/android-toolchain/android-14/bin/arm-linux-androideabi-gcc-nm
    the sixth step)找到MAKEDEPPROG= gcc，修改为MAKEDEPPROG= /opt/android-toolchain/android-14/bin/arm-linux-androideabi-gcc
e)cp Makefile Makefile.ok
f)执行make && make install

4) 编译pcre
a） tar xvf pcre-8.34.tar.gz
b) cd  xvf pcre-8.34
c) gedit my_configure_pcre.sh
-----------------------------------my_configure_pcre.sh start here------------------------------------------------
#!/bin/sh
./configure \
--host=arm-linux \
--prefix=/home/zangcf/nginx_ndk/build \
CC=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-gcc \
CPP=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-cpp \
AR=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-ar \
AS=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-as \
CXX=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-g++ \
CXXCPP=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-cpp
-----------------------------------my_configure_pcre.sh end here------------------------------------------------
d)chmod u+x my_configure_pcre.sh
e)./my_configure_pcre.sh
f)make && make install

5) 解压zlib
tar xvf zlib-1.2.8.tar.gz

6) 解压nginx_mod_h264

7)编译nginx
a)tar xvf nginx-1.5.9.tar.gz
b)cd nginx-1.5.9
c)gedit auto/cc/name
    if [ "$NGX_PLATFORM" != win32 ]; then

    ngx_feature="C compiler"
    ngx_feature_name=
    #ngx_feature_run=yes
    ngx_feature_run=no   ==>set to no to skip check
    ngx_feature_incs=
    ngx_feature_path=

d)gedit auto/types/sizeof
    ngx_test="$CC $CC_TEST_FLAGS $CC_AUX_FLAGS
    ==> ngx_test="gcc $CC_TEST_FLAGS $CC_AUX_FLAGS

e) gedit src/os/unix/ngx_errno.h
at line 15 add #define NGX_SYS_NERR 333

f) gedit src/os/unix/ngx_shmem.c
#if (NGX_HAVE_MAP_ANON) ==> #if (!NGX_HAVE_MAP_ANON)

g) gedit auto/lib/pcre/make
    ./configure --disable-shared $PCRE_CONF_OPT 

修改为
    ./configure --disable-shared $PCRE_CONF_OPT \
--host=arm-linux \
--prefix=/home/zangcf/nginx_ndk/build \
CC=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-gcc \
CPP=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-cpp \
AR=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-ar \
AS=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-as \
CXX=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-g++ \
CXXCPP=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-cpp

h) gedit auto/lib/openssl/make
$OPENSSL/.openssl/include/openssl/ssl.h:    $NGX_MAKEFILE
    cd $OPENSSL \\
    && if [ -f Makefile ]; then \$(MAKE) clean; fi \\
    && ./config --prefix=$ngx_prefix no-shared $OPENSSL_OPT \\
    && \$(MAKE) \\
    && \$(MAKE) install LIBDIR=lib
修改为
$OPENSSL/.openssl/include/openssl/ssl.h:    $NGX_MAKEFILE
    cd $OPENSSL \\

i) 打开/home/zangcf/nginx_ndk/nginx_mod_h264_streaming-2.2.7/src/ngx_http_streaming_module.c，删除
 if (r->zero_in_uri)   { 
    return NGX_DECLINED;  
 } 


j) gedit my_configure_nginx.sh
-----------------------------------my_configure_nginx.sh start here------------------------------------------------
#!/bin/sh
BUILD_PATH=/home/zangcf/nginx_ndk/build
CC_PATH=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-gcc
CPP_PATH=/opt/android-toolchain/android-14/bin/arm-linux-androideabi-g++
./configure \
  --prefix=$BUILD_PATH \
  --builddir=$BUILD_PATH \
  --with-zlib=/home/zangcf/nginx_ndk/zlib-1.2.8 \
  --with-pcre=/home/zangcf/nginx_ndk/pcre-8.34 \
  --with-pcre-jit \
  --with-cc=$CC_PATH  \
  --with-cpp=$CPP_PATH \
  --with-openssl=/home/zangcf/nginx_ndk/openssl-1.0.1f \
  --add-module=/home/zangcf/nginx_ndk/nginx_mod_h264_streaming-2.2.7 \
  --with-http_flv_module \
  --with-http_mp4_module \
  --add-module=/home/zangcf/nginx_ndk/nginx-rtmp-module
-----------------------------------my_configure_nginx.sh end here------------------------------------------------

k) gedit ../build/Makefile 
注意这里使用的arm_linux_gcc版本必须是4.4.3以后的，之前的本本可能会出错。
   the first step)找到-I /home/zangcf/nginx_ndk/openssl-1.0.1f/.openssl/include \，替换为-I /home/zangcf/nginx_ndk/build/include/openssl \
   the second step)找到 /home/zangcf/nginx_ndk/openssl-1.0.1f/.openssl/include/openssl/ssl.h \，替换为/home/zangcf/nginx_ndk/build/include/openssl/ssl.h
   the third step)CFLAGS增加-I/opt/FriendlyARM/toolschain/4.4.3/arm-none-linux-gnueabi/sys-root/usr/include和-I/home/zangcf/nginx_ndk/build/include
   the fourth step) CLAGS去掉 -Werror
   the fifth step) 找到/home/zangcf/nginx_ndk/pcre-8.34/.libs/libpcre.a /home/zangcf/nginx_ndk/openssl-1.0.1f/.openssl/lib/libssl.a，替换为/home/zangcf/nginx_ndk/build/lib/libssl.a
   the sixth step)找到/home/zangcf/nginx_ndk/openssl-1.0.1f/.openssl/lib/libcrypto.a，替换为/home/zangcf/nginx_ndk/build/lib/libcrypto.a 
   the seventh step) 在链接目标文件增加libc的标准库地址/opt/FriendlyARM/toolschain/4.4.3/arm-none-linux-gnueabi/sys-root/usr/lib/libcrypt.a和/opt/FriendlyARM/toolschain/4.4.3/arm-none-linux-gnueabi/sys-root/usr/lib/libc.a /home/zangcf/nginx_ndk/build/lib/libpcre.a
   the eight step ) 找到/home/zangcf/nginx_ndk/pcre-8.34/.libs/libpcre.a，替换为/home/zangcf/nginx_ndk/build/lib/libpcre.a
这里如果集成Makefile还有找不到的文件，需要指定链接过程，类似做法如上。
l) make && make install
大工告成
```





