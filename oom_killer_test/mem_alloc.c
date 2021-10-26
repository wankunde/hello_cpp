#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BLOCK_SIZE (1024 * 1024)

int main(int argc, char **argv) 
{
    int thr, i;
    char *p;
    if(argc != 2) {
        printf("Usage: mem_alloc <num (MB)>\n");
        exit(0);
    }

    thr = atoi(argv[1]);
    printf("Allocating," "set to %d Mbytes\n", thr);
    sleep(30);
    for(i=0;i<thr;i++) {
        // 分配 1M 大小的 bytes
        p = malloc(BLOCK_SIZE);
        memset(p, 0x00, BLOCK_SIZE);
        // 每隔10秒
        // sleep(10);
    }
    // 睡眠1min
    sleep(60);

    return 0;
}