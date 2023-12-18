#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdio.h>

#define HEAP_CAP 640000
#define MEM_BLOCK_CAP 1024

typedef unsigned char byte;
typedef struct {
    byte *ptr;
    size_t size;
} Mem_Block;

void *heapc_alloc(size_t size);
void heapc_free(void *ptr);
void heapc_compress();
void compress_mem_blocks(Mem_Block *blocks, int size, int k);
int find_mem_block_index(void *ptr);
double fragmentation_index();
void heap_dump();
void mem_dump();

#endif  // HEAP_H
