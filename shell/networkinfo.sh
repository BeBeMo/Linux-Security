#!/bin/bash
#网络信息
echo "路由表信息为："
route -n
echo "网络接口的属性为："
ifconfig
echo "网络统计信息为："
netstat -s
exit 0
