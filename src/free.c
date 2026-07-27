#include "../include/yalloc.h"

block_meta *get_block_ptr(void *ptr) {
    return ((block_meta*)ptr - 1); // pointer arithmetic : get header struct
}

void yfree(void *ptr) {
    if (!ptr) {return;}
    block_meta *block = get_block_ptr(ptr);
    block->is_free = 1;
}