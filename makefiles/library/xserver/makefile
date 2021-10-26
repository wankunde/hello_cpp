TARGET=xserver
OBJS=xserver.o
CXX=g++
# 1 -I 指定动态链接库的头文件的位置
CXXFLAGS=-I../xthread -std=c++11
# 2 通过 -L 指定动态链接库的寻找位置, Link-time path
LDFLAGS=-L../xthread
# 3 -l 指定使用动态链接库
LIBS=-lxthread -lpthread

# 4 动态链接库会在程序运行的时候进行加载，可以通过 export LD_LIBRARY_PATH=../xthread 让程序运行的时候到指定目录去加载动态链接库
# 也可以通过 -rpath 选项告诉程序到这个地方加载动态链接库，可以用逗号分隔来配置多个-rpath
GCC_OPTION=-Wl,-rpath=../xthread

$(TARGET):$(OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS) $(LIBS) $(GCC_OPTION)

clean:
	$(RM) $(TARGET) $(OBJS)

# 指定伪目标
.PHONY: clean *clean
