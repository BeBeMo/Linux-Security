#!/bin/bash
echo "用户信息"
echo "当前活动用户为："
w 
echo "系统所有用户为"
cut -d: -f1 /etc/passwd
echo "系统所有组为："
cut -d: -f1 /etc/group
exit 0
