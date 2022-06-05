# Makefile 使用练习

* first_make : 使用 Makefile 编译快速入门
* makefile2 : 练习GCC 编译选项， 编译参数简写，clean 伪目标等
* library : 其中 xthread 先编译动态链接库，xserver 会调用动态链接库

# Makefile 格式

TARGET: DEPENDENCY
	command1
	command2

# Makefile 中的特殊字符

* $@ is target (thing currently being compiled) and is a left-hand side of :
* $< is first prerequisite, the first item on a right-hand side of :
* $^ are all prerequisites, all items on a right-hand side of :

```
%.o : %.cpp
	$(CC) $(CFLAGS) -c $<
```
上面说的是所有.o 文件都是通过 .cpp 文件编译而成,  对应的文件名用 $< 代替

# GCC 编译

1. 预处理，生成预编译文件（.文件）： `gcc –E hello.c –o hello.i`
2. 编译，生成汇编代码（.s文件）：`gcc –S hello.i –o hello.s`
3. 汇编，生成目标文件（.o文件）：`gcc –c hello.s –o hello.o`
4. 链接，生成可执行文件：`gcc hello.o –o hello`

补充说明:
* 编译可以一步到位 `gcc hello.c -o hello`  注意 `-o` 的参数不能以`.o` 结尾


