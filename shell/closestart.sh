#!/bin/bash
#关闭自启动项

#统计有多少个自启动项
n=$(cat ./shell/result2 | wc -l)
#检测输入的自启动项编号是否存在
if [ $1 -gt 0 -a $1 -le $n ]; then
	#获取输入编号对应的自启动项
	a=$(cat ./shell/result2 | awk 'NR=='$1'{print $2}')
	#把自启动项名字中的S替换为K
	b=${a/S/K}
	#把S开头的自启动项名字重命名为K开头的，此时自启动项就变成了开机不自启动项
	echo $2 | sudo -S mv $a $b
	#判断上一条重命名的命令是否执行成功，并输出相关提示信息
	if [ $? == 0 ]; then
		echo "关闭成功！"
	else
		echo "关闭失败！"
	fi

else
	echo "输入编号错误！"
fi
exit 0







