
Link : https://www.bilibili.com/video/BV1vR4y1u77h
# CMakeList.txt 编写

* 编译使用外部构建模式

# 外部编译模式

```
cd build
cmake ..
make
make install
```

# INSTALL

DESTINATION 默认 `CMAKE_INSTALL_PREFIX=/usr/local`, 相对路径是在这个路径的后面

# Library

* 静态库: `.a` 或者 `.lib` 结尾，静态编译
* 动态库: `.so` 或者 `.dll` 结尾，动态加载

安装 library: `cmake -D CMAKE_INSTALL_PREFIX=/usr ..`
