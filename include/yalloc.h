#ifndef YALLOC_H
#define YALLOC_H

#include <stddef.h>
#include <unistd.h>

typedef struct block_meta {
    int is_free;
    size_t size;
    struct block_meta *next;
} block_meta;

#define META_SIZE sizeof(block_meta)

#endif