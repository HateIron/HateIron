# C语言用例集

[TOC]

## 一、大小端判断

```c
int isBigEndian()
{
    short i = 1;
 	char *p = (char *)&i;
    return (*p == 1) ? __little : __big;
}
```



