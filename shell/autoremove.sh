#删除系统不再使用的孤立软件
#!/bin/bash
#验证密码是否正确
echo $1 | sudo -S echo "" 2> /dev/null
#判断上一条命令是否执行成功
if [ $? == 0 ];then
	sudo -S apt-get -y autoremove > /dev/null
	#判断上一条命令是否执行成功，并输出相关提示信息
	if [ $? == 0 ];then
		echo "孤立软件清理成功！"
	else
		echo "清理失败,请重试！"
	fi
else 
	echo "密码输入错误！"
fi


