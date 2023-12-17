#include <stdio.h>


#define HEAP_CAPACITY 10
typedef unsigned char byte;

byte heap[HEAP_CAPACITY] = {0}; 


// Dump heap contents to console
void heap_dump() {
    for (int i = 0; i < HEAP_CAPACITY; i++) {
        printf("%d", heap[i]);
    }
}

void *heapc_alloc(size_t size) {

}

void heapc_free(void* ptr) {
    
} 








int main() {

    for (int i = 0; i < 10; i++) {
        heap[i] = i; 
    }

    heap_dump();

    return 0;
}

