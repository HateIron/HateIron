#<center>http & html</center>

[TOC]

# 一、网页怎样添加在手机中自动横屏支持

```powershell
需要 css3 中的一个属性 transform:rotate，但是此属性 ie9 以下版本不支持
```

示例代码，不过是写死的，大不了在页面加一个按钮，手动横屏：

```powershell
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title></title>
<meta name="Keywords" content="">
<meta name="Description" content="">
</head>
<body style="width:700px;
             height:800px;
             transform:rotate(90deg);
             -ms-transform:rotate(90deg);
             -moz-transform:rotate(90deg);
             -webkit-transform:rotate(90deg);">

<div id="aa">
html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码html 横屏显示的代码
</div>
</body>
</html>
```

# <font style="text-align:center">runoob 网站手抄</font>

## 一、网页编码问题.

> 对于中文网页。需要增加语句 `<meta charset="utf-8">`指明编码。但是某些浏览器需要` <meta charset="gbk">`，如360浏览器

```powershell
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>菜鸟教程(runoob.com)</title>
    </head>
    <body>
        <h1>我的第一个标题</h1>
        <p>我的第一个段落。</p>
    </body>
</html>
```

##二、通用声明

### HTML5

`<!DOCTYPE html>`

### HTML 4.01

```
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
```

### XHTML 1.0

```
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
```

## 文本格式化

### 粗体`<b>`、`<strong>`

```powershell
两者效果相同
<b>这个文本是加粗的</b>
<strong>这个文本是加粗的</strong>
```

### 斜体`<em>`、`<i>`

```powershell
两者效果相同
<em>这个文本是斜体的</em>
<i>这个文本是斜体的</i>
```

### 放大字体`<big>`

```powershell
<big>这个文本字体放大</big>
```

###缩小字体`<small>`

```powershell
<small>这个文本是缩小的</small>
```

### 上/下标`<sub>`、`<sup>`

```powershell
这个文本包含<sub>下标</sub>
这个文本包含<sup>上标</sup>
```

### pre格式化`<pre>`

```powershell
<pre>
此例演示如何使用 pre 标签
对空行和    空格
进行控制
</pre>
```

### 计算机输出`<code>`、`<kbd>`、`<tt>`、`<var>`

```powershell
<code>计算机输出</code>
<kbd>键盘输入</kbd>
<tt>打字机文本</tt>
<var>计算机变量</var>
```

### 缩写和首字母缩写`<abbr>`、`<acronym>`

```powershell
两者效果相同，把鼠标移到简略内容上，会弹出 title 指定的详细信息：
<abbr title="etcetera">etc.</abbr>
<acronym title="World Wide Web">WWW</acronym>
```

### 文字方向`<bdo>`

```html
<p>该段落文字从左到右显示。</p>  
<p><bdo dir="rtl">该段落文字从右到左显示。</bdo></p>  
```

### 块引用`<q>`

```powershell
源代码：
<p>WWF's goal is to: 
<q>Build a future where people live in harmony with nature.</q>
We hope they succeed.</p>

效果(两个 q 变成了双引号)：
WWF's goal is to: "Build a future where people live in harmony with nature". We hope they succeed.
```

### 字体删除效果和插入效果`<del>`、`<ins>`

```html
源码：
	<p>My favorite color is <del>blue</del> <ins>red</ins>!</p>
```

<p>My favorite color is <del>blue</del> <ins>red</ins>!</p>

## head

 ### `<title>` 标签定义了不同文档的标题。 

###`<base>`标签 

> `<base>`标签描述了基本的链接地址/链接目标,`该标签作为HTML文档中所有的链接标签的默认链接:`
>
> ```html
> <head>
> 	<base href="http://www.runoob.com/images/" target="_blank">
> </head>
> ```

###` <link> 元素`

> `<link> `标签定义了文档与外部资源之间的关系。
>
> `<link>` 标签通常用于链接到样式表
>
> ```html
> <head>
> 	<link rel="stylesheet" type="text/css" href="mystyle.css">
> </head>
> ```

###`<style> 元素`

> `<style>` 标签定义了HTML文档的样式文件引用地址.
>
> 在`<style>` 元素中你也可以直接添加样式来渲染 HTML 文档:
>
> ```html
> <head>
>     <style type="text/css">
>         body {background-color:yellow}
>         p {color:blue}
>     </style>
> </head>
> ```

###`<meta> 元素`

>meta 标签描述了一些基本的元数据。
>
>`<meta>` 标签提供了元数据.元数据也不显示在页面上，但会被浏览器解析。
>
>`META` 元素通常用于指定网页的描述，关键词，文件的最后修改时间，作者，和其他元数据。
>
>元数据可以使用于浏览器（如何显示内容或重新加载页面），搜索引擎（关键词），或其他Web服务。
>
>`<meta>` 一般放置于 `<head>`区域
>
>#### 为搜索引擎定义关键词: 
>
>```html
><meta name="keywords" content="HTML, CSS, XML, XHTML, JavaScript">
>```
>
>####为网页定义描述内容 :
>
>```html
><meta name="description" content="免费 Web & 编程 教程">
>```
>
>#### 定义网页作者: 
>
>````html
><meta name="author" content="Runoob">
>````
>
>#### 每30秒钟刷新当前页面: 
>
>```html
><meta http-equiv="refresh" content="30">
>```

##`html css`

### 第一个完整简单用例，将`<h1>`标红，将`<p>`标蓝

> 源码：
>
> ```html
> <!DOCTYPE html>
> <html>
>     <head>
>         <meta charset="utf-8"> 
>         <title>菜鸟教程(runoob.com)</title>
>         <style type="text/css">
>             h1 {color:red;}
>             p {color:blue;}
>         </style>
>     </head>
> 
>     <body>
>         <h1>这是一个标题</h1>
>         <p>这是一个段落。</p>
>     </body>
> </html>
> ```

### 一个没有下标线的链接`"text-decoration:none;"`

> ```html
> <!DOCTYPE html>
> <html>
>     <head> 
>         <meta charset="utf-8"> 
>         <title>菜鸟教程(runoob.com)</title> 
>     </head>
>     <body>
>     	<a href="http://www.runoob.com/" style="text-decoration:none;">访问 runoob.com!</a>
>     </body>
> </html>
> ```

### 使用外部样式表

`<link rel="stylesheet" type="text/css" href="styles.css">`

> ```html
> <!DOCTYPE html>
> <html>
>     <head>
>         <meta charset="utf-8"> 
>         <title>菜鸟教程(runoob.com)</title> 
>         <link rel="stylesheet" type="text/css" href="styles.css">
>     </head>
> 
>     <body>
>         <h1>我使用了外部样式文件来格式化文本 </h1>
>         <p>我也是!</p>
>     </body>
> </html>
> ```

### 如何使用 CSS

- 内联样式--------------- 在HTML元素中使用"style" **属性**

```HTML
<p style="color:blue;margin-left:20px;">This is a paragraph.</p>
<p style="font-family:arial;color:red;font-size:20px;">一个段落。</p>
<h1 style="text-align:center;">居中对齐的标题</h1>
```

<p style="color:blue;margin-left:20px;">This is a paragraph.</p> 

<p style="font-family:arial;color:red;font-size:20px;">一个段落。</p> 

<h1 style="text-align:center;">居中对齐的标题</h1> 

- 内部样式表 ----------- 在HTML文档头部 `<head>` 区域使用`<style>` **元素** 来包含CSS

```html
<head>
    <style type="text/css">
        body {background-color:yellow;}
        p {color:blue;}
    </style>
</head>
```

- 外部引用 -------------- 使用外部 CSS **文件**

```html
<head>
	<link rel="stylesheet" type="text/css" href="mystyle.css">
</head>
```

## html 图像

### 最简单插入图像

```html
<img src="smiley.gif" alt="Smiley face" width="32" height="32"></p>
```

<div><img src="smiley.gif" alt="picture load failed,Smiley face" width="32" height="32"></p></div>

### 图像排列(`float 属性`)

```html
<p>
	<img src="smiley.gif" alt="Smiley face" style="float:left" width="32" height="32"> 一个带图片的段落，图片浮动在这个文本的左边。
</p>

<p>
	<img src="smiley.gif" alt="Smiley face" style="float:right" width="32" height="32"> 一个带图片的段落，图片浮动在这个文本的右边。
</p>
```

### 图像链接

```html
<p>创建图片链接:
    <a href="http://www.runoob.com/html/html-tutorial.html">
        <img  border="10" src="smiley.gif" alt="HTML 教程" width="32" height="32">
    </a>
</p>

<p>无边框的图片链接:
    <a href="http://www.runoob.com/html/html-tutorial.html">
		<img border="0" src="smiley.gif" alt="HTML 教程" width="32" height="32">
    </a>
</p>
```

### 图像映射(`map关键字`)

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>菜鸟教程(runoob.com)</title>
    </head>
    <body>
        <p>点击太阳或其他行星，注意变化：</p>
        <img src="planets.gif" width="145" height="126" alt="Planets" usemap="#planetmap">

        <map name="planetmap">
          <area shape="rect"   coords="0,0,82,126" alt="Sun"     href="sun.htm">
          <area shape="circle" coords="90,58,3"    alt="Mercury" href="mercur.htm">
          <area shape="circle" coords="124,58,8"   alt="Venus"   href="venus.htm">
        </map>

    </body>
</html>
```

### 表格

### 最基础表格

```html
<table border="1">
    <tr>
        <td>row 1, cell 1</td>
        <td>row 1, cell 2</td>
    </tr>
    <tr>
        <td>row 2, cell 1</td>
        <td>row 2, cell 2</td>
    </tr>
</table>
```

<div>

<table border="1"><br/><tr> <br/><td>row 1, cell 1</td> <br/><td>row 1, cell 2</td><br/> </tr><br/> <tr> <br/><td>row 2, cell 1</td><br/><td>row 2, cell 2</td><br/></tr><br/> </table> 

</div>

### 没有边框的表格

```html
<!DOCTYPE html>
<html>
    <head> 
        <meta charset="utf-8"> 
        <title>菜鸟教程(runoob.com)</title> 
    </head>
    
    <body>
        <h4>这个表格没有边框:</h4>
        <table>
            <tr>
              <td>100</td>
              <td>200</td>
              <td>300</td>
            </tr>
            <tr>
              <td>400</td>
              <td>500</td>
              <td>600</td>
            </tr>
        </table>

        <h4>这个表格没有边框:</h4>
        <table border="0">
            <tr>
              <td>100</td>
              <td>200</td>
              <td>300</td>
            </tr>
            <tr>
              <td>400</td>
              <td>500</td>
              <td>600</td>
            </tr>
        </table>
    </body>
</html>	
```

<body>

<p>这个表格没有边框:</p>
<table border="0">
<tr>
  <td>100</td>
  <td>200</td>
  <td>300</td>
</tr>
<tr>
  <td>400</td>
  <td>500</td>
  <td>600</td>
</tr>
</table>

<p>这个表格有边框:</p>
<table border="20">
<tr>
  <td>100</td>
  <td>200</td>
  <td>300</td>
</tr>
<tr>
  <td>400</td>
  <td>500</td>
  <td>600</td>
</tr>
</table>

</body>

### 表头`<th>`

```html
<!DOCTYPE html>
<html>
    <head> 
        <meta charset="utf-8"> 
        <title>菜鸟教程(runoob.com)</title> 
    </head>
    
    <body>
    <h4>水平标题:</h4>
    <table border="1">
    <tr>
      <th>Name</th>
      <th>Telephone</th>
      <th>Telephone</th>
    </tr>
    <tr>
      <td>Bill Gates</td>
      <td>555 77 854</td>
      <td>555 77 855</td>
    </tr>
    </table>

    <h4>垂直标题:</h4>
    <table border="1">
    <tr>
      <th>First Name:</th>
      <td>Bill Gates</td>
    </tr>
    <tr>
      <th>Telephone:</th>
      <td>555 77 854</td>
    </tr>
    <tr>
      <th>Telephone:</th>
      <td>555 77 855</td>
    </tr>
    </table>
    </body>
</html>
```

<h4>水平标题:</h4>
    <table border="1">
    <tr>
    <th>Name</th>
      <th>Telephone</th>
      <th>Telephone</th>
    </tr>
    <tr>
      <td>Bill Gates</td>
      <td>555 77 854</td>
      <td>555 77 855</td>
    </tr>
    </table>
<h4>垂直标题:</h4>
    <table border="1">
    <tr>
      <th>First Name:</th>
      <td>Bill Gates</td>
    </tr>
    <tr>
      <th>Telephone:</th>
      <td>555 77 854</td>
    </tr>
    <tr>
      <th>Telephone:</th>
      <td>555 77 855</td>
    </tr>
    </table>

### 表格的标题`<caption>`

```html
<!DOCTYPE html>
<html>
    <head> 
        <meta charset="utf-8"> 
        <title>菜鸟教程(runoob.com)</title> 
    </head>
    
    <body>
        <table border="1">
          <caption>Monthly savings</caption>
          <tr>
            <th>Month</th>
            <th>Savings</th>
          </tr>
          <tr>
            <td>January</td>
            <td>$100</td>
          </tr>
          <tr>
            <td>February</td>
            <td>$50</td>
          </tr>
        </table>
    </body>
</html>
```

<table border="1">
          <caption>Monthly savings</caption>
          <tr>
            <th>Month</th>
            <th>Savings</th>
          </tr>
          <tr>
            <td>January</td>
            <td>$100</td>
          </tr>
          <tr>
            <td>February</td>
            <td>$50</td>
          </tr>
        </table>

### 跨行或者跨列的单元格`<th colspan>跨列`、`<th rowspan>跨行`

```html
<!DOCTYPE html>
<html>
    <head> 
        <meta charset="utf-8"> 
        <title>菜鸟教程(runoob.com)</title> 
    </head>
    
    <body>
    <h4>单元格跨两格:</h4>
    <table border="1">
        <tr>
          <th>Name</th>
          <th colspan="2">Telephone</th>
        </tr>
        <tr>
          <td>Bill Gates</td>
          <td>555 77 854</td>
          <td>555 77 855</td>
        </tr>
    </table>

    <h4>单元格跨两列:</h4>
    <table border="1">
        <tr>
          <th>First Name:</th>
          <td>Bill Gates</td>
        </tr>
        <tr>
          <th rowspan="2">Telephone:</th>
          <td>555 77 854</td>
        </tr>
        <tr>
          <td>555 77 855</td>
        </tr>
    </table>

    </body>
</html>
```

<div>
<h4>单元格跨两列:</h4>
<table border="1">
<tr>
<th>Name</th>
<th colspan="2">Telephone</th>
</tr>
<tr>
<td>Bill Gates</td>
<td>555 77 854</td>
<td>555 77 855</td>
</tr>
</table>

<h4>单元格跨两行:</h4>
<table border="1">
<tr>
<th>First Name:</th>
<td>Bill Gates</td>
</tr>
<tr>
<th rowspan="2">Telephone:</th>
<td>555 77 854</td>
</tr>
<tr>
<td>555 77 855</td>
</tr>
</table>
</div>

### 单元格边距`<table border="1" cellpadding="10">`

```html
<!DOCTYPE html>
<html>
    <head> 
        <meta charset="utf-8"> 
        <title>菜鸟教程(runoob.com)</title> 
    </head>
    
    <body>
        <h4>没有单元格边距:</h4>
        <table border="1">
            <tr>
              <td>First</td>
              <td>Row</td>
            </tr>   
            <tr>
              <td>Second</td>
              <td>Row</td>
            </tr>
        </table>

        <h4>有单元格边距:</h4>
        <table border="1" cellpadding="10">
        <tr>
          <td>First</td>
          <td>Row</td>
        </tr>   
        <tr>
          <td>Second</td>
          <td>Row</td>
        </tr>
        </table>
    </body>
</html>
```

<h4>没有单元格边距:</h4>
<table border="1">
            <tr>
              <td>First</td>
              <td>Row</td>
            </tr>   
            <tr>
              <td>Second</td>
              <td>Row</td>
            </tr>
        </table>

<h4>有单元格边距:&lt;table border="1" cellpadding="20"&gt;用markdown编辑转化效果不明显</h4>
<table border="1" cellpadding="20">
        <tr>
          <td>First</td>
          <td>Row</td>
        </tr>  

​        <tr>
          <td>Second</td>
          <td>Row</td>
        </tr>
        </table>

### 单元格间距

```html
<!DOCTYPE html>
<html>
    <head> 
        <meta charset="utf-8"> 
        <title>菜鸟教程(runoob.com)</title> 
    </head>
    
    <body>
    <h4>没有单元格间距:</h4>
    <table border="1">
        <tr>
          <td>First</td>
          <td>Row</td>
        </tr>
        <tr>
          <td>Second</td>
          <td>Row</td>
        </tr>
    </table>

    <h4>单元格间距="0":</h4>
    <table border="1" cellspacing="0">
        <tr>
          <td>First</td>
          <td>Row</td>
        </tr>
        <tr>
          <td>Second</td>
          <td>Row</td>
        </tr>
    </table>

    <h4>单元格间距="10":</h4>
    <table border="1" cellspacing="10">
        <tr>
          <td>First</td>
          <td>Row</td>
        </tr>
        <tr>
          <td>Second</td>
          <td>Row</td>
        </tr>
    </table>
    </body>
</html>
```

<h4>没有单元格间距:</h4>
<table border="1">
        <tr>
          <td>First</td>
          <td>Row</td>
        </tr>
        <tr>
          <td>Second</td>
          <td>Row</td>
        </tr>
    </table>
    
<h4>单元格间距="0":&lt;table border="1" cellspacing="0"&gt;</h4>
<table border="1" cellspacing="0">
        <tr>
          <td>First</td>
          <td>Row</td>
        </tr>
        <tr>
          <td>Second</td>
          <td>Row</td>
        </tr>
    </table>
    
<h4>单元格间距="10":&lt;table border="1" cellspacing="10"&gt;</h4>
<table border="1" cellspacing="10">
        <tr>
          <td>First</td>
          <td>Row</td>
        </tr>
        <tr>
          <td>Second</td>
          <td>Row</td>
        </tr>
    </table>

### 表格列组标签`<col span="2" style="background-color:red">`

```powershell
<table border="1">
  <colgroup>
    <col span="2" style="background-color:red">
    <col style="background-color:yellow">
  </colgroup>
  <tr>
    <th>ISBN</th>
    <th>Title</th>
    <th>Price</th>
  </tr>
  <tr>
    <td>3476896</td>
    <td>My first HTML</td>
    <td>$53</td>
  </tr>
  <tr>
    <td>5869207</td>
    <td>My first CSS</td>
    <td>$49</td>
  </tr>
</table>
```

<table border="1">
  <colgroup>
    <col span="2" style="background-color:red">
    <col style="background-color:yellow">
  </colgroup>
  <tr>
    <th>ISBN</th>
    <th>Title</th>
    <th>Price</th>
  </tr>
  <tr>
    <td>3476896</td>
    <td>My first HTML</td>
    <td>$53</td>
  </tr>
  <tr>
    <td>5869207</td>
    <td>My first CSS</td>
    <td>$49</td>
  </tr>
</table>

### 一个漂亮的表格

```html
<style type="text/css">
@charset "utf-8";
/* CSS Document */
.tabtop13 {
	margin-top: 13px;
}
.tabtop13 td{
	background-color:#ffffff;
	height:25px;
	line-height:150%;
}
.font-center{ text-align:center}
.btbg{background:#e9faff !important;}
.btbg1{background:#f2fbfe !important;}
.btbg2{background:#f3f3f3 !important;}
.biaoti{
	font-family: 微软雅黑;
	font-size: 26px;
	font-weight: bold;
	border-bottom:1px dashed #CCCCCC;
	color: #255e95;
}
.titfont {
	
	font-family: 微软雅黑;
	font-size: 16px;
	font-weight: bold;
	color: #255e95;
	background: url(../images/ico3.gif) no-repeat 15px center;
	background-color:#e9faff;
}
.tabtxt2 {
	font-family: 微软雅黑;
	font-size: 14px;
	font-weight: bold;
	text-align: right;
	padding-right: 10px;
	color:#327cd1;
}
.tabtxt3 {
	font-family: 微软雅黑;
	font-size: 14px;
	padding-left: 15px;
	color: #000;
	margin-top: 10px;
	margin-bottom: 10px;
	line-height: 20px;
}
</style>
<!-- html  html  html  html  html  html  html  html  html  html  html -->
<table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
  <tr>
    <td align="center" class="biaoti" height="60">受理员业务统计表</td>
  </tr>
  <tr>
    <td align="right" height="25">2017-01-02---2017-05-02</td>
  </tr>
</table>

<table width="100%" border="0" cellspacing="1" cellpadding="4" bgcolor="#cccccc" class="tabtop13" align="center">
  <tr>
    <td colspan="2" class="btbg font-center titfont" rowspan="2">受理员</td>
    <td width="10%" class="btbg font-center titfont" rowspan="2">受理数</td>
    <td width="10%" class="btbg font-center titfont" rowspan="2">自办数</td>
    <td width="10%" class="btbg font-center titfont" rowspan="2">直接解答</td>
    <td colspan="2" class="btbg font-center titfont">拟办意见</td>
    <td colspan="2" class="btbg font-center titfont">返回修改</td>
    <td colspan="3" class="btbg font-center titfont">工单类型</td>
  </tr>
  <tr>
    <td width="8%" class="btbg font-center">同意</td>
    <td width="8%" class="btbg font-center">比例</td>
    <td width="8%" class="btbg font-center">数量</td>
    <td width="8%" class="btbg font-center">比例</td>
    <td width="8%" class="btbg font-center">建议件</td>
    <td width="8%" class="btbg font-center">诉求件</td>
    <td width="8%" class="btbg font-center">咨询件</td>
  </tr>
  <tr>
    <td width="7%" rowspan="8" class="btbg1 font-center">受理处</td>
    <td width="7%"  class="btbg2">王艳</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2 font-center">总计</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
  </tr>
  <tr>
    <td width="7%" rowspan="8" class="btbg1 font-center">话务组</td>
    <td width="7%"  class="btbg2">王艳</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">王艳</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">王艳</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">王艳</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
   <tr>
    <td class="btbg2 font-center">总计</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
  </tr>
</table>
```

<style type="text/css">
@charset "utf-8";
/* CSS Document */
.tabtop13 {
	margin-top: 13px;
}
.tabtop13 td{
	background-color:#ffffff;
	height:25px;
	line-height:150%;
}
.font-center{ text-align:center}
.btbg{background:#e9faff !important;}
.btbg1{background:#f2fbfe !important;}
.btbg2{background:#f3f3f3 !important;}
.biaoti{
	font-family: 微软雅黑;
	font-size: 26px;
    font-weight: bold;
	border-bottom:1px dashed #CCCCCC;
	color: #255e95;
}
.titfont {
	font-family: 微软雅黑;
	font-size: 16px;
	font-weight: bold;
	color: #255e95;
	background: url(../images/ico3.gif) no-repeat 15px center;
	background-color:#e9faff;
}
.tabtxt2 {
	font-family: 微软雅黑;
	font-size: 14px;
	font-weight: bold;
	text-align: right;
	padding-right: 10px;
	color:#327cd1;
}
.tabtxt3 {
	font-family: 微软雅黑;
	font-size: 14px;
	padding-left: 15px;
	color: #000;
	margin-top: 10px;
	margin-bottom: 10px;
	line-height: 20px;
}
</style>
<!-- html  html  html  html  html  html  html  html  html  html  html -->
<table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
  <tr>
    <td align="center" class="biaoti" height="60">受理员业务统计表</td>
  </tr>
  <tr>
    <td align="right" height="25">2017-01-02---2017-05-02</td>
  </tr>
</table>

<table width="100%" border="0" cellspacing="1" cellpadding="4" bgcolor="#cccccc" class="tabtop13" align="center">
  <tr>
    <td colspan="2" class="btbg font-center titfont" rowspan="2">受理员</td>
    <td width="10%" class="btbg font-center titfont" rowspan="2">受理数</td>
    <td width="10%" class="btbg font-center titfont" rowspan="2">自办数</td>
    <td width="10%" class="btbg font-center titfont" rowspan="2">直接解答</td>
    <td colspan="2" class="btbg font-center titfont">拟办意见</td>
    <td colspan="2" class="btbg font-center titfont">返回修改</td>
    <td colspan="3" class="btbg font-center titfont">工单类型</td>
  </tr>
  <tr>
    <td width="8%" class="btbg font-center">同意</td>
    <td width="8%" class="btbg font-center">比例</td>
    <td width="8%" class="btbg font-center">数量</td>
    <td width="8%" class="btbg font-center">比例</td>
    <td width="8%" class="btbg font-center">建议件</td>
    <td width="8%" class="btbg font-center">诉求件</td>
    <td width="8%" class="btbg font-center">咨询件</td>
  </tr>
  <tr>
    <td width="7%" rowspan="8" class="btbg1 font-center">受理处</td>
    <td width="7%"  class="btbg2">王艳</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2 font-center">总计</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
  </tr>
  <tr>
    <td width="7%" rowspan="8" class="btbg1 font-center">话务组</td>
    <td width="7%"  class="btbg2">王艳</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">王艳</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">王艳</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">王艳</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td class="btbg2">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
   <tr>
    <td class="btbg2 font-center">总计</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
    <td class="btbg2 font-center">20</td>
  </tr>
</table>



### 表格头`<thead>`，表格尾`<tfoot>`、表格体`<tbody>`

```php+HTML
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>菜鸟教程(runoob.com)</title> 
<style type="text/css">
thead {color:green;}
tbody {color:blue;}
tfoot {color:red;}
</style>
</head>
<body>

<table border="1">
  <thead>
    <tr>
      <th>Month</th>
      <th>Savings</th>
    </tr>
  </thead>
  <tfoot>
    <tr>
      <td>Sum</td>
      <td>$180</td>
    </tr>
  </tfoot>
  <tbody>
    <tr>
      <td>January</td>
      <td>$100</td>
    </tr>
    <tr>
      <td>February</td>
      <td>$80</td>
    </tr>
  </tbody>
</table>

<p><b>提示:</b>  thead, tbody, 和 tfoot 元素默认不会影响表格的布局。不过，您可以使用 CSS 来为这些元素定义样式，从而改变表格的外观。</p>

</body>
</html>
```

<style type="text/css">
thead {color:green;}
tbody {color:blue;}
tfoot {color:red;}
</style>

<table border="1">
  <thead>
    <tr>
      <th>Month</th>
      <th>Savings</th>
    </tr>
  </thead>
  <tfoot>
    <tr>
      <td>Sum</td>
      <td>$180</td>
    </tr>
  </tfoot>
  <tbody>
    <tr>
      <td>January</td>
      <td>$100</td>
    </tr>
    <tr>
      <td>February</td>
      <td>$80</td>
    </tr>
  </tbody>
</table>

### 日期和时间标签`<time>`

```html
<p>我们在每天早上 <time>9:00</time> 开始营业。</p>
<p>我在 <time datetime="2016-02-14">情人节</time> 有个约会。</p>
```

<p>我们在每天早上 <time>9:00</time> 开始营业。</p> <p>我在 <time datetime="2016-02-14">情人节</time> 有个约会。</p> 

### html 字幕轨道标签`<track>`

> ###`<track>` 标签为媒体元素（比如`<audio>`and`<video>`）规定外部文本轨道 

```html
<video width="320" height="240" controls>
    <source src="forrest_gump.mp4" type="video/mp4">
    <source src="forrest_gump.ogg" type="video/ogg">
    <track src="subtitles_en.vtt" kind="subtitles" srclang="en" label="English">
    <track src="subtitles_no.vtt" kind="subtitles" srclang="no" label="Norwegian">
</video>
```

### 下划线标签`<u>`

```html
<p>This is a <u>parragraph</u>.</p>
```

<p>This is a <u>parragraph</u>.</p>

### 无序列表`<ul>`标签

```html
<ul>
  <li>Coffee</li>
  <li>Tea</li>
  <li>Milk</li>
</ul>
```

<ul>
  <li>Coffee</li>
  <li>Tea</li>
  <li>Milk</li>
</ul>

###媒体标签`<video>`

```html
<video width="320" height="240" controls>
    <source src="./attach/movie.mp4" type="video/mp4">
    <source src="./attach/movie.ogg" type="video/ogg">
    您的浏览器不支持 video 标签。
</video>
```

<video width="320" height="240" controls><br/> <source src="./attach/movie.mp4" type="video/mp4"><br/> <source src="./attach/movie.ogg"  type="video/ogg"><br/> 您的浏览器不支持 video 标签。<br/> </video> 



### 自定义标签

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8"> 
        <title>为 HTML 添加新元素</title>
        <script>
        	document.createElement("myHero")
        </script>

        <style>
            myHero {
                display: block;
                background-color: #ddd;
                padding: 50px;
                font-size: 30px;
            }
        </style> 
    </head>

    <body>
        <h1>我的第一个标题</h1>
        <p>我的第一个段落。</p>
        <myHero>我的第一个新元素</myHero>
    </body>
</html>
```

###画布标签

```html
<!DOCTYPE html> 
<html>
	<head> 
		<meta charset="utf-8"> 
		<title>菜鸟教程(runoob.com)</title> 
	</head> 
    
	<body>
		<canvas id="myCanvas">你的浏览器不支持 HTML5 canvas 标签。</canvas>
		<script>
			var c=document.getElementById('myCanvas');
			var ctx=c.getContext('2d');
			ctx.fillStyle='#FF0000';
			ctx.fillRect(0,0,80,100);
		</script>
	</body>
</html>
```

<iframe src="./web_samples/myCanvas.html"></iframe>



###声音控件 `<audio controls>`

```html
<audio controls>
    <source src="horse.ogg" type="audio/ogg">
    <source src="horse.mp3" type="audio/mpeg">
    您的浏览器不支持 audio 元素。
</audio>
```

<div>

<audio controls>
<source src="./web_samples/horse.ogg" type="audio/ogg">
<source src="./web_samples/horse.mp3" type="audio/mpeg">
您的浏览器不支持 audio 元素。
</audio>

</div>















