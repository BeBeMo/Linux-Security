#删除flash cookies
#!/bin/bash

#删除flash cookies
rm -rf ~/.macromedia/Flash_Player/*
#判断上一条命令是否执行成功，并输出相关提示信息
if [ $? == 0 ];then
	echo "flash cookies删除成功！"
else
	echo "所有flash cookies已删除！"
fi
