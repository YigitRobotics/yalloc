#include "../include/yalloc.h"

void *global_base = NULL;

block_meta *find_empty_block(block_meta **last, size_t size) {
    block_meta *current = global_base;
    while (current && !(current->is_free && current->size >= size))
    {
        *last = current;
        current = current->next;
    }

    return current;
}

block_meta *request_space(block_meta *last, size_t size) {
    block_meta *block;

    void *requested = sbrk(0);
    void *new_brk = sbrk(size + META_SIZE);

    if (new_brk == (void*)-1) return NULL; // null-check if new_brk didn't work.
}