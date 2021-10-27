#include <stdio.h>
#include <string.h> // include memset function
#include <fcntl.h>  // include open function
#include <unistd.h> // include write lseek close function

#define BLOCK_SIZE 4096

int main()
{
    char buf[BLOCK_SIZE];
    int fd = open("/tmp/file.hole", O_WRONLY | O_TRUNC | O_CREAT, 0600);
    memset(buf, 'a', BLOCK_SIZE);
    write(fd, buf, BLOCK_SIZE);
    // Make a hole， lseek函数功能: 移动文件读写指针, 表示对要操作的文件fd, 从当前位置 SEEK_CUR, 移动 12K 个offset，实现打洞
    lseek(fd, BLOCK_SIZE * 3, SEEK_CUR); // Make a hole
    write(fd, buf, BLOCK_SIZE);
    lseek(fd, BLOCK_SIZE * 3, SEEK_CUR); // Make a hole
    write(fd, buf, BLOCK_SIZE);
    close(fd);

    return 0;
}