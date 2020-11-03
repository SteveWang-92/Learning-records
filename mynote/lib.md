
liberr_num.a:
	gcc -c get_num.c $(CFLAGS) $(INCLUDES) -o get_num.o
	gcc -c error_functions.c ename.c.inc $(CFLAGS) $(INCLUDES) -o error_functions.o
	ar -rc liberr_num.a get_num.o error_functions.o //这就是静态编译生成静态库

liberr_num.so:
	gcc -fPIC -c get_num.c error_functions.c $(CFLAGS) $(INCLUDES)//这里注意需要加上-fPIC 
	gcc -shared -o liberr_num.so *.o       //这里注意加上 -shared


INCLUDES = -I /home/wfh/code/include/  //可以这样指定头文件和库的路径
LIBS = -L /home/wfh/code/lib/       

copy: copy.o  
  5     gcc copy.o $(LIBS) $(INCLUDES) -lerr_num -o copy //在进行编译的时候不要链接上库，只有在链接的时候才需要指定链接的库文件
  6 
  7 copy.o: copy.c
  8     gcc -c copy.c  $(LIBS) $(INCLUDES)  -o copy.o 
 
