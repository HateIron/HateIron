

#<center>代码覆盖率</center>

<span id='jump'></span>

[TOC]

## 一、Makefile 中要添加支持覆盖率的宏



## 二、编译生成目标文件后，一定要运行目标文件，才能生成相应数据

> ####目标文件执行之后，会生成相应的 *.gcno / *.gcda 等相关文件，覆盖率信息都包含在这些文件里。

## 三、利用 lcov 产生更加漂亮的呈现格式

```powershell
一段 python脚本实现：

def GatherLcovInfo2Web():
	#首先创建目标文件夹，是 nginx 服务器的一个目录，防止原来就有， -p 不用报错
	run_cmd（"mkdir -p /usr/local/nginx/html/prj_dir")
	#如果原来目录中有内容，全部将其删除
	run_cmd("rm /usr/local/nginx/html/prj_dir/* -rf")
	#运行编译好的程序，以便产生覆盖率信息
	rum_cmd("./run_obj_file")
	#用 lcov 产生prj.info, 要使用 -d 指明当前目录， -b 指明 base_dir。
	run_cmd("lcov -d ./ -c -o /usr/local/nginx/html/prj_dir/my_prj.info -t 'prj_title' -b ../")
	#删除不必要的模块，不把它们统计到覆盖率中，排除干扰，提高精确度
	run_cmd('lcov -r /usr/local/nginx/html/prj_dir/my_prj.info "/usr/include/*" "/usr/lib/*" "/usr/include/c++/4.8.2/*" "./test_case_frame/*" -o /usr/local/nginx/html/prj_dir/my_prj_filtered.info' )
	#利用过滤之后的 .info 文件生成 html 信息
	run_cmd( 'genhtml -o /usr/local/nginx/html/prj_dir/ /usr/local/nginx/html/prj_dir/my_prj_filtered.info')
```

## 四、采用 shell 脚本的写法更简单

```powershell
mkdir -p /usr/local/nginx/html/PrjLcovDir

rm /usr/local/nginx/html/PrjLcovDir/* -rf

lcov -b ../ -d ./ -c -o /usr/local/nginx/html/PrjLcovDir/Prj.info
lcov -r /usr/local/nginx/html/PrjLcovDir/Prj.info "/usr/include*" "/usr/lib/*" "/usr/incude/c++/4.8.2/*" "./test_case_frame/*" -o /usr/local/nginx/html/prj_dir/my_prj_filtered.info

genhtml -o /usr/local/nginx/html/prj_dir/ /usr/local/nginx/html/prj_dir/my_prj_filtered.info
```















