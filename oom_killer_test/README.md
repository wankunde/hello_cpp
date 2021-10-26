# [参考实验](https://blog.csdn.net/DeliaPu/article/details/112370856?utm_source=app&app_version=4.14.1)

# Environment

Develop in vscode and run in vmware node.

## VSCode 快捷键

* 查看Function List : Command + Shift + O
* 代码格式化快捷键: Shift + Option + F

## C 语言头文件说明

* C的头文件在Linux环境中保存在 `/usr/include` 目录下，在Mac环境中保存在`/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include`目录下
* 我的Mac上安装的是GCC 8.4.0 版本，发现在GCC 安装目录的 `include`, `include-fixed` 等目录下也有很多可用的头文件
* 在Mac上开发程序的时候会提示找不到 `malloc.h` 这个文件，因为在Mac环境中，`malloc.h` 这个文件完整目录为 `/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/sys/malloc.h`, 所以对应的Mac环境编译代码应该是 `#include <sys/malloc.h>`

## GCC 编译选项说明

* 。
* -g 在可执行程序中包含标准调试信息
* -Wall	允许发出Gcc提供的所有有用的报警信息
* -werror	把所有的告警信息转化为错误信息，并在告警发生时终止编译过程

## GCC 中C语言版本说明

* ANSI C(c89) : GCC 默认使用的c89 编译标准，该标准不支持在for循环内定义变量，需要先定义再使用
* c99 : 使用 `-std=c99` 选项使用 c99 编译标准，来开启高级功能
* c11 : 使用 `-std=c11` 选项使用 c11 编译标准，来开启高级功能

## 程序运行和测试

* 在单独运行C程序的时候，查看 `ps -e -o 'pid,comm,args,pcpu,rsz,vsz,stime,user,uid' |grep -E 'mem_alloc|COMMAND' |grep -v grep` 输出中的RSZ 来监控程序使用的真实物理内存
* 使用 `start_container.sh` 脚本启动测试容器，过一段时间会发现容器已经退出， 查看容器 `State` 属性，发现 OOMKilled = true， 说明容器被OOM
```json
# docker inspect --format='{{json .State }}' b9f819c4c5e5  | python -m json.tool

# docker inspect --format='{{json .State }}' b9f819c4c5e5  | jq
{
  "Status": "exited",
  "Running": false,
  "Paused": false,
  "Restarting": false,
  "OOMKilled": true,
  "Dead": false,
  "Pid": 0,
  "ExitCode": 137,
  "Error": "",
  "StartedAt": "2021-10-26T16:15:39.948313498Z",
  "FinishedAt": "2021-10-26T16:16:10.179040572Z"
}
```