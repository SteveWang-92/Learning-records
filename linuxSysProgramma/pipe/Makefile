#一个规则:
#	目标:依赖条件(tab缩进)

DIR_INC = ./include
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin

#两个函数:
#匹配当前工作目录所有的.c文件,将文件名赋值给src
SRC = $(wildcard ${DIR_SRC}/*.c)
#将src中包含.c的文件替换为.o,并赋值给obj
OBJ = $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${SRC}))

TARGET = main
BIN_TARGET = ${DIR_BIN}/${TARGET}
#flag
CC = gcc
CFLAGS = -g -Wall -I${DIR_INC}


#All指定makefile的终极目标
${BIN_TARGET}:${OBJ}
	$(CC) $(OBJ)  -o $@
${DIR_OBJ}/%.o:${DIR_SRC}/%.c
	$(CC) $(CFLAGS) -c  $< -o $@
#为什么有rm之前有- ,其作用是遇到不存在的文件不报错,继续执行
.PHONY:clean
clean:
	find ${DIR_OBJ} -name *.o -exec rm -rf {} \;
#3个自动变量
#$@:在规则的命令中,表示规则中的目标
#$^:在规则的命令中,表示所有的依赖条件
#$<:在规则的命令中,表示第一个依赖条件



