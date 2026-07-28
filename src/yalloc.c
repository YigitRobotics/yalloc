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

    block = requested;

    if (last) last->next = block;

    block->size = size;
    block->next = NULL;
    block->is_free = 0;

    return block;
}

void *yalloc(size_t size) {
    block_meta *block;
    if (size <= 0) return NULL;

    if (!global_base) {
        block = request_space(NULL, size);
        if (!block) return NULL;
        global_base = block;
    }
    else {
        block_meta *last = global_base;
        block = find_empty_block(&last, size);
        if (!block) {
            block = request_space(last, size);
            if (!block) return NULL;
        }
        else {
            block->is_free = 0;
        }
        
    }

    return (block + 1);
}
