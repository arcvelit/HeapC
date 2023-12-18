#include "heap.h"

int main() {

    // 
    char *alphabet = (char*)heapc_alloc(26*sizeof(char));
    char *alpha = (char*)heapc_alloc(28*sizeof(char));
    char *array_lower = (char*)heapc_alloc(5*sizeof(char));

    heapc_free(alpha);

    for (size_t i = 0; i < 26; i++) {
        alphabet[i] = 'A' + i;
    }

    for (size_t i = 0; i < 5; i++) {
        array_lower[i] = 'a' + i;
    }

    heap_dump();
    mem_dump();

    printf("Fragmented [%.2f]", fragmentation_index());
    
    return 0;
}

