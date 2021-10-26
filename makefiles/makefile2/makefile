
TARGET=myapp
# 自动推导 *.o 文件
OBJS=hello_c++.o xdata.o
LIBS=-lpthread -I../test_include
# @ 不显示执行命令
# - 失败后不停止

# $(TARGET): hello_c++.cpp xdata.cpp

CXXFLAGS = -pthread -fPIC -std=c++11

$(TARGET): $(OBJS)
	echo "begin build $(TARGET)"
	$(CXX) $^ -o $@ $(LIBS)
	@echo "build success!!!"

clean:
	$(RM) $(TARGET) $(OBJS)

# 指定伪目标
.PHONY: clean *clean
