# HeapC
Implementation of a minimalist Heap structure using the C language.

## Scope
This is to better understand how memory allocation works by implementing one of my own. The heap is created as a `byte[]` array and the user may allocate memory blocks using the `heapc_allocate()` method. The system also keeps track of allocated memory by storing `Mem_Block`'s into an array.

![image](https://github.com/arcvelit/HeapC/assets/86175300/a009e71b-ce2a-4532-ac56-bc539388659b)

 Each block is a structure that holds a pointer to the allocated memory and the size of that block in the heap.

![image](https://github.com/arcvelit/HeapC/assets/86175300/66be1c66-bae3-4fc7-9306-61c283c085e0)


## Challenge

The main challenge is to avoid as much as possible the use of the C heap. Except for the fact that it would be circular to implement a data structure while making use of the same concept, allocating memory to the C heap would keep memory available for the lifetime of the process. However, we only want to free using the heapC API, and manage the personalized heap. In other words, the aim was to control absolutely all data manipulation.


## Improvement
This implementation is limited because the space is not optimized once the fragmentation index is too high (percent spacing between blocks). Also, the heap could be implemented using other data structures, for instance using a tree. There are many algorithms to optimize structure (i.e. [AVL trees](https://en.wikipedia.org/wiki/AVL_tree)) or to search through heap trees. 
