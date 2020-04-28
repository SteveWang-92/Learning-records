#!/bin/sh
rm -rf /backups_wfh
mkdir /backups_wfh
echo creat file
cp  /media/wfh/大白菜U盘/*backup* /backups_wfh/
echo finish copy
tar -xvPzf /backups_wfh/home_backup.tar.gz -C / > home.log
echo finish home
tar -xvPzf /backups_wfh/other_backup.tar.gz -C /  > other.log
echo finished all
reboot
