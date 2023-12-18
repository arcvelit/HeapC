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
void heap_dump();
void mem_dump();
double fragmentation_index();

#endif  // HEAP_H
