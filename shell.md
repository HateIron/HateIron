# shell 专题

[TOC]

## 一、这里都是一个个独立的小例子

```powershell
[zhoujinhua@ prj] vi replace.sh

#显然 $# 表示参数的个数
if [ "$#" -lt "2" ];then
	echo 'error, please input src_str dst_str' 
	exit
fi

# $1 表示第一个参数
echo $1
echo $2

#先把包含关键字 $1 的文件打印出来
echo `grep -rn $1 ./ -rl`

# 所所有包含关键字 $1 的文件，里面的 $1 都替换成 $2
sed -i -e 's/$1/$2/g' `grep -rn $1 ./ -rl`

此脚本调用方法：
[zhoujinhua@ prj] ./replace.sh str_source str_dest
```



##二、`patsubst`函数的级联使用方法

```powershell
obj = $(patsubst %c,%o, $(patsubst %S, %.o, $(patsubst %s, %.o $(DIR))))

解释：
1、$(DIR) 为一个目录，是一个路径变量，其实展开后，可以是 *.c *.h *.s *.S ...
2、先执行第三个 patsubst ，将其中所有 *.s 变成 *.o
3、再执行第二个 patsubst ，将所有 *.S 变成 *.o
4、最后执行第一个patsubst，将所有 *.c 变成 *.o
```

##三、`echo -e`的作用,man帮助的解释是，允许后面的输出进行转义

```powershell
假设你是 echo -e "i will use \n $HOME" 输出的将是
i will use 
/root(当前用户的主目录)

如果是 echo "i will use \n $HOME" 则输出是：
i will use \n $HOME
```



##四、`tar`命令的使用

### 1、正常打包

```
tar -vcf ./abc.tar ./
```

### 2、排除某个目录打包

```powershell
tar -vcf ./abc.tar ./  --exclude=./dir1 --exclude=./dir2/release
注意：
是 --exclude=./dir1 而不是 --exclude=./dir1/
```









