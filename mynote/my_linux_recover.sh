#!/bin/sh
mkdir /backups_wfh
mv  /home/wfh/backups_wfh/*.tar.gz /backups_wfh/

tar -xvPzf /backups_wfh/home_backup.tar.gz / > home.log

tar -xvPzf /backups_wfh/other_backup.tar.gz  /  > other.log


echo finished
