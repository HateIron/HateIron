#<center>gtest</center>

[TOC]

## 一、 gtest 代码获取



## 二、更改gtest使用时的目录结构，不能把项目代码放在 gtest 里面

```powershell
将原来 gtest 目录中的用例全部删除。
也不再使用 gtest 自带的测试用例。如此一下，整个 gtest 框架代码变得极小
```





## 三、更改相应的 Makefile



## 四、应用

## 五、整合时编译出错

```powersh`ell
此时在 gtest Makefile 和 项目的 makefile 中，CXXFLAGS 增加两个参数
CXXFLAGS += -Bdynamic -lgcc_s
```



