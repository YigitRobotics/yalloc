#ifndef YALLOC_H
#define YALLOC_H

#include <stddef.h>
#include <unistd.h>

typedef struct block_meta {
    int is_free;
    size_t size;
    struct block_meta *next;
} block_meta;

void yfree(void *ptr);
void basic_allocation(char *argv);
void *yalloc(size_t size);

#define META_SIZE sizeof(block_meta)

#endif