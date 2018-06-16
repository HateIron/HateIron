# --*-- coding: utf-8 --*--
import os,sys
import stat
from os.path import basename

html = ('<!DOCTYPE html>\n' 
        '\n' 
        '<html>\n'
        '{navigation}\n'
        '</html>\n')

details_header = (
        '<details class="menu" close>\n'
        '<summary>{content}</summary>\n'
        '<ul>\n'
        '\n')

details_footer = (
        '<ul>\n'
        '</details>\n')
table_flag     = '|-|-|-|-|\n'
cell           =  '|<a href="{link}" target="showframe"> {content} </a>'
tbl_width      = 3

def file_scan(path):
    content    = ''
    file_num   = 0
    left_cells =0
    files      = os.listdir(path)
    for file in files:
        file_path = os.path.join(path, file)
        if not os.path.isdir(file_path) and file_path.endswith('.html'):
            file_num += 1
            #print ("full_name = %s"%file)
            file = os.path.basename(file)
            file_and_ex = os.path.splitext(file)
            #分别取出文件名，后缀名，存储在file_and_ex[0] 、 file_and_ex[1]中
            #print ("file_and_ex.file = " + file_and_ex[0])
            file = file_and_ex[0]
            #print ("base_name = %s"%file)
            content += str(cell).format(link=file_path,content=file)
            if (file_num%tbl_width == 0):
                content += '|\n'
            if (tbl_width==file_num):
                content += table_flag
    while left_cells < (tbl_width-file_num%tbl_width):
        content += '| '
        left_cells += 1
    content += '|\n'
    return content

#if __name__='__main__':
content = ''
text    = ''  
content+= file_scan('./')
with open('index.md', 'w') as f:
    f.writelines(content)     