#conda 其实就是一个包管理的工具，可以自己配置环境

#就是说自己的系统里面需要有各种python版本，然后conda创建一个环境，将这个环境的python和自己的环境上面的链接上，然后自己在根据需要定制各种各样的开发环境，比如需要numpy的，需要web的。
先pip install python3.7
然后下载conda的文件在官网上找到自己相应的系统一个XXXX.sh
然后终端 bash XXX.sh

#对于环境的操作
#下面是创建python=3.6版本的环境，取名叫py36
conda create -n py36 python=3.6 
#//删除环境（不要乱删啊啊啊）
conda remove -n py36 --all
#激活环境,下面这个py36是个环境名
conda activate py36
#退出环境
conda deactivate
#查看环境

conda list 列举当前环境下的所有包
conda list -n packagename 列举某个特定名称包
conda install packagename 为当前环境安装某包
conda install -n envname packagename 为某环境安装某包
conda search packagename 搜索某包
conda updata packagename 更新当前环境某包
conda update -n envname packagename 更新某特定环境某包
conda remove packagename 删除当前环境某包
conda remove -n envname packagename 删除某环境环境某包

#可以添加其他源，常用的有清华TUNA

conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
conda config --set show_channel_urls yes 在包后面显示来源


#阻止conda默认的打开.在~/.bashrc的最后加上下面一句话
conda config --set auto_activate_base false
