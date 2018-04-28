#<center>secureCRT</center>

## 一、录制脚本功能

> ### 利用录制脚本功能，生成基本框架

## 二、特殊按键

### 1、`ctrl_N`

```vb
Sub Main
    crt.Screen.Send chr(14) & chr(14)
End Sub
```



###2、`ctrl _N + 1`

```vb
Sub Main
    crt.Screen.Send chr(14) & "1" && chr(13)
End Sub
```



## 三、循环

```vb
#$language  ="vbscript"
#$interface = "1.0"
crt.Screen.Synchronous = True
' this is automatically generated script , may be need to 
' be edited in order to work well

Sub Main
  dim  cond_1
  dim  cond_2
  dim  Para_1
  dim  Para_2
  
  cond_1 = 1
  cond_2 = 1
  
  Para_1 = AA
  Para_2 = BB
  
  OperationFunc = " doSomeFunc "
  crt.Screen.Send chr(14) & "1" & chr(13) `ctrl_N + 1
  ctr.Screen.WaitForString "##"
  crt.Screen.Send "setupFunc " & Para_1 && chr(13)
  ctr.Screen.WaitForString "##"
  crt.Screen.Send "setupFunc " & Para_2 && chr(13)
  
  while cond_1 <= 6
    cond_2 = 1
    while cond_2 <= 13
      crt.Screen.Send OperationFunc & ' cond_1 ' & cond_1 & ' cond_2 ' & cond_2 & chr(13)
      crt.Sceen.WaitForString "##"
    wend
      cond_1 = cond_1 + 1
  wend
End Sub    
```

## 四、条件语句

```vb
`如果条件不为 False
If crt.Screen.WaitForString ("XXX>", 1) <> False) Then
	crt.Screen.Send "enable " & chr(13)
Else
	crt.Screen.Send "disable" & chr(13)
End if
```

## 五、`case`语句

```vb
crt.Screen.Send "WriteFunc 2,3" & chr(13)
szOutput = crt.Screen.ReadString("Rebooting", 10)
Select Case crt.Screen.MatchIdx
case 0
  MsgBox "Time out"
case 1
  crt.Screen.Send "reboot " & chr(13)
End Select
```



