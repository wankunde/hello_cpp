
TARGET=libxthread.so
# TARGET=libxthread.dylib
OBJS=xthread.o
LDFLAGS=-shared
CXXFLAGS=-fpic -std=c++11

$(TARGET):$(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@ $(CXXFLAGS)

clean:
	$(RM) $(TARGET) $(OBJS)

# 指定伪目标
.PHONY: clean *clean
