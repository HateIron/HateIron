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

