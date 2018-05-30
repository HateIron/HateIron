#<center>sed</center>

[TOC]

##一、将 Makefile 中的字符串 abc 替换成 efg

```shell
# sed -i -e 's/abc/efg/g' `find . -name Makefile`
```

##二、在 vim 中，对指定行数范围，采用 sed 替换

```shell
:100,130s/src_str/dest_str/g
```

