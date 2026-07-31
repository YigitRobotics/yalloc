#include "../include/yalloc.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    if (argc < 3) {
        fprintf(stderr, "Please provide 3 arguments!\n");
        return 1;
    }

    if (strcmp(argv[1], "tests") == 0) {
        basic_allocation(argv[2]);
    }

    return 0;
} 
