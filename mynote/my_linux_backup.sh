#!/bin/sh
echo start                                             
rm -rf /home/wfh/backups_wfh
rm -rf /backups_wfh
mkdir /backups_wfh /home/wfh/backups_wfh


#一共有cdrom  home            lib         media               opt   run   srv  usr bin    dev    initrd.img      lib64       mnt                 proc  sbin  sys  var boot         etc    initrd.img.old  lost+found  my_linux_backup.sh  root  snap  tmp  vmlinuz  里面需要备份的是home opt lib*  srv usr bin initrd* sbin var boot etc root snap vmlinuz#可能还有需要修改的只知道这么多了
tar -cvPzf /backups_wfh/home_backup.tar.gz --exclude=/lost+found /home > home.log
#备份home文件夹，输出重定向是为了过滤标准输入看到错误输出。
echo finish home backup
tar -cvPzf /backups_wfh/other_backup.tar.gz  opt lib*  /srv /usr /bin initrd* /sbin /var /boot /etc /root /snap recover backup vmlinuz > other.log
#备份其他提到的文件夹
echo finish other backup
mv /backups_wfh/*.tar.gz /home/wfh/backups_wfh/
rm home.log
rm other.log
echo finished
