#<center>mockcpp</center>

[TOC]

#一、资源获取



file:///F:/git_prj/HateIron/2018-01/mockcpp-2.6.tar.gz



# 二、安装过程，及解决方法

```powershell
在没有启用 c++11新特性的编译器上，很顺利
tar -xf mockcpp-2.6.tar.gz
cmake .
make 
make install

在gcc-6.2.0上编译，则出现错误：
./mockcpp/incude/mockcpp/mockcpp.h:59:8 错误: expected unqualified-id before 'static_assert'

然后打开这个 mockcpp.h
将原来的 static_assert 定义注释掉，换一种写法：
#define EIGEN_STATIC_ASSERT(CONDITION,MSG)\
    {Eigen::internal::static_assertion<bool(CONDITION)>::MSG;}
    
#if 0
template <bool condition>
struct static_assert
{
  typedef int static_assert_failure[condition ? 1 : -1];
};
#endif
```

