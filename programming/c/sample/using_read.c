/**
 * this is much faster then using_fgets.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char buff[10000] = ""; // fast and dirty, without malloc
    char all_content[28722] = ""; // fast and dirty
    
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    int fd = open("postslist.json", O_RDONLY);
    ssize_t n;
    while ((n = read(fd, all_content, 28723)) == -1);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    size_t content_length = strlen(all_content);

    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
    printf("%s\n", all_content);
    printf("strlen: %ld\n", content_length);
    printf("d: %ld microsecond\n", delta_us);
    return 0;
}
