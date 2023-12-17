#include <stdio.h>


#define HEAP_CAP 1000
#define MEM_BLOCK_CAP 10
typedef unsigned char byte;
typedef struct {
    byte *ptr;
    size_t size;
} Mem_Block;

size_t heap_size = 0;

Mem_Block heap_blocks[MEM_BLOCK_CAP] = {0};
byte heap[HEAP_CAP] = {0}; 

byte *heap_ptr = heap;

void *heapc_alloc(size_t size) {

    if (heap_size + size > HEAP_CAP) {
        printf("Heap error: overflow occurred\n");
        return NULL;
    }

    // Does not keep track of blocks
    void *mem = heap_ptr;
    heap_ptr += size;
    heap_size += size;

    return mem;

}

void heapc_free(void* ptr) {

} 



int main() {


    char *alpha = (char*)heapc_alloc(26*sizeof(char));

    for (size_t i = 0; i < 26; i++) {
        alpha[i] = 'A' + i;
    }

    // printf("\n%zu ", heap_ptr);

    printf("Heap ptr at position: %d\n",heap_ptr-heap);
    for (int i = 0; i < HEAP_CAP; i++) {
        printf("%c", heap[i]);
    }

    return 0;
}

