#<center>makefile</center>

[TOC]

##一、makefile 调试手段

### 1、`info` 打印

```shell
$(info, "here add the debug info")
```

###2、`warning`打印

```shell
$(warning, "here add the debug info")
```

### 3、`error`打印

```shell
$(error "error: this will stop the compile") ##可以停止当前 Makefile 的编译
```

### 4、`info`打印变量

```shell
$(info, $(TargetDevice))
```

### 5、`echo`增加调试信息

```shell
test : $(files) shared libdll
	@echo "start the compile of xxxxxx"
	@echo $(files)
	gcc -L/home/test_code -g -o0 -o test $(files) -lstdc++ -DMACRO=macroName -lshared
```

### 6、综合应用示例

```makefile
INCS = -I./include 
ifeq ($(OS), mingw)
    INCS += -I./serial/windows/include
endif

export INCS
$(info "incs = $(INCS)")
$(injfo "OS  = $(OS)")
```





## 二、支持多种语言的 Makefile 通用模板，更简洁

```shell 
export MAKE := make
export AS   := ${CROSS_TOOL}as
export LD   := ${CROOS_TOOL}ld
export CC   := ${CROOS_TOOL}gcc
export AR   := ${CROOS_TOOL}ar
export NM   := ${CROOS_TOOL}nm
export STRIP:= ${CROOS_TOOL}strip
export LD   := ${CROOS_TOOL}ld
export OBJCOPY := ${CROSS_TOOL}objcopy
export OBJDUMP := ${CROSS_TOOL}objdump

ifeq ($(system), linux)
	RM = rm -rf
else
	RM = del /a/f/s/q
fi

dest := prj_name
out  := debug
LIB  := ${out}/mylib.a

PWD= $(shell pwd)

SRC    = $(shell find $(PWD) -name '*.[c|s|S]')
_OBJ   = $(patsubst %.c,%.o, $(patsubst %.S,o, $(patsubst %.s,%.o,$SRC)))
__OBJ  = $(foreach obj, $(__OBJ), $(addprefix ${out}/,,${obj}))
INCLUDE= $(foreach inc, $(dir $(shell find ${PWD} -name '*.h')), -l${inc})

export CFLAGS := ${INCLUDE}
export LDFLAGS:= -static --enable-stdcall-fixup -lwsock32
export ARFLAGS:= -rcsu

all:${LIB}
	$(CC) ${CFLAGS} -c -o ${out}/${dest} ${LIB} ${LDFLAGS}
	
${LIB} : ${out}
	${AR} ${ARFLAGS} $@ $&

${OUT}/%.o : %.c
	${CC} ${CFLAGS} ${INC} $^ -c -o $@

${OUT}/%.o : %s
	${CC} ${CFLAGS} ${INC} $^ -c -o $@
	
${OUT}/%.o : %.S
	${CC} ${CFLAGS} ${INC} $^ -c -o $@
clean:
	@-${RM} ${out} ${dest} ${LIB}
```

## 三、Makefile 判断平台

###1、第一种写法，比较丑，不方便使用

```shell
OS_NAME=$(shell uname -o)
LocalOSName=$(shell echo $(OS_NAME) | tr '[A-Z]' '[a-z]')

$(info "LocalOSName : $(LocalOSName))

ifeq ($(findstring gnu/linux, $(LocalOSName)), gnu/linux) #如果从$(LocalOSName)中能找到 gnu/linux
	CXXFlags=-g3 -fprofile-arcs -ftest-coverage
	RM= rm -rf
else
	ifeq  ($(findstring Cygwin, $(LocalOSName)), Cygwin) #如果从$(LocalOSName)中能找到 Cygwin
		CXXFlags=-g3 -fprofile-arcs -ftest-coverage
		RM= rm -rf
	else
		# add other case
	endif
endif
```

### 2、第二种写法，条件语句漂亮许多,不用嵌套

```shell
OS_NAME=$(shell uname -o)
LocalOSName=$(shell echo $(OS_NAME) | tr '[A-Z]' '[a-z]')

$(info "LocalOSName : $(LocalOSName))

ifeq ($(findstring gnu/linux, $(LocalOSName)), gnu/linux) #如果从$(LocalOSName)中能找到 gnu/linux
	CXXFlags=-g3 -fprofile-arcs -ftest-coverage
	RM= rm -rf
else ifeq  ($(findstring Cygwin, $(LocalOSName)), Cygwin) #如果从$(LocalOSName)中能找到 Cygwin
	CXXFlags=-g3 -fprofile-arcs -ftest-coverage
	RM= rm -rf
else ifeq  ($(findstring msys, $(LocalOSName)), msys) #如果从$(LocalOSName)中能找到 msys
	# add msys case
else
	# add other case
endif
```



## 四、gtest Makefile 研究

## 五、另一种风格的通用 Makefile

## 六、一条语句编译项目

```shell
d:\prj> gcc -g -I../serial/include -I../../comm/include test_serial.c -o test_serial serial.a comm.a
```



## 七、`vpath`注意事项

```shell
# makefile 中
vpath %.c  ../module/source#尾部不能有任何东西，空格都不行
vpath %.c ../prj/source#尾部不能有任何东西，空格都不行
```



## 八、Makefile 中常用函数

**$(subst FROM,TO,TEXT)**

​         函数名称：字符串替换函数

​         函数功能：把字符串TEXT中的FROM字符串替换为TO

​         返回值：替换后的新字符串

​                   $(subst ee,EE,feet on the stree) //替换“feet on the street“中的ee为EE。结果得到字符串”fEEt on the strEEt”

**$(patsubst PATTERN,REPLACEMENT,TEXT)**

​         函数名称：模式替换函数

​         函数功能：搜索TEXT中以空格分开的单词，将符合模式PATTERN替换为REPLACEMENT。参数PATTERN中可以用模式通配符%来表示一个单词中的诺干字符。如果参数REPLACEMENT中也包含一个%，那么REPLACEMENT中的”%”将使PATTERN中的那个”%”所代表的字符串。而且只有第一个%作为模式字符来处理，之后出现的不再作为模式字符（作为一个字符）。转义字符可以避免%不作为为模式字符

​         返回值：替换后的新字符串

​         函数说明：参数TEXT单词之间的多个空格在处理时被合并为一个空格，并忽略前导和结尾空格

​                   $(patsubst %.c,%.o,x.c.c bar.c)

​                  替换以.o结尾的字符，函数的返回结果就为”x.c.o bar.o”

**$(strip STRING)**

​         函数名称：去空格函数

​         函数功能：去掉字符串STRING开头和结尾的空格，并将其中多个连续空字符合并为一个空字符

​         返回值：无前导和结尾空字符，使用单一空格分隔的多个单词的字符串

​         Strip函数常用语条件判断语句的表达式中，确保表达式比较可靠和健壮

**$(findstring FIND,IN)**

​         函数名称：查找字符串函数

​         函数功能：在字符串IN中查找FIND字符串

​         返回值：如果在IN中找到FIND子字符串，则返回FIND，否则返回空

​         函数说明：收索是严格的文本匹配

​                   $(findstring a,a b c)     返回 a

​                   $(findstring a,b c)       返回 空字符

**$(filter PATTERN…,TEXT)**

​         函数名称:过滤函数

​         函数功能：过滤掉字符串TEXT中所有不符合模式PATTERN的单词，保留所有符合此模式的单词。模式中一般需要包含字符%，存在多个模式时，模式之间用空格分隔

​         返回值：空格分隔的TEXT字符串中所有符合模式PATTERN的字符串

​         函数说明：filter可以用来去除一个变量中的某些字符串。

​                   source := foo.c bar.c baz.s ugh.h

​                   foo: $(source)

​                            cc $(filter %.c %s,$(source)) -o foo       此句话等于 cc foo.c bar.c baz.s -o foo 剔除掉了不符合.c,.s 的文件

**$(filter-out PATTERN…,TEXT)**

​         函数名称：反过滤函数

​         函数功能：和filter相反，剔除掉TEXT中所有符合模式PATTERN的单词

​         返回值：空格分隔的所有不符合模式PATTERN的字符串

​                   objects = main1.o foo.o main2.o bar.o

​                   mains = main1.o main2.o

​                   $(filter-out $(mains),$(objects))     去除了变量object中mains定义的字符串（文件名）的功能，返回”foo.o bar.o”

**$(sort LIST)**

​         函数名称：排序

​         函数功能：给字符串LIST中的单词以首字母为主进行排序，并去掉重复的单词

​         返回值：空格分隔的没有重复单词的字符串

​                   $(sort foo bar lose foo)

​                   返回值为”bar foo lose”    升序排，去掉重复单词

**$(word N,TEXT)**

​         函数名称：取单词函数

​         函数功能：取字符串TEXT中第N个单词(N的值从1开始)

​         返回值：返回字符串TEXT中第N个单词

​         函数说明：N大雨字符串TEXT中单词数目，返回空字符串。如果N为0，出错！！

​                   $(word 2,foo bar baz)        返回bar

**$(wordlist S,E,TEXT)**

​         函数名称：取字符串函数

​         函数功能：从字符串TEXT中去除从S开始到E打单词串。S和E表示单词在字符串中位置的数字

​         返回值：TEXT中从第S到E的单词串

​         函数说明：“S”和“E”都是从1开始的数字。当“S”比“TEXT”中的字数大时，返回空。如果“E”大于“TEXT”字数，返回从“S”开始，到“TEXT”结束的单词串。如果“S”大于“E”，返回空。

​                   $(wordlist 2,3,foo bar baz)   返回”bar baz”

**$(words TEXT)**

​         统计TEXT字符串的单词个数，返回值即为单词个数

​                   $(words,foo bar)  返回值为2.字符串TEXT最后一个单词就是$(word $(words TEXT),TEXT)

**$(firstword NAMES…)**

​         函数名称：取首单词函数

​         功能：取字符串“NAMES…“的第一个单词

​         返回值：返回NAMES的第一个单词

​                   $(firstword foo bar)

​                   返回值为foo。Firstword的实现功能等同于$(word 1,NAMES…)

​         下面我们来看一个实际应用：Makefile中可以使用VPATH来指定搜索路径。对于源代码所包含的头文件的搜索路径需要使用gcc的-l参数指定目录来实现。VPATH罗列的目录是用:分隔的

​         ……

​         VPATH = src:../includes

​         override CFLAGS += $(patsubst %,-l%,$(subst :, ,$(VPATH)))  à CFLAGS += -lsrc -l../includes

​         首先$(subst :, ,$(VPATH))将VPATH中的:用空格代替。$(patsubst %,-l%,src ../includes) 在patsubst函数中，模式和替换模式中都有%时，两个%表示同样的值。而模式直接使用%表示无论啥都匹配，全匹配

##九、Makefile 导出变量给 `sub-makefile`

```
http://www.gnu.org/savannah-checkouts/gnu/make/manual/html_node/Variables_002fRecursion.html#Variables_002fRecursion
```

> ### A、用自己的话来复述一遍要点
>
> #### 1、上层 makefile 可以显式的将变量传给 sub-makefile
>
> ```shell
> 在 sub-makefile 中，这些变量就是缺省值，但是不会覆盖 sub-makefile 中定义的的变量，除非加一了`-e` 选项。
> ```
>
> #### 2、makefile export 各种选项的定义
>
> ```shell
> `http://www.gnu.org/savannah-checkouts/gnu/make/manual/html_node/Options-Summary.html#Options-Summary`
> ```
>
> #### 3、要向下传递或者 export 一个变量，make 事先将变量添加到环境变量中。然后sub-make再使用环境变量来初始化它的变量
>
> ```shell
> 系统环境变量相关知识：
> `http://www.gnu.org/savannah-checkouts/gnu/make/manual/html_node/Environment.html#Environment`
> ```
>
> #### 4、一般情况下，make 不会导出`shell`变量，需强制导出
>
> ```shell
> `http://www.gnu.org/savannah-checkouts/gnu/make/manual/html_node/Choosing-the-Shell.html#Choosing-the-Shell`
> ```
>
> ####5、默认情况下，特殊变量`MAKEFLAGS`是导出的，除非`unexport it`
>
> 命令行变量也自动导出。被追加在`MAKEFLAGS`后面
>
> #### 6、make 自动产生的变量一般不会导出，因为sub-makefile也会自己定义
>
> ```shell
> 隐式变量的产生规则
> `http://www.gnu.org/savannah-checkouts/gnu/make/manual/html_node/Implicit-Variables.html#Implicit-Variables`
> ```
>
> ### B、正式开始
>
> ####1、导出变量的语法
>
> ```shell
> export variable ...
> ```
>
> #### 2、阻止导出
>
> ```shell
> unexport variable ...
> ```
>
> #### 3、简写方法
>
> ```shell
> export variable=value
>
> 等同于：
> variable=value
> export variable
> ```
>
> ```shell
> export variable:=value
>
> 等同于：
> variable:=value
> export variable
> ```
>
> ```
> export variable+=value
>
> 等同于：
> variable+=value
> export variable
> ```
>
> ```shell
> 更多的追加规则
> `http://www.gnu.org/savannah-checkouts/gnu/make/manual/html_node/Appending.html#Appending`
> ```
>
> #### 4、如果要导出全部变量
>
> ```shell
> export / unexport
> ```
>
> #### 5、特殊变量 `MAKELEVEL`会变，表示当前 makefile 的深度
>
> ```shell
> 从 0 开始，然后依次是 1， 然后是 2
> ```
>
> #### 6、Makefile 中的条件语句
>
> ```shell
> `http://www.gnu.org/savannah-checkouts/gnu/make/manual/html_node/Conditional-Example.html#Conditional-Example`
> ```
>
> 一个例子
>
> ```shell
> libs_for_gcc = -lgnu
> normal_libs =
>
> foo: $(objects)
> ifeq ($(CC),gcc)
>         $(CC) -o foo $(objects) $(libs_for_gcc)
> else
>         $(CC) -o foo $(objects) $(normal_libs)
> endif
> ```
>
> 等同于
>
> ```shell
> libs_for_gcc = -lgnu
> normal_libs =
>
> ifeq ($(CC),gcc)
>   libs=$(libs_for_gcc)
> else
>   libs=$(normal_libs)
> endif
>
> foo: $(objects)
>         $(CC) -o foo $(objects) $(libs)
> ```
>
> 

## 十、自动变量

```shell
`http://www.gnu.org/savannah-checkouts/gnu/make/manual/html_node/Automatic-Variables.html#Automatic-Variables`
```

```shell
对如下变量做了详细说明
$@  $% $< $? $^  $+  $|  $*  $(@D)  $(@F) $(*D) $(%D) $(%F) $(<D) $(<F) $(+D) $(+F) $(?D)  $(?F)
```

##十一、报错:`"时钟错误的问题"`

```shell
# 工程 make 时出现"时钟错误的问题"解决方案
# 先 ls -l 查看日期不正确的文件
# 然后 touch 之，或者
find ./ -type f | xargs touch
```

## 十二、 'patsubst'讲解



##十三、`Makefile`级联

```makefile
CurrDir=$(shell pwd)
IndependentModuleDir=$(CurrDir)

SUBDIRS=${IndependentModuleDir}/prj1  \
        ${IndependentModuleDir}/prj2  \
        ${IndependentModuleDir}/prj3  \
        ${IndependentModuleDir}/prj4
 
 LibDir = ${IndependentModuleDir}/../libs
 
 all:
 	@list='$(SUBDIRS);' \
 	for subdir in $$list; do \
 		echo "Clean before make in $$subdir"; \
 		(cd $$subdir && rm Debug rf);
 	done; \
 	for subdir in $$list; do \
 		echo "now is making $$subdir"; \
 		(cd $$subdir && mkdir Debug && make -j4); \
 		done;

.PHONY: clean
clean:
	@list='$(SUBDIR)'; \
	for subdir in $$list; do \
		echo "clean in $$subdir"; \
		(cd $$subdir && rm Debug -rf); \
	done; \
	cd ${LibDir} && rm *.a -rf
```

## 十四、项目中使用独立模块

```powershell
目录结构：
PrjDir
|
|---source
|     |---file_1.c
|     |---file_2.c
|     |---file_3.c
|
|---include
|     |---file_1.h
|     |---file_2.h
|     |---file_3.h
|
|---unittest
|     |---case
|     |    |---case1.cpp
|     |    |---case2.cpp
|     |    |---case3.cpp
|     |
|     |---stub
|     |    |---source
|     |    |     |---stub.c
|     |    |     |---main.c
|     |    |
|     |    |---include
|     |          |---stub.h
|     | 
|     |---stub
|          |---source
|                |---stub.c
|                |---main.c
| 
| ---independModule
      |---libs
           |---module_1.a
           |---module_2.a

还有独立提供的模块 include 目录
```



```makefile
GTEST_DIR = ./independentModule/gtest_1.7.0
CXX = gcc
LD  = g++

CXXFLAGS += -g3

#ifdef AAA
	CXXFLAGS += -D_INSTALL_AAA_MACRO
#endif

#ifdef BBB
	CXXFLAGS += -D_INSTALL_BBB_MACRO
#endif

CXXFLAGS += -D_INSTALL_SOME_MACRO
CXXFLAGS += -fprofile-arcs -ftest-coverage #支持 gcov 
CXXFLAGS += -gdwarf-2 -Bdynami -lgcc_s

OS_NAME = $(shell uname -o)

Local_OS_Name = $(shell echo $(OS_NAME) | tr '[A-Z]' '[a-z]')
SED_TOOL = 
RM_TOOL  = 
RM_CMD   =

# find keyword "linux"
ifeq ($(findstring gnu/linux, $(Local_OS_Name)), gnu/linux)
	SED_TOOL = sed
	RM_TOOL  = rm
	RM_CMD   = rm -rf
elif ($(findstring cygwin, $(Local_OS_Name)), cygwin)
	SED_TOOL = sed
	RM_TOOL  = rm
	RM_CMD   = rm -rf
else
	SED_TOOL = c:/MINGW/msys/10/bin/sed
	RM_TOOL  = c:/MINGW/msys/10/bin/rm
    RM_CMD   = del /q/f
endif

LDFLAGS = -o
OBJ_DIR = ./Debug
LIT_DIR = ./libs
LIBS    = -lgcov -lpthread
LIBS   += -ftest-coverage
PrjDir  = ..

INCS    = -I./stub/include  \
		 -I./independentModule/module_1/include \
		 -I./independentModule/module_2/include \
		 -I./independentModule/module_3/include \
		 ...
		 -I./independentModule/module_n/include \
		 -I$(GTEST_DIR)/include                 \
		 -I$(GTEST_DIR)/include/gtest           \
		 -I$(GTEST_DIR)/include/gtest/internal  \
		 -I$(PrjDir)/include
		 
vpath  %.c    $(PrjDir)/unittest/stub/source
vpath  %.c    $(PrjDir)/source
vpath  %.cpp  $(PrjDir)/unittest/stub/source
vpath  %.cpp  $(PrjDir)/unittest/case

#生成目标文件，即可执行文件
EXE_NAME = ut

SRC = $(notdir $(wildcard $(PrjDir)/source/file_1.c))    \
	  $(notdir $(wildcard $(PrjDir)/source/file_2.c))    \
	  $(notdir $(wildcard $(PrjDir)/source/file_3.c))    \
	  ......
	  $(notdir $(wildcard $(PrjDir)/source/file_n.c))    \
	  $(notdir $(wildcard $(PrjDir)/unittest/stub/source/*.c)) 
SRCC =$(notdir $(wildcard  $(PrjDir)/unittest/stub/source/*.cpp))  \
	  $(notdir $(wildcard  $(PrjDir)/unittest/case/*.cpp))

# 将全部 .c 替换得到 .o
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o, $(SRC)) \
	   $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCC))
#等同写法如下：
# OBJS = $(SRC:%.c=$(OBJ_DIR)/%.O) $(SRCC:%.cpp=$(OBJ_DIR)/%.O)

DEPENDENT := $(SRC:%.C=$(OBJ_DIR)/%.c.d) \
			$(SRCC:%.cpp=$(OBJ_DIR)/%.cpp.d)
# 此段同样可采用 $(patsubst) 来实现
A_Modules = $(wildcard $(LIB_DIR)/%.a)

all: ${EXE_NAME}

${EXE_NAME}: {OBJS}
	${LD} ${LD_FLAGS} $@ ${OBJS} ${A_Modules} ${LIBS}
	
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	${LD} -c ${CXXFLAGS} ${INCS} $< -o $@

$(OBJ_DIR)/%.o : %c | $(OBJ_DIR)
	${LD} -c ${CXXFLAGS} ${INCS} $< -o $@

#注释：这一段代码极难理解，主要是不常接触
# 一、 $(CXX) -MM ${CXXFLAGS} ${INCS} $< > $@.$$$$; 
#	  这行的作用，-MM把编译时包含的头文件细节保存到 $@.$$$$ 中，即 aa.c.d.1234 中，$@表示目标文件，即文件名 .c.d, .$$$$表示四个数字，这是个临时文件
# 二、  $(SED_TOOL) 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; 
#     这一行更难理解。首先，把 $@.$$$$  的内容，通过重管道读到内存，然后通过 sed 工具，对其内容进行正则表达式处理，将文本中的 （等验证）等内容变成 "a.cd : " 字样
# 三、$(RM_TOOL) -f $@.$$$$ 删除中间文件
$(OBJ_DIR)/%.c.d : %c | $(OBJ_DIR)
	$(CXX) -MM ${CXXFLAGS} ${INCS} $< > $@.$$$$;  \
	$(SED_TOOL) 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;  \
	$(RM_TOOL) -f $@.$$$$
	
$(OBJ_DIR)/%.cpp.d : %cpp | $(OBJ_DIR)
	$(CXX) -MM ${CXXFLAGS} ${INCS} $< > $@.$$$$;  \
	$(SED_TOOL) 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;  \
	$(RM_TOOL) -f $@.$$$$
	
ifneq "$(MAKECMDGOALS)" "clean"
sinclude ${DEPEND}
endif

.PHONY: clean
	@$(RM_CMD) $(OBJ_DIR)/* -rf
	
.PHONY: show_os
	echo $(findstring gnu/linux $(Local_OS_Name))
```









