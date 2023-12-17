#include <stdio.h>

#define HEAP_CAP 1000
#define MEM_BLOCK_CAP 10
typedef unsigned char byte;
typedef struct {
    byte *ptr;
    size_t size;
} Mem_Block;

Mem_Block mem_blocks[MEM_BLOCK_CAP] = {0};
byte heap[HEAP_CAP] = {0}; 

byte *heap_ptr = heap;
Mem_Block *mem_blocks_ptr = mem_blocks;

size_t heap_size = 0;
size_t mem_blocks_size = 0;


void *heapc_alloc(size_t size) {

    if ( heap_size + size > HEAP_CAP || mem_blocks_size + 1 > MEM_BLOCK_CAP) {
        printf("Heap error: overflow occurred\n");
        return NULL;
    }

    void *mem = heap_ptr;

    // Update heap
    heap_ptr += size;
    heap_size += size;

    // Update blocks
    Mem_Block new_block = {mem, size};
    *mem_blocks_ptr = new_block;

    mem_blocks_size++;
    mem_blocks_ptr++;

    return mem;
}

// Free blocks of memory
void heapc_free(void* ptr) {

} 

// Reduce fragmentation
void heapc_compress() {

}

// Print contents of heap
void heap_dump() {
    for (int i = 0; i < HEAP_CAP; i++) {
        printf("%c", heap[i]);
    }
}


int main() {


    char *alpha = (char*)heapc_alloc(26*sizeof(char));

    for (size_t i = 0; i < 26; i++) {
        alpha[i] = 'A' + i;
    }

    heap_dump();

    
    return 0;
}

