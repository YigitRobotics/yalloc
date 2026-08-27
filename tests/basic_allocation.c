#include "../include/yalloc.h"
#include <string.h>
#include <stdio.h>

void basic_allocation(char *argv) {
    char *buff = yalloc(strlen(argv) + 1);
    strcpy(buff, argv);

    fflush(stdout);

    printf("\n%s\n", buff);
    yfree(buff);
    buff = NULL;
}