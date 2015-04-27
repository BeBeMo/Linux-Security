#!/bin/bash
#资源信息
echo "内存使用量和交换区使用量为："
free -m 
echo "各分区使用情况为："
df -h  
echo "内存总量为："
grep MemTotal /proc/meminfo
echo "空闲内存量为："
grep MemFree /proc/meminfo
echo "系统运行时间、用户数、负载为："
uptime 
echo "系统负载为："
cat /proc/loadavg  
exit 0
