/**
 * this is much slower then using_read.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <stdint.h>
#include <time.h>

int main()
{
    char buff[10000] = ""; // fast and dirty, without malloc
    char all_content[28722] = ""; // fast and dirty
    FILE *fp;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    fp = fopen("postslist.json", "rb");
    if (fp == NULL) {
        fprintf(stderr, "cannot open file\n");
    }
    while (fgets(buff, 10000, fp)) { // why like this? because it returns when it hits a newline
        strcat(all_content, buff);
    }

    size_t content_length = strlen(all_content);
    fclose(fp);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
    printf("%s\n", all_content);
    printf("d: %ld microsecond\n", delta_us);
    return 0;
}