#删除firefox的会话恢复
#!/bin/bash
#找到后缀为.default的文件夹路径
path=`find ~/.mozilla/firefox -type d -name "*.default"`
#进入找的路径
cd $path
#删除会话恢复
rm sessionstore.* 
#判断上一条命令是否执行成功，并输出相关提示信息
if [ $? == 0 ]; then
	echo "会话恢复删除成功！"
else
	echo "所有的会话恢复已删除！"
fi
