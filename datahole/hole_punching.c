#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
// 注意在CentOS 7中还需要包含linux/falloc.h：
#include <linux/falloc.h>
#include <sys/stat.h>
#include <assert.h>

int main()
{
    off_t offset;
    int ret;
    struct stat st;

    // do allocation
    printf("===== Allocation =====\n");
    int fd = open("/tmp/file_nohole", O_RDWR | O_CREAT, 0755);
    assert(fd != -1);
    ret = fallocate(fd, 0, 0, 1024000);
    assert(ret == 0);
    offset = lseek(fd, 0, SEEK_END);
    printf("SEEK_END offset:\t %d\n", offset);
    fstat(fd, &st);
    printf("fstat:\t\t\t file size %d, %d allocated (%d Bytes).\n",
           st.st_size, st.st_blocks, st.st_blocks * 512);
    close(fd);

    // do dedallocation
    printf("==== Deallocation ====\n");
    fd = open("/tmp/file_withhole", O_RDWR | O_CREAT, 0755);
    assert(fd != -1);
    ret = fallocate(fd, 0, 0, 1024000);
    // 释放 400K 到 1000K 这段存储空间
    ret = fallocate(fd, FALLOC_FL_PUNCH_HOLE | FALLOC_FL_KEEP_SIZE, 409600, 1024000);
    assert(ret == 0);
    offset = lseek(fd, 0, SEEK_END);
    printf("SEEK_END offset:\t %d\n", offset);
    fstat(fd, &st);
    printf("fstat:\t\t\t file size %d, %d allocated (%d Bytes).\n",
           st.st_size, st.st_blocks, st.st_blocks * 512);
    close(fd);
    return 0;
}
