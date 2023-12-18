#include "heap.h"

byte heap[HEAP_CAP] = {0}; 
Mem_Block mem_blocks[MEM_BLOCK_CAP] = {0};

size_t heap_size = 0;
size_t mem_blocks_size = 0;

void *heapc_alloc(size_t size) {

    if (heap_size + size > HEAP_CAP || mem_blocks_size + 1 > MEM_BLOCK_CAP) {
        printf("HEAP ERROR: OVERFLOW\n");
        return NULL;
    }

    // Update the heap
    void *alloc_ptr = heap+heap_size;
    heap_size += size;

    // Register a block of memory
    Mem_Block new_block = {alloc_ptr, size};
    mem_blocks[mem_blocks_size++] = new_block;

    return alloc_ptr;
}

// Free a block of memory
void heapc_free(void* ptr) {

    int freed_index = find_mem_block_index(ptr);

    // Pointer not registered
    if (freed_index < 0) return;

    // Keep the mem blocks contiguous
    compress_mem_blocks(mem_blocks, mem_blocks_size, freed_index);
    mem_blocks_size--;

    // Compress heap if 50%  of size is free  
    if (fragmentation_index() > 0.50)
        heapc_compress();
}

// Reset fragmentation
void heapc_compress() {
    
}

// Perform compression by overwriting blocks to the left
void compress_mem_blocks(Mem_Block* blocks, int size, int k) {
    for (int  i = k; i < size - 1  ; i++) {
        blocks[i] = blocks[i + 1];
    }
}

// Get the index of a registered pointer
int find_mem_block_index(void *ptr) {

    int index = -1; 
    for (size_t i = 0; i < mem_blocks_size; i++) {
        if (mem_blocks[i].ptr == ptr) {
            index = i;
            break;
        }
    } 
    return index;
}

// Percent spacing in heap
double fragmentation_index() {
    if (heap_size == 0) return 0.0;

    int block_sizes = 0;
    for (size_t i = 0; i < mem_blocks_size; i++) {
        block_sizes += mem_blocks[i].size;
    }

    return 1.0 - (float)block_sizes / (float)heap_size;
}

// Print contents of heap
void heap_dump() {
    for (size_t i = 0; i < heap_size; i++) {
        printf("%c", heap[i]);
    }
    printf("\n");
}

// Print sizes of memory blocks
void mem_dump() {
    if (mem_blocks_size == 0) return; 
    size_t i;
    for (i = 0; i < mem_blocks_size - 1; i++) {
        printf("| %d ", mem_blocks[i].size);
    }
    printf("| %d |\n", mem_blocks[i].size);
}