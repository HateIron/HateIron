#<center>markdown</center>

[TOC]

#一、字体颜色、大小,只有转化为html才生效

##1、用法

```powershell
1、字体
<font face="黑体">我是黑体字</font>
<font face="微软雅黑">我是微软雅黑</font>
<font face="STCAIYUN">我是华文彩云</font>

2、颜色、大小、字体
<font color=#0099ff size=3 face="黑体" > color=#0099ff size=72 face="黑体"</font>

#0099ff --> 海蓝色
<font color="gray" size=10>灰色， size为6 </font>
```

## 2、常用字体

```powershell
<font face="黑体">我是黑体字</font><br/>
<font face="宋体">我是宋体字</font><br/>
<font face="微软雅黑">我是微软雅黑字</font><br/>
<font face="fantasy">我是fantasy字</font><br/>
<font face="Helvetica">我是Helvetica字</font><br/>
```

## 3、常用字体颜色

```powershell
浅红色文字：<font color="#dd0000">浅红色文字：</font><br /> 
深红色文字：<font color="#660000">深红色文字</font><br /> 
浅绿色文字：<font color="#00dd00">浅绿色文字</font><br /> 
深绿色文字：<font color="#006600">深绿色文字</font><br /> 
浅蓝色文字：<font color="#0000dd">浅蓝色文字</font><br /> 
深蓝色文字：<font color="#000066">深蓝色文字</font><br /> 
浅黄色文字：<font color="#dddd00">浅黄色文字</font><br /> 
深黄色文字：<font color="#666600">深黄色文字</font><br /> 
浅青色文字：<font color="#00dddd">浅青色文字</font><br /> 
深青色文字：<font color="#006666">深青色文字</font><br /> 
浅紫色文字：<font color="#dd00dd">浅紫色文字</font><br /> 
深紫色文字：<font color="#660066">深紫色文字</font><br /> 
```



# 二、背景颜色

```powershell
<table><tr><td bgcolor=#FF00FF>背景色的设置是按照十六进制颜色值：#7FFFD4</td></tr></table>

<table><tr><td bgcolor=#FF83FA>背景色的设置是按照十六进制颜色值：#FF83FA</td></tr></table>

<table><tr><td bgcolor=#D1EEEE>背景色的设置是按照十六进制颜色值：#D1EEEE</td></tr></table>

<table><tr><td bgcolor=#C0FF3E>背景色的设置是按照十六进制颜色值：#C0FF3E</td></tr></table>

<table><tr><td bgcolor=#54FF9F>背景色的设置是按照十六进制颜色值：#54FF9F</td></tr></table>
```



# 三、markdown 表格内换行

```powershell
可以用html的代码，插入代码<br>
```

# 四、分隔线

## 1、三个连续星号

`***`

效果：

---

## 2、三个连续减号，效果同星号

`---`

效果：

---

## 3、多个连续减号，效果同三个连续减号



# 五、段落缩进

## 1、三个带空格的星号，或者减号，或者`*`/`-`混用

`* * *`

效果：

* 一级

* * 二级标题

  * - - 四级标题
      - 四级内容

      三级内容

      - - - * * 多级标题内容

# 六、链接

## 1、行内式

```powershell
一、带 title 的链接
This is [an example](http://example.com/ "Title") inline link.

==》
<p>This is <a href="http://example.com/" title="Title">
an example</a> inline link.</p>

二、最普通常用的链接
[This link](http://example.net/) has no title attribute.
会产生如下代码
<p><a href="http://example.net/">This link</a> has no
title attribute.</p>
```

## 2、链接本机资源

```powershell
See my [About](/about/) page for details
```

## 3、链接文件内参考

```powershell
用法：
    This is [an example][id] reference-style link. 
或者多一个空格：
    This is [an example] [id] reference-style link.

而 id 的定义，可以在文件任意位置：
[id]: http://example.com/  "Optional Title Here"
 [id]: http://example.com/  "Optional Title Here"
  [id]: http://example.com/  "Optional Title Here"
   [id]: http://example.com/  "Optional Title Here" 前面最多可以加三个空格
   
以下三种格式略有不同，都是合法的：
[foo]: http://www.baidu.com/  "Optional Title Here"
[foo]: http://www.baidu.com/  'Optional Title Here'
[foo]: http://www.baidu.com/  (Optional Title Here)

点击 This is [an example][id] reference-style link. 的链接后，直接跳转到 http://www.baidu.com/
```



# 七、粗体

## 1、用`*`表示

*这是 \* 包围的字体*

_这是\_包围的字体_

# 八、图片

````
![pic_name](./picture_path)
````

# 九、 markdown 中的 `<iframe>`嵌套网页

```powershell
<iframe src="http://www.baidu.com/" width="700px" height="500px" frameboarder="0" scrolling="no"></iframe>

注意事项：
	网址中的所有 '&'  都要替换成 '&amp;'，
```

效果如下：

<iframe src="http://www.baidu.com/" width="700px" height="500px" frameboarder="0" scrolling="no"></iframe>



