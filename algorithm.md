#<center>algorithm</center>

[TOC]

## 一、hash 算法

###1、哈希表的概念及作用

这个网页说的很清楚：https://www.cnblogs.com/21dacia/articles/1403006.html

一、哈希表的概念及作用

> 一般的线性表，树中，记录在结构中的相对位置是随机的，即和记录的关键字之间不存在确定的关系，因此，在结构中查找记录时需进行一系列和关键字的比较。这一类查找方法建立在“比较“的基础上，查找的效率依赖于查找过程中所进行的比较次数。
>
> 理想的情况是能直接找到需要的记录，因此必须在记录的存储位置和它的关键字之间建立一个确定的对应关系f，使每个关键字和结构中一个唯一的存储位置相对应。
>
> 哈希表最常见的例子是以学生学号为关键字的成绩表，１号学生的记录位置在第一条，１０号学生的记录位置在第１０条...
>
> 如果我们以学生姓名为关键字，如何建立查找表，使得根据姓名可以直接找到相应记录呢？
>
> | a    | b    | c    | d    | e    | f    | g    | h    | i    | j    | k    | l    | m    | n    | o    | p    | q    | r    | s    | t    | u    | v    | w    | x    | y    | z    |
> | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
> | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   | 11   | 12   | 13   | 14   | 15   | 16   | 17   | 18   | 19   | 20   | 21   | 22   | 23   | 24   | 25   | 26   |
>
> |                                           | 刘丽 | 刘宏英 | 吴军 | 吴小艳 | 李秋梅 | 陈伟 | ...  |
> | ----------------------------------------- | ---- | ------ | ---- | ------ | ------ | ---- | ---- |
> | 姓名中各字拼音首字母                      | ll   | lhy    | wj   | wxy    | lqm    | cw   | ...  |
> | 用所有首字母编号值相加求和                | 24   | 46     | 33   | 72     | 42     | 26   | ...  |
> | 最小值可能为3 最大值可能为78 可放75个学生 |      |        |      |        |        |      |      |
>
> 
>
> 用上述得到的数值作为对应记录在表中的位置，得到下表：
>
> |      |        | 成绩一 | 成绩二... |
> | ---- | ------ | ------ | --------- |
> | 3    | ...    |        |           |
> | ...  | ...    |        |           |
> | 24   | 刘丽   | 82     | 95        |
> | 25   | ...    |        |           |
> | 26   | 陈伟   |        |           |
> | ...  | ...    |        |           |
> | 33   | 吴军   |        |           |
> | ...  | ...    |        |           |
> | 42   | 李秋梅 |        |           |
> | ...  | ...    |        |           |
> | 46   | 刘宏英 |        |           |
> | ...  | ...    |        |           |
> | 72   | 吴小艳 |        |           |
> | ...  | ...    |        |           |
> | 78   | ...    |        |           |
>
> 上面这张表即哈希表。
>
> 如果将来要查李秋梅的成绩，可以用上述方法求出该记录所在位置：
>
> 李秋梅:lqm 12+17+13=42 取表中第42条记录即可。
>
> 问题：如果两个同学分别叫 刘丽 刘兰 该如何处理这两条记录？
>
> 这个问题是哈希表不可避免的，即冲突现象：对不同的关键字可能得到同一哈希地址。

二、哈希表的构造方法

> １、直接定址法
>
> > 例如：有一个从1到100岁的人口数字统计表，其中，年龄作为关键字，哈希函数取关键字自身。
> >
> > | 地址 | 01   | 02   | ...  | 25   | 26   | 27   | ...  | 100  |
> > | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
> > | 年龄 | 1    | 2    | ...  | 25   | 26   | 27   | ...  | ...  |
> > | 人数 | 3000 | 2000 | ...  | 1050 | ...  | ...  | ...  | ...  |
> > | ...  |      |      |      |      |      |      |      |      |
>
> ２、数字分析法
>
> > 有学生的生日数据如下：
> >
> > 年.月.日
> >
> > 75.10.03
> > 75.11.23
> > 76.03.02
> > 76.07.12
> > 75.04.21
> > 76.02.15
> > ...
> >
> > 经分析,第一位，第二位，第三位重复的可能性大，取这三位造成冲突的机会增加，所以尽量不取前三位，取后三位比较好。
>
> ３、平方取中法
>
> > 取关键字平方后的中间几位为哈希地址。
>
> ４、折叠法
>
> > 将关键字分割成位数相同的几部分（最后一部分的位数可以不同），然后取这几部分的叠加和（舍去进位）作为哈希地址，这方法称为折叠法。
> >
> > 例如：每一种西文图书都有一个国际标准图书编号，它是一个10位的十进制数字，若要以它作关键字建立一个哈希表，当馆藏书种类不到10,000时，可采用此法构造一个四位数的哈希函数。如果一本书的编号为0-442-20586-4,则：
> >
> > |      | 5864        |      | 5864        |
> > | ---- | ----------- | ---- | ----------- |
> > |      | 4220        |      | 0224        |
> > | +)   | 04          | +)   | 04          |
> > |      | ----------- |      | ----------- |
> > |      | 10088       |      | 6092        |
> > |      | H(key)=0088 |      | H(key)=6092 |
> > |      |             |      |             |
> > |      | (a)移位叠加 |      | (b)间界叠加 |
>
> ５、除留余数法
>
> > 取关键字被某个不大于哈希表表长m的数p除后所得余数为哈希地址。
> >
> > H(key)=key MOD p (p<=m)
>
> ６、随机数法
>
> > 选择一个随机函数，取关键字的随机函数值为它的哈希地址，即
> >
> > H(key)=random(key) ,其中random为随机函数。通常用于关键字长度不等时采用此法



### 2、字符串哈希函数

​	字符串哈希函数，常用字符串哈希函数有 BKDRHash，APHash，DJBHash，JSHash，RSHash，SDBMHash，PJWHash，ELFHash等等。对于以上几种哈希函数，我对其进行了一个小小的评测，来源http://blog.csdn.net/wanglx_/article/details/40300363

| Hash函数 | 数据1 | 数据2 | 数据3 | 数据4 | 数据1得分 | 数据2得分 | 数据3得分 | 数据4得分 | 平均分 |
| -------- | ----- | ----- | ----- | ----- | --------- | --------- | --------- | --------- | ------ |
| BKDRHash | 2     | 0     | 4774  | 481   | 96.55     | 100       | 90.95     | 82.05     | 92.64  |
| APHash   | 2     | 3     | 4754  | 493   | 96.55     | 88.46     | 100       | 51.28     | 86.28  |
| DJBHash  | 2     | 2     | 4975  | 474   | 96.55     | 92.31     | 0         | 100       | 83.43  |
| JSHash   | 1     | 4     | 4761  | 506   | 100       | 84.62     | 96.83     | 17.95     | 81.94  |
| RSHash   | 1     | 0     | 4861  | 505   | 100       | 100       | 51.58     | 20.51     | 75.96  |
| SDBMHash | 3     | 2     | 4849  | 504   | 93.1      | 92.31     | 57.01     | 23.08     | 72.41  |
| PJWHash  | 30    | 26    | 4878  | 513   | 0         | 0         | 43.89     | 0         | 21.95  |
| ELFHash  | 30    | 26    | 4878  | 513   | 0         | 0         | 43.89     | 0         | 21.95  |

```c
unsigned int SDBMHash(char *str)  
{  
    unsigned int hash = 0;  
   
    while (*str)  
    {  
        // equivalent to: hash = 65599*hash + (*str++);  
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;  
    }  
   
    return (hash & 0x7FFFFFFF);  
}  
   
// RS Hash Function  
unsigned int RSHash(char *str)  
{  
    unsigned int b = 378551;  
    unsigned int a = 63689;  
    unsigned int hash = 0;  
   
    while (*str)  
    {  
        hash = hash * a + (*str++);  
        a *= b;  
    }  
   
    return (hash & 0x7FFFFFFF);  
}  
   
// JS Hash Function  
unsigned int JSHash(char *str)  
{  
    unsigned int hash = 1315423911;  
   
    while (*str)  
    {  
        hash ^= ((hash << 5) + (*str++) + (hash >> 2));  
    }  
   
    return (hash & 0x7FFFFFFF);  
}  
   
// P. J. Weinberger Hash Function  
unsigned int PJWHash(char *str)  
{  
    unsigned int BitsInUnignedInt = (unsigned int)(sizeof(unsigned int) * 8);  
    unsigned int ThreeQuarters    = (unsigned int)((BitsInUnignedInt  * 3) / 4);  
    unsigned int OneEighth        = (unsigned int)(BitsInUnignedInt / 8);  
    unsigned int HighBits         = (unsigned int)(0xFFFFFFFF) << (BitsInUnignedInt - OneEighth);  
    unsigned int hash             = 0;  
    unsigned int test             = 0;  
   
    while (*str)  
    {  
        hash = (hash << OneEighth) + (*str++);  
        if ((test = hash & HighBits) != 0)  
        {  
            hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));  
        }  
    }  
   
    return (hash & 0x7FFFFFFF);  
}  
   
// ELF Hash Function  
unsigned int ELFHash(char *str)  
{  
    unsigned int hash = 0;  
    unsigned int x    = 0;  
   
    while (*str)  
    {  
        hash = (hash << 4) + (*str++);  
        if ((x = hash & 0xF0000000L) != 0)  
        {  
            hash ^= (x >> 24);  
            hash &= ~x;  
        }  
    }  
   
    return (hash & 0x7FFFFFFF);  
}  
   
// BKDR Hash Function  
unsigned int BKDRHash(char *str)  
{  
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..  
    unsigned int hash = 0;  
   
    while (*str)  
    {  
        hash = hash * seed + (*str++);  
    }  
   
    return (hash & 0x7FFFFFFF);  
}
   
// DJB Hash Function  
unsigned int DJBHash(char *str)  
{  
    unsigned int hash = 5381;  
   
    while (*str)  
    {  
        hash += (hash << 5) + (*str++);  
    }  
   
    return (hash & 0x7FFFFFFF);  
}  
   
// AP Hash Function  
unsigned int APHash(char *str)  
{  
    unsigned int hash = 0;  
    int i;  
   
    for (i=0; *str; i++)  
    {  
        if ((i & 1) == 0)  
        {  
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));  
        }  
        else  
        {  
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));  
        }  
    }  
   
    return (hash & 0x7FFFFFFF);  
```





