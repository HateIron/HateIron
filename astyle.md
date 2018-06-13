# <center>astyle</center>

[TOC]

# 一、基础用法，对某单个文件操作

```powershell
# find ./ -name test.cpp | xargs astyle --style=ansi --indent=spaces=4 -S -m0 -Y -f -H -U -p
```

```powershell
# find ./ -name TestTCheckDetectArea.cpp | xargs astyle --style=ansi --indent=spaces=4 -S -m0 -Y -f -H -U -p
```

```powershell
# find ./ -name TestTCheckAlm.cpp | xargs astyle --style=ansi --indent=spaces=4 -S -m0 -Y -f -H -U -p
# find ./ -name '*.[c|h]' | xargs astyle --style=ansi --indent=spaces=4 -S -m0 -Y -f -H -U -p
# rm *.orig
```

# 二、只对目录中的`.c/.h`操作

```powershell
# find ../ -name '*.[c|h]' | grep -v ./gtest-1.7.0
```



