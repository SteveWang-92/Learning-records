sudo apt-get install git

最好的方法就是先在github上面有一个仓库，然后自己git clone 就可以直接用了　，不需要许多操作


创建版本库
$ mkdir learngit
$ cd learngit
$ pwd
/Users/michael/learngit

$ git init
Initialized empty Git repository in /Users/michael/learngit/.git/

初始化之后就可以在目录下面写东西，假设写的是一 readme.txt

$ git add readme.txt 
用命令git add告诉Git，把文件添加到仓库
$ git commit -m "wrote a readme file"
[master (root-commit) eaadf4e] wrote a readme file
 1 file changed, 2 insertions(+)
 create mode 100644 readme.txt
用命令git commit告诉Git，把文件提交到仓库

git status命令可以让我们时刻掌握仓库当前的状态
git diff顾名思义就是查看difference

版本控制系统肯定有某个命令可以告诉我们历史记录，在Git中，我们用git log命令查看：
如果嫌输出信息太多，看得眼花缭乱的，可以试试加上--pretty=oneline参数：
Git提供了一个命令git reflog用来记录你的每一次命令：

现在，我们要把当前版本append GPL回退到上一个版本add distributed，就可以使用git reset命令：
$ git reset --hard HEAD^
HEAD is now at e475afc add distributed

$ git reset --hard 1094a
HEAD is now at 83b0afe append GPL



你可以发现，Git会告诉你，git checkout -- file可以丢弃工作区的修改：

$ git checkout -- readme.txt

命令git checkout -- readme.txt意思就是，把readme.txt文件在工作区的修改全部撤销，这里有两种情况：

一种是readme.txt自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；

一种是readme.txt已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。

总之，就是让这个文件回到最近一次git commit或git add时的状态。

现在，看看readme.txt的文件内容：

$ cat readme.txt
Git is a distributed version control system.
Git is free software distributed under the GPL.
Git has a mutable index called stage.
Git tracks changes of files.

文件内容果然复原了。

git checkout -- file命令中的--很重要，没有--，就变成了“切换到另一个分支”的命令，我们在后面的分支管理中会再次遇到git checkout命令。


删除
$ rm test.txt
$ git rm test.txt
rm 'test.txt'
$ git commit -m "remove test.txt"
[master d46f35e] remove test.txt
 1 file changed, 1 deletion(-)
 delete mode 100644 test.txt
另一种情况是删错了，因为版本库里还有呢，所以可以很轻松地把误删的文件恢复到最新版本：
$ git checkout -- test.txt

git远程仓库
一、安装 Git
配置git用户信息
git config --global user.name "woider"
git config --global user.email "woider@gmail.com"
二、开启 SSH 服务
apt-get install ssh
ps -e | grep sshd
三、生成 SSH KEY
* 使用 ls -al ~/.ssh 命令查看 ssh key 是否存在，若存在则忽略这一步
　生成 SSH KEY：  ssh-keygen -t rsa -C "woider@gmail.com"  
　生成 ssh key 过程中，会让你填写 passphrase，连按三次回车跳过即可


查看 SSH KEY
 进入 /root/.ssh 目录，查看 id_rsa 和 id_rsa.pub 文件：
 root@localhost:~# cd /root/.ssh
 root@localhost:~/.ssh# ls -a  
↑ id_rsa 为私钥，id_rsa.pub 为公钥

复制 SSH KEY
打开 id_rsa.pub 文件，将内容复制到剪贴板

添加 SSH KEY
登录 GitHub，打开 Personal settings 页面，选择 SSH and GPG keys 选项：
↑ Title 可以随意填写，Key 中填写刚从 id_rsa.pub 中拷贝的内容
添加 SSH key 之后，Linux 就可以通过 SSH 建立本地 Git 与 GitHub 的连接了。

之后就是在ｇｉｔｈｕｂ上面创建仓库，然后ｃｌｏｎｅ到本地，记得初始化的选项选上

 git push origin master  命令推送修改

如果自己在本地新建的一个文件，那么就先在本地git init,初始化一下。
然后将已有的文件 
git add --all
git commit -m "xxxxx"
这时候再在远程仓库那里新建一个和本地仓库名字一样的远程仓库，
在本地git push -u origin master 、
但是
如果你选择了创建一个README那么这时候会提示报错
其实原因就是仓库这个不匹配，需要先pull一下，和本地的合并之后再push
git pull --rebase origin master
git push -u origin master 、



创建合并分支

首先，我们创建dev分支，然后切换到dev分支：

$ git checkout -b dev
Switched to a new branch 'dev'

git checkout命令加上-b参数表示创建并切换，相当于以下两条命令：

$ git branch dev
$ git checkout dev
Switched to branch 'dev'

然后，用git branch命令查看当前分支：

$ git branch
* dev
  master

git branch命令会列出所有分支，当前分支前面会标一个*号。

然后，我们就可以在dev分支上正常提交，比如对readme.txt做个修改，加上一行：

Creating a new branch is quick.

然后提交：

$ git add readme.txt 
$ git commit -m "branch test"
[dev b17d20e] branch test
 1 file changed, 1 insertion(+)

现在，dev分支的工作完成，我们就可以切换回master分支：

$ git checkout master
Switched to branch 'master'

切换回master分支后，再查看一个readme.txt文件，刚才添加的内容不见了！因为那个提交是在dev分支上，而master分支此刻的提交点并没有变：

现在，我们把dev分支的工作成果合并到master分支上：

$ git merge dev
Updating d46f35e..b17d20e
Fast-forward
 readme.txt | 1 +
 1 file changed, 1 insertion(+)

git merge命令用于合并指定分支到当前分支。合并后，再查看readme.txt的内容，就可以看到，和dev分支的最新提交是完全一样的。

注意到上面的Fast-forward信息，Git告诉我们，这次合并是“快进模式”，也就是直接把master指向dev的当前提交，所以合并速度非常快。

当然，也不是每次合并都能Fast-forward，我们后面会讲其他方式的合并。

合并完成后，就可以放心地删除dev分支了：

$ git branch -d dev
Deleted branch dev (was b17d20e).

删除后，查看branch，就只剩下master分支了：

$ git branch
* master

因为创建、合并和删除分支非常快，所以Git鼓励你使用分支完成某个任务，合并后再删掉分支，这和直接在master分支上工作效果是一样的，但过程更安全。



$ git branch
* dev
  master
$ git checkout master
Switched to branch 'master'

然后，敲命令git tag <name>就可以打一个新标签：

$ git tag v1.0

可以用命令git tag查看所有标签：

$ git tag
v1.0

$ git tag v0.9 f52c633

注意，标签不是按时间顺序列出，而是按字母排序的。可以用git show <tagname>查看标签信息：

还可以创建带有说明的标签，用-a指定标签名，-m指定说明文字：

$ git tag -a v0.1 -m "version 0.1 released" 1094adb

用命令git show <tagname>可以看到说明文字：
删除标签
$ git tag -d v0.1
推送某个标签
$ git push origin v1.0
一次性推送全部尚未推送到远程的本地标签：

$ git push origin --tags

如果标签已经推送到远程，要删除远程标签就麻烦一点，先从本地删除：

$ git tag -d v0.9
Deleted tag 'v0.9' (was f52c633)

然后，从远程删除。删除命令也是push，但是格式如下：

$ git push origin :refs/tags/v0.9
