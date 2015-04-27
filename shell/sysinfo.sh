#!/bin/bash
#系统信息
echo "CPU信息（型号）：" 
cat /proc/cpuinfo | grep name | cut -f2 -d: | uniq -c 
echo "当前cpu运行的位数："
getconf LONG_BIT 
echo "当前操作系统内核信息："
uname -a 
echo "查看操作系统版本："
head -n 1 /etc/issue  
echo "硬盘的型号信息："
cat /proc/scsi/scsi 
echo "计算机名:"
hostname
echo "内存信息 ："
cat /proc/meminfo
echo "所有USB设备有：" 
lsusb -tv
echo "所有PCI设备有："
lspci -tv   
echo "加载的内核模块有："
lsmod 
exit 0

