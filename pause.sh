#!/bin/bash
#实现按任意键操作的脚本文件
#-s 指输入的字符屏幕上不可件，应该说可见，但由于和终端的背景色相同，故不可见了
 
#-n1 看到n后那个“1”了没，表示仅接收1个字符，按回车键也属于一个字符
 
#-p是指后面可加用“ ”括起来的提示符
read -s -n1 -p "按任意键继续 ... "
