# 是一个调试工具不是一个编译工具
[来源](https://www.linuxidc.com/Linux/2019-01/156510.htm)

- gcc -g test.c -o test //-g 一定要加上因为这是

- gdb tst

- list 列出相应的代码块，正常是10行，显示的行数是可以修改的在vimrc中

- breakpoint 16 断点在第16行
	breakpoint fun 在函数fun处进行断点
	info breakpoint 查看断点
  	delete + 断点的数值标识符，delete 1，删除第1个断点；
	clear + 函数名 、 +行号、+文件名:行号 ，清除断点main()函数处的断点：clear main 或者 clear 5 （本质是main函数的第一条语句所在）；


- run 运行程序

- next 下一步
- print i 打印变量i
- bt 查看函数堆栈
- finish 退出函数
- q 退出gbd

- 源代码搜索 
1. forward-research 
2. search 
3. reverse-search
后面都加上正则表达式就行

- 指定源文件的路径(有时候进入gdb但是找不到源文件，有可能表明相应的程序不在这目录下面，可以指定目录去寻找)
1. directory/dir <dirname>
2. show directory显示源文件目录


# gdb 调试程序
- gdb <programname> 
- gdb <programname> core 程序非法执行产生的文件，调试运行一个程序和core文件
gdb　
- gdb <programname> PID 运行的PID的程序自动跟上

# GDB启动时，可以加上一些GDB的启动开关，详细的开关可以用gdb -help查看。我在下面只例举一些比较常用的参数：
-symbols <file>/-s <file>
    从指定文件中读取符号表。
-se file
    从指定文件中读取符号表信息，并把他用在可执行文件中。
-core <file>/-c <file>
    调试时core dump的core文件。
    -directory <directory>/-d <directory>
    加入一个源文件的搜索路径。默认搜索路径是环境变量中PATH所定义的路径。

# 在gdb环境中，你可以执行UNIX的shell的命令，使用gdb的shell命令来完成：
- shell <command string>
调用UNIX的shell来执行<command string>，环境变量SHELL中定义的UNIX的shell将会被用来执行<command string>，如果SHELL没有定义，那就使用UNIX的标准shell：/bin/sh。（在Windows中使用Command.com或 cmd.exe）
- 还有一个gdb命令是make：
make <make-args>
可以在gdb中执行make命令来重新build自己的程序。这个命令等价于"shell make <make-args>"。

---
# 在GDB中运行程序####

当以gdb <program>方式启动gdb后，gdb会在PATH路径和当前目录中搜索<program>的源文件。如要确认gdb是否读到源文件，可使用l 或list命令，看看gdb是否能列出源代码。
在gdb中，运行程序使用r或是run命令。程序的运行，你有可能需要设置下面四方面的事。

1. 程序运行参数
set args 可指定运行时参数。（如：set args 10 20 30 40 50）
show args 命令可以查看设置好的运行参数。

2. 运行环境
path <dir> 可设定程序的运行路径。
show paths 查看程序的运行路径。
set environment varname [=value] 设置环境变量。如：set env USER=hchen
show environment [varname] 查看环境变量。

3. 工作目录
cd <dir> 相当于shell的cd命令。
pwd 显示当前的所在目录。

4. 程序的输入输出
info terminal 显示你程序用到的终端的模式。
使用重定向控制程序输出。如：run > outfile
tty命令可以指定写输入输出的终端设备。如：tty /dev/ttyb



调试已运行的程序####

两种方法：
1、在UNIX下用ps查看正在运行的程序的PID（进程ID），然后用gdb <program> PID格式挂接正在运行的程序。
2、先用gdb <program>关联上源代码，并进行gdb，在gdb中用attach命令来挂接进程的PID。并用detach来取消挂接的进程。


暂停 / 恢复程序运行####

调试程序中，暂停程序运行是必须的，GDB可以方便地暂停程序的运行。你可以设置程序的在哪行停住，在什么条件下停住，在收到什么 信号时停住等等。以便于你查看运行时的变量，以及运行时的流程。

当进程被gdb停住时，你可以使用info program 来查看程序的是否在运行，进程号，被暂停的原因。

在gdb中，我们可以有以下几种暂停方式：断点（BreakPoint）、观察点（Watch Point）、捕捉点（Catch Point）、信号（Signals）、 线程停止（Thread Stops）。如果要恢复程序运行，可以使用c或是continue命令。

一、设置断点（Break Points）
我们用break命令来设置断点。下面有几点设置断点的方法：

break <function>
在进入指定函数时停住。C++中可以使用class::function或function(type,type)格式来指定函数名。

break <linenum>
在指定行号停住。

break +offset
break -offset
在当前行号的前面或后面的offset行停住。offiset为自然数。

break filename:linenum
在源文件filename的linenum行处停住。

break filename:function
在源文件filename的function函数的入口处停住。

break *address
在程序运行的内存地址处停住。

break
break命令没有参数时，表示在下一条指令处停住。

break ... if <condition>
...可以是上述的参数，condition表示条件，在条件成立时停住。比如在循环境体中，可以设置break if i=100，表示当i为100时停住程序。

查看断点时，可使用info命令，如下所示：（注：n表示断点号）
info breakpoints [n]
info break [n]


二、设置观察点（WatchPoint）
观察点一般用来观察某个表达式（变量也是一种表达式）的值是否有变化，如果有变化，马上停住程序。我们有下面的几种方法来设置观察点：
watch <expr>
为表达式（变量）expr设置一个观察点。一旦表达式值有变化时，马上停住程序。

rwatch <expr>
当表达式（变量）expr被读时，停住程序。

awatch <expr>
当表达式（变量）的值被读或被写时，停住程序。

info watchpoints
列出当前所设置了的所有观察点。

三、设置捕捉点（CatchPoint）
你可设置捕捉点来补捉程序运行时的一些事件。如：载入共享库（动态链接库）或是C++的异常。设置捕捉点的格式为：

catch <event>
当event发生时，停住程序。event可以是下面的内容：
1、throw 一个C++抛出的异常。（throw为关键字）
2、catch 一个C++捕捉到的异常。（catch为关键字）
3、exec 调用系统调用exec时。（exec为关键字，目前此功能只在HP-UX下有用）
4、fork 调用系统调用fork时。（fork为关键字，目前此功能只在HP-UX下有用）
5、vfork 调用系统调用vfork时。（vfork为关键字，目前此功能只在HP-UX下有用）
6、load 或 load <libname> 载入共享库（动态链接库）时。（load为关键字，目前此功能只在HP-UX下有用）
7、unload 或 unload <libname> 卸载共享库（动态链接库）时。（unload为关键字，目前此功能只在HP-UX下有用）

tcatch <event>
只设置一次捕捉点，当程序停住以后，应点被自动删除。

四、维护停止点
上面说了如何设置程序的停止点，GDB中的停止点也就是上述的三类。在GDB中，如果你觉得已定义好的停止点没有用了，你可以使用 delete、clear、disable、enable这几个命令来进行维护。

clear
清除所有的已定义的停止点。

clear <function>
clear <filename:function>
清除所有设置在函数上的停止点。

clear <linenum>
clear <filename:linenum>
清除所有设置在指定行上的停止点。

delete [breakpoints] [range...]
删除指定的断点，breakpoints为断点号。如果不指定断点号，则表示删除所有的断点。range 表示断点号的范围（如：3-7）。其简写命令为d。

比删除更好的一种方法是disable停止点，disable了的停止点，GDB不会删除，当你还需要时，enable即可，就好像回收站一样。

disable [breakpoints] [range...]
disable所指定的停止点，breakpoints为停止点号。如果什么都不指定，表示disable所有的停止点。简写命令是dis.

enable [breakpoints] [range...]
enable所指定的停止点，breakpoints为停止点号。

enable [breakpoints] once range...
enable所指定的停止点一次，当程序停止后，该停止点马上被GDB自动disable。

enable [breakpoints] delete range...
enable所指定的停止点一次，当程序停止后，该停止点马上被GDB自动删除。

五、停止条件维护
前面在说到设置断点时，我们提到过可以设置一个条件，当条件成立时，程序自动停止，这是一个非常强大的功能，这里，我想专门说说 这个条件的相关维护命令。一般来说，为断点设置一个条件，我们使用 if关键词，后面跟其断点条件。并且，条件设置好后，我们可以 用condition命令来修改断点的条件。（只有break和watch命令支持if， catch目前暂不支持if）

condition <bnum> <expression>
修改断点号为bnum的停止条件为expression。

condition <bnum>
清除断点号为bnum的停止条件。

还有一个比较特殊的维护命令ignore，你可以指定程序运行时，忽略停止条件几次。

ignore <bnum> <count>
表示忽略断点号为bnum的停止条件count次。

六、为停止点设定运行命令
我们可以使用GDB提供的command命令来设置停止点的运行命令。也就是说，当运行的程序在被停止住时，我们可以让其自动运 行一些别的命令，这很有利行自动化调试。对基于GDB的自动化调试是一个强大的支持。

commands [bnum]
... command-list ...
end

为断点号bnum指写一个命令列表。当程序被该断点停住时，gdb会依次运行命令列表中的命令。
例如：

break foo if x>0
commands
printf "x is %d\n",x
continue
end

断点设置在函数foo中，断点条件是x>0，如果程序被断住后，也就是，一旦x的值在foo函数中大于0，GDB会自动打印出x的值，并继续运行程序。
如果你要清除断点上的命令序列，那么只要简单的执行一下commands命令，并直接在打个end就行了。

七、断点菜单
在 C++中，可能会重复出现同一个名字的函数若干次（函数重载），在这种情况下，break <function>不能告诉GDB要停在哪 个函数的入口。当然，你可以使用break <function(type)>也就是把函数的参数类型告诉GDB，以指定一个函数。否则的话，GDB会给你列 出一个断点菜单供你选择你所需要的断点。你只要输入你菜单列表中的编号就可以了。
(gdb) b String::after
[0] cancel
[1] all
[2] file:String.cc; line number:867
[3] file:String.cc; line number:860
[4] file:String.cc; line number:875
[5] file:String.cc; line number:853
[6] file:String.cc; line number:846
[7] file:String.cc; line number:735
> 2 4 6
Breakpoint 1 at 0xb26c: file String.cc, line 867.
Breakpoint 2 at 0xb344: file String.cc, line 875.
Breakpoint 3 at 0xafcc: file String.cc, line 846.
Multiple breakpoints were set.
Use the "delete" command to delete unwanted
breakpoints.
(gdb)

可见，GDB列出了所有after的重载函数，你可以选一下列表编号就行了。0表示放弃设置断点，1表示所有函数都设置断点。
