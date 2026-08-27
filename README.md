
# YigitMemoryAllocator (yalloc)

## Status

I've been planning to build a memory allocator for a long time, and this project is the result of that effort.

The allocator is intentionally minimal in scope and currently focuses on core allocation functionality. Most security-related protections have not yet been implemented, although the allocator is already usable in its current state.

Planned improvements include:
- Thread-safety mechanisms (mutexes, spinlocks, etc.) [DONE ✅]
- Race condition prevention
- Additional security hardening
- Performance optimizations

At the moment, the allocator should be considered experimental and not yet suitable for security-critical or highly concurrent workloads.

## Leak Summary

I ran Valgrind and ran some simple tests. You can review the `leak_summary.txt` file.

If you want to generate a Valgrind report, you can use the following command.

```bash
valgrind --leak-check=full ./bin/app tests testing_text \
    > output.txt 2> leak_summary.txt
```

## Design

The allocator currently uses a simple free-list based design.

Allocation works by performing a first-fit search through the list of blocks (`find_free_block`) and returning the first suitable free block.

When `free()` is called, the block is simply marked as available and returned to the free list.

Currently, the allocator does not implement:

- Block splitting
- Block coalescing
- Arena-based allocation
- Advanced fragmentation mitigation

As a result, memory fragmentation can become significant during long-running workloads.