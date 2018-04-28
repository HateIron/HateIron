#<center>VIM</center>

<span id='jump'></span>

[TOC]

## 1、vim 下实现代码像 source insight 一样的跳转功能

> ### 1、首先要下载到 ctags.
>
> ​	因为 taglist 基于 [ctags](https://vim.sourceforge.io/scripts/script.php?script_id=273)，或到 http://share.wishcell.cn/2018/2018-01.html 下载
>
> ###2、解压后将插件脚本文件(.vim)和帮助文件(.txt)分别放入vim常用目录
>
> 下载到的压缩包为：`taglist_46.zip`
>
> 解压之：
>
> ```shell
> [root@localhost packages]# mkdir tmp 
> [root@localhost packages]# unzip -n taglist_46.zip -d ./tmp/
> Archive:  taglist_46.zip
>   inflating: ./tmp/plugin/taglist.vim  
>   inflating: ./tmp/doc/taglist.txt  
> ```
>
> 将其解压到指定目录 ./tmp下面，然后将 脚本文件`.vim`和帮助文件`.txt`分别放入常用目录：
>
> `$HOME/.vim/` 或者`$HOEM/vimfiles/`或者`$VIM/vimfiles` 下面的 `plugin/taglist.vim`
>
> `/doc/taglist.txt`
>
> 然后重启 vim.
>
> ```shell
> [root@localhost .vim]# ls /packages/tmp/plugin/
> taglist.vim
> [root@localhost .vim]# cp /packages/tmp/plugin/taglist.vim ./
> [root@localhost .vim]# pwd
> /home/wishcell/.vim
>
> [wishcell@localhost .vim]$ mkdir ~/.vim/doc/
> [wishcell@localhost .vim]$ cp /packages/tmp/doc/taglist.txt ~/.vim/doc/
> [wishcell@localhost .vim]$ ls /packages/tmp/doc/
> taglist.txt
> [wishcell@localhost .vim]$ 
> ```
>
> ### 3、导入帮助文件
>
> ```shell
> :helptags ~/.vim/doc
> ```
>
> 执行完毕后，帮助文件已经被导入。然后使用
>
> ```
> :help taglist.txt
> ```
>
> 来详细查看手册
>
> ```shell
> taglist.txt     Plugin for browsing source code
>     
> Author: Yegappan Lakshmanan  (yegappan AT yahoo DOT com)
> For Vim version 6.0 and above
> Last change: 2013 Feburary 26
>     
> 1. Overview                                     taglist-intro
> 2. Taglist on the internet                      taglist-internet
> 3. Requirements                                 taglist-requirements
> 4. Installation                                 taglist-install
> 5. Usage                                        taglist-using
> 6. Options                                      taglist-options
> 7. Commands                                     taglist-commands
> 8. Global functions                             taglist-functions
> 9. Extending                                    taglist-extend
> 10. FAQ                                         taglist-faq
> 11. License                                     taglist-license
> 12. Todo                                        taglist-todo
>         
> ==============================================================================
> taglist.txt [Help][RO]                                                                         1,1            Top
>     } else {
> study/c/EasyLogger/easylogger/src/elog.c                                                       644,1          99%
> "taglist.txt" [readonly] 1515L, 69979C
> ```
>
> ###4、正式使用
>
> ##### A、在vim中，打开`taglist`窗口使用
>
> ```shell
> :TlistOpen
> ```
>
> 得到这样的窗口:左侧窗口，光标在函数上，可上下移动。先中一个回车，即跳到相应函数
>
> #####B、在vim中，关闭`taglist`窗口使用
>
> ```
> :TlistClose
> ```
>
> #####问题：
>
> ```shell
> 执行 :Tlist (:TlistOpen, :TlistToggle) 命令后，
> 得到错误提示：
> E488: Trailing characters   
>
> 由于太复杂，只得放弃跟踪
> ```
>
> ###5、多种使用选项，快捷键
>
> +  回车`---跳到光标所在代码处。即光标在哪个函数。回车后就跳上
>
>
> + `o` --- 新开一个窗口，显示 tag 的内容。与 source Insight 很像了
> + `u` --- 更新 taglist 窗口中的 tag
> + `s`---两种排序方式切换：名称排序/出现顺序
> + `x`--- taglist 窗口放大/缩小，方便查看较长的 tag
> + `<space>`---空格，在下文显示当前 tag 的定义。
> + `+`---打开一个折叠，同`zo`
> + `-`---将一个 tag 折叠起来，同`zc`
> + `*`--- 打开所有的折叠，同`zR`
> + `=`---将所有 tag 折叠起来，同`zM`
> + `[[`---跳到前一个文件
> + `]]`---跳到下一个文件
> + `q`---关闭 `taglist`窗口
>   + `<F1>`显示帮助
>
> ### 6、其它可以在`vimrc`脚本中添加的功能
>
> ```
> "设置ctags路径
> let Tlist_Ctags_Cmd = '/usr/bin/ctags'
>
> "启动vim后自动打开taglist窗口
> let Tlist_Auto_Open = 1
>
> "不同时显示多个文件的tag，仅显示一个
> let Tlist_Show_One_File = 1
>
> "taglist为最后一个窗口时，退出vim
> let Tlist_Exit_OnlyWindow = 1
>
> "taglist窗口显示在右侧，缺省为左侧
> let Tlist_Use_Right_Window =1
>
> "设置taglist窗口大小
> "let Tlist_WinHeight = 100
> let Tlist_WinWidth = 40
>
> "设置taglist打开关闭的快捷键F8
> noremap <F8> :TlistToggle<CR>
>
> "更新ctags标签文件快捷键设置
> noremap <F6> :!ctags -R<CR>
> ```
>
> 
>
> 还有许多其他的设置，请参考帮助文档:help taglist.txt
> 其英文原版手册: <http://vim-taglist.sourceforge.net/manual.html>
>
> 



## 2、ctags 更多精美的配置

###本文来自http://www.cnblogs.com/feisky/archive/2012/02/07/2341932.html

### 1、生成标签文件

> 在当前目录下(运行$提示符后面的命令): 
>
> ```shell
> $ctags -R .
> ```
>
> -R表示recursive，递归,为当前目录及其子目录中的c文件生成标签文件。最后一个.表示在当前目录。
>
> ​        运行完当前目录会多一个文件tags,就是c标签的索引文件。

### 2、跳转

>   1.用vim打开一个已经建过标签的c文件
>
>   2. `ctrl+] `找到光标所在位置的标签定义的地方
>
>   3. `ctrl+t `回到跳转之前的标签处
>
>    ​    注意：此时运行vim，必须在"tags"文件所在的目录下运行。否则，运行它会找不到"tags"文件，而需要在vim中用":set tags="命令设定"tags"文件的路径。对于一个稍微大点的项目，你可能在任何一个目录下打开vim，然而在每个目录下都生成一个tags文件并不 是个好主意，那么如何解决呢？方法是在.vimrc中增加一行：
>
>    ```shell
>    set tags=tags;/
>    ```
>
>    这是告诉vim在当前目录找不到tags文件时请到上层目录查找。

### 3、在 `vim`中输入`:Tlist`即可自动的开/关切换

> 一个简单的方法是设定快捷键,在.vimrc中增加一行:
>
> ` nnoremap <silent> <F8> :TlistToggle<CR>`
>
> 这样在vim中按F8就可以打开/关闭taglist了。
>
> 更多相关配置请看后面关于.vimrc的介绍。

###4、这位朋友的 `.vimrc`

```bash
".vimrc
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" General
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"For ctags, then it can find the 'tags' file even not in current directory
set tags=tags;/
"Get out of VI's compatible mode..
set nocompatible
"Sets how many lines of history VIM har to remember
set history=400
"Set to auto read when a file is changed from the outside
set autoread
"Have the mouse enabled all the time:
"when you need to copy from vim, maybe you have to ':set mouse=' first
set mouse=a
"""""""""""""""""""""""""""""""""""""
" Colors and Fonts
"""""""""""""""""""""""""""""""""""""
"Enable syntax highlight
syntax enable
"set colorscheme
colorscheme elflord
"endif
"""""""""""""""""""""""""""""""""""""
" VIM userinterface
"""""""""""""""""""""""""""""""""""""
"Set 7 lines to the curors away from the border- when moving vertical..
set so=7
"Turn on WiLd menu
set wildmenu
"Always show current position
set ruler
"The commandbar is 2 high
set cmdheight=2
"Show line number
set nu
"Set backspace
set backspace=eol,start,indent
"Bbackspace and cursor keys wrap to
set whichwrap+=<,>,h,l
"show matching bracets
set showmatch
"How many tenths of a second to blink
set mat=2
"Highlight search things
set hlsearch
"imediately show the search result
set is
"""""""""""""""""""""""""""""""""""""
" Folding
"""""""""""""""""""""""""""""""""""""
"Enable folding, I find it very useful
set nofen
set fdl=0
"""""""""""""""""""""""""""""""""""""
" Text options
"""""""""""""""""""""""""""""""""""""
set expandtab
set shiftwidth=2
set ambiwidth=double
set smarttab
"Set Tab=4 spaces
set ts=4
set lbr
set tw=500
set selection=inclusive
   """"""""""""""""""""""""""""""
   " Indent
   """"""""""""""""""""""""""""""
   "Auto indent
   set ai
   "Set auto indent width = 4 spaces
   set sw=4
   "Smart indet
   set si
   "C-style indenting
   set cindent "usage: select codes, press '=' key, the codes will autoindenting
   "Wrap lines
   set wrap
"Encoding settings
if has("multi_byte")
    " Set fileencoding priority
    if getfsize(expand("%")) > 0
        set fileencodings=ucs-bom,utf-8,cp936,big5,euc-jp,euc-kr,latin1
    else
        set fileencodings=cp936,big5,euc-jp,euc-kr,latin1
    endif
    " CJK environment detection and corresponding setting
    if v:lang =~ "^zh_CN"
        " Use cp936 to support GBK, euc-cn == gb2312
        set encoding=cp936
        set termencoding=cp936
        set fileencoding=cp936
    elseif v:lang =~ "^zh_TW"
        " cp950, big5 or euc-tw
        " Are they equal to each other?
        set encoding=big5
        set termencoding=big5
        set fileencoding=big5
    elseif v:lang =~ "^ko"
        " Copied from someone's dotfile, untested
        set encoding=euc-kr
        set termencoding=euc-kr
        set fileencoding=euc-kr
    elseif v:lang =~ "^ja_JP"
        " Copied from someone's dotfile, unteste
        set encoding=euc-jp
        set termencoding=euc-jp
        set fileencoding=euc-jp
    endif
    " Detect UTF-8 locale, and replace CJK setting if needed
    if v:lang =~ "utf8$" || v:lang =~ "UTF-8$"
        set encoding=utf-8
        set termencoding=utf-8
        set fileencoding=utf-8
    endif
else
    echoerr "Sorry, this version of (g)vim was not compiled with multi_byte"
endif
"""""""""""""""""""""""""""""""""""""
"plugins
"""""""""""""""""""""""""""""""""""""
" Tlist
if &diff
let Tlist_Auto_Open=0 "don't auto pen when compare two files
else
let Tlist_Auto_Open=1 "auto pen Tlist when open a file
endif
"set taglist window in right, delete the following line if you don't like
let Tlist_Use_Right_Window=1
let Tlist_Auto_Update=1 
let Tlist_File_Fold_Auto_Close=1
"auto close Tlist when exiting file.
let Tlist_Exit_OnlyWindow = 1 
nmap <F7> :copen<CR>
nmap <F6> :cclose<CR>
```

## 3、vimdiff 的使用

> ### 用法主要整理来源于`https://jingyan.baidu.com/article/ae97a646da05debbfd461d33.html`
>
> 

### A、打开方式

> 1、水平打开
>
> ```shell
> vimdiff a.c  b.c   
> 或者
> vimdiff -d a.c  b.c 
> ```
>
> 2、垂直打开
>
> ```shell
> vimdiff -o a.c b.c
> ```

###B、符号意义

> 1、折叠行
>
> ```shell
>  +--  7 lines: #include <stdio.h>-------------------   表示折叠的行
> ```
>
> 2、删除的行
>
> ```shell
> 二.------------------------------------------------------------   表示删除的行
> ```
>
> 3、对行进行`折叠/展开`
>
> - `zo`展开折叠的行
> - `zc`将行折叠

### C、差异跳转

> 1、跳到上一个差异`]c`
>
> 2、跳到下一个差异`[c`
>
> 3、左右窗口切换`ctrl + ww`

### D、左右窗口内容复制

> 1、从当前窗口复制给另一窗口`dp`
>
> 2、从另一窗口复制到当前窗口`do`

### E、退出vimdiff

> 1、保存所有文件并退出
>
> ```shell
> :wqa!
> ```
>
> 2、不保存所有文件并退出
>
> ```shell
> :qa!
> ```

## 4、字符串替换

```shell
:1,$s/old_str/new_str/g
```

## 5、列编辑，如全部注释

引用 https://www.cnblogs.com/xiaowant/articles/1992923.html

```
删除列
1.光标定位到要操作的地方。
2.CTRL+v 进入“可视 块”模式，选取这一列操作多少行。
3.d 删除。
 
插入列
插入操作的话知识稍有区别。例如我们在每一行前都插入"() "：
1.光标定位到要操作的地方。
2.CTRL+v 进入“可视 块”模式，选取这一列操作多少行。
3.SHIFT+i(I) 输入要插入的内容。
4.ESC 按两次，会在每行的选定的区域出现插入的内容。
```

##6、vim 中清除 `^M`，实测第四种方法可行

```powershell
第一种方法：
cat -A filename 就可以看到windows下的断元字符 ^M
要去除他，最简单用下面的命令：
dos2unix filename
 
第二种方法： 
sed -i 's/^M//g' filename
#注意：^M的输入方式是 Ctrl + v ，然后Ctrl + M 
 
第三种方法：
#vi filename 
:1,$ s/^M//g
^M 输入方法： ctrl+V ,ctrl+M
 
第四种方法：
#cat filename |tr -d '/r' > newfile
#^M 可用 /r 代替
```



