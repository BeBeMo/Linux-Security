#!/bin/bash 
#软件总信息
echo "库里的软件有："
apt-cache stats
#显示所有软件 
echo "已装软件有："
dpkg -l | awk '{if(NR!=1&&NR!=2&&NR!=3&&NR!=4&&NR!=5) {print $2}}'
#echo "软件包列表中里所有软件名称有："
#apt-cache pkgnames
exit 0
