#<center>sed</center>

[TOC]

#一、将 Makefile 中的字符串 abc 替换成 efg

```shell
# sed -i -e 's/abc/efg/g' `find . -name Makefile`
```

对当前目录所有 .c 文件进行字符串替换

```powershell
# sed -i -e 's/src_string/dest_string/g' `grep -rl src_string ./`
```

#二、在 vim 中，对指定行数范围，采用 sed 替换

```shell
:100,130s/src_str/dest_str/g
```

