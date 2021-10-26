# [Linux File Hole](https://www.halolinux.us/kernel-reference/file-holes.html)
实现Linux文件打洞(Make a hole), 这样会给该文件预留一定的空间。
例如, `datahole.c` 写出了这样一个文件: [DataSize 400][HoleSize 12000][DataSize 400][HoleSize 12000][DataSize 400]
当我们 `ll` 查看该文件的时候显示，该文件Size 为 3600， 根据文章中介绍，Block hole 只有在发生读写的时候，文件系统才会触发Block的分配。