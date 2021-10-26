#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buf[400];
    int fd = open("file.hole", O_WRONLY|O_TRUNC|O_CREAT, 0600);
    memset(buf, 'a', 400);
    write(fd, buf, 400);
    // Make a hole， lseek函数功能: 移动文件读写指针, 表示对要操作的文件fd, 从当前位置 SEEK_CUR, 移动 1200 个offset，实现打洞
    lseek(fd, 1200, SEEK_CUR); // Make a hole
    write(fd, buf, 400);
    lseek(fd, 1200, SEEK_CUR); // Make a hole
    write(fd, buf, 400);
    close(fd);

    return 0;
}