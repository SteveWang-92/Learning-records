# 场景一：删除master分支下的所有历史版本与log，只保留当前的版本，并同步至GitHub

- 方法一：先新建一个名为latestbranch的分支，然后将当前master分支中的所有文件添加到latestbranch分支中，接着等待移动完毕后删除master分支，最后把latestbranch这个分支的分支名改为master。

- 具体实现：
尝试运行 git checkout --orphan latestbranch
添加所有文件git add -A
提交更改git commit -am "commit message"
删除分支git branch -D master
将当前分支重命名git branch -m master
最后，强制更新存储库。git push -f origin master

- 方法二：不推荐使用，可能导致git存储库出现问题。思路：直接删除.git文件再初始化仓库

- 先删除.git文件

然后初始化Git（user为你的用户名，repo为你的仓库名）
git init git remote add origin git@github.com:user/repo
提交当前版本的代码：
git add * git commit -am 'message'
最后，强制更新到GitHub：
git push -f origin maste

[原文侵删](https://blog.csdn.net/COCO56/article/details/86560424 )

