#<center>gtest</center>

[TOC]

## 一、 gtest 代码获取

```powershell
一、https://sourceforge.net/projects/mxedeps/files/gtest-1.7.0.zip/download
二、玩客云 》分区１　》　onecloud 》 tools 》　gtest-1.7.0.zip

在 linux 环境解压之：
	unzip gtest-1.7.0.zip
```



## 二、更改gtest使用时的目录结构，不能把项目代码放在 gtest 里面

```powershell
将原来 gtest 目录中的用例全部删除。
也不再使用 gtest 自带的测试用例。如此一下，整个 gtest 框架代码变得极小
```



## 三、更改相应的 Makefile



## 四、应用

## 五、整合时编译出错

此时在 gtest Makefile 和 项目的 makefile 中，CXXFLAGS 增加两个参数
CXXFLAGS += -Bdynamic -lgcc_s

## 六、 gtest输出 xml 格式的报告

## 1、首先在 main 函数中加入一句打印开关

```powershel
testing::GTEST_FLAGS(output) = "xml";
```

## 2、将 xml 报告转化为 html

- ### A、为 test_detail.xml 配套一个 xsl 样式表文件

```powershell
一、带上testing::GTEST_FLAGS(output) = "xml";　后，运行结果生成一个　test_detail.xml　文件
　　以 gtest 默认的示例。直接进入　gtest-1.7.0/make　; make ; sample1_unittest
二、为 test_detail.xml 匹配一个 xsl 文件
　　内容如下

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:msxsl="urn:schemas-microsoft-com:xslt" exclude-result-prefixes="msxsl"> 

<xsl:output method="html" indent="yes"/> 

<xsl:template match="/"> 

<table cellpadding="2" cellspacing="5" border="1px">
<tr>
    <th bgcolor="#808080"><font color="#FFFFFF">Testcase Num</font></th>
    <th bgcolor="#808080"><font color="#FFFFFF">Failure Num</font></th>
</tr>
<tr>
    <td style="font-family: Verdana; font-size: 15px; font-weight: bold;"><xsl:value-of select="testsuites/@tests"/> </td>
    <td style="font-family: Verdana; font-size: 15px; font-weight: bold;"><xsl:value-of select="testsuites/@failures"/> </td>
</tr>
</table>

<table cellpadding="2" cellspacing="5"> 
<tr><td style="font-family: Verdana; font-size: 10px;">

<table align="left" cellpadding="2" cellspacing="0" style="font-family: Verdana; font-size: 10px;"> 
<tr>
<th bgcolor="#808080"><font color="#FFFFFF"><b>TestSuites</b></font></th> 
<th bgcolor="#808080">
<table width="1000px" align="left" cellpadding="1" cellspacing="0" style="font-family: Verdana; font-size: 10px;">
<tr style="font-family: Verdana; font-size: 10px;">
<td  width="15%"><font color="#FFFFFF"><b>Testcase</b></font></td>
<td  width="25%"><font color="#FFFFFF"><b>Result</b></font></td>
<td  width="75%"><font color="#FFFFFF"><b>ErrorInfo</b></font></td>
</tr>
</table>
</th> 
</tr> 
<xsl:for-each select="testsuites/testsuite"> 
<tr>
<td style="border: 1px solid #808080"><xsl:value-of select="@name"/></td> 
<td style="border: 1px solid #808080">
<table width="1000px" align="left" cellpadding="1" cellspacing="0" style="font-family: Verdana; font-size: 10px;">
<xsl:for-each select="testcase">
<tr>
<td style="border: 1px solid #808080" width="15%" rowspan="@tests"><xsl:value-of select="@name"/></td>
<xsl:choose>
    <xsl:when test="failure">
      <td style="border: 1px solid #808080" bgcolor="#ff00ff" width="25%">Failure</td>
      <td style="border: 1px solid #808080" bgcolor="#ff00ff" width="70%"><xsl:value-of select="failure/@message"/></td>
    </xsl:when>
    <xsl:otherwise>
     <td style="border: 1px solid #808080" width="25%">Success</td>
     <td style="border: 1px solid #808080" width="70%"><xsl:value-of select="failure/@message"/></td>
     </xsl:otherwise>
</xsl:choose>
</tr>
</xsl:for-each>
</table>
</td> 
</tr>
</xsl:for-each> 
</table> 
</td> 
</tr> 
</table>

</xsl:template>
</xsl:stylesheet>
```

- ###　Ｂ、test_detail.xml 调用 xsl 文件

```powershell
只需要在 test_detail.xml 第二行加入一句：
<?xml-stylesheet type="text/xsl" href="aa.xsl"?>
```

## 3、效果

- ### Ａ、无错情况下的效果图

<iframe src="./attach/test_detail_succ.xml" width="1000px" height="210px" boarder="1px" scrolling="no"></iframe>

- ### B 、有错时的效果图

<iframe src="./attach/test_detail_fail.xml" width="1000px" height="210px" boarder="1px" scrolling="no"></iframe>









