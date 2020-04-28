#!/bin/sh
# $#是传给脚本的参数个数
# $0是脚本名字，$1 第一个参数 以此类推。$@是所有参数的列表
# shell 里面表示变量，前面要加上$
echo start

echo ----------
echo ----------
echo ----------
for name in $@
do
echo 查找单词 $name
grep -rn "$name" src |grep -v .py|grep -v .rst
echo ----------
echo ----------
echo ----------
echo 查找文件名 $name 
find -name $name*
echo ----------
echo ----------
echo ----------
done
echo end 
