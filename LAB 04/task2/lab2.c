#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int global_init = 100; //Data segment
int global_uninit; //BSS segment

int main() {
	int local_var = 30; //Stack
	int *heap_var = (int *)malloc(sizeof(int)); //Heap
	*heap_var = 500;

	printf("---Memory Segment Address---\n\n");

	printf("global_init: %p (Data Segment)\n", (void *)&global_init);
	printf("global_uninit: %p (BSS Segment)\n", (void *)&global_uninit);
	printf("local_var: %p (Stack Segment)\n", (void *)&local_var);
	printf("heap_var data: %p (Heap Segment)\n", (void *)heap_var);

	uintptr_t stack_addr = (uintptr_t)&local_var;
	uintptr_t heap_addr = (uintptr_t)heap_var;
	uintptr_t diff = (stack_addr > heap_addr) ? (stack_addr - heap_addr) : (heap_addr - stack_addr);

	printf("\nDifference Between Stack and Heap: %llu bytes (0x%llx)\n", (unsigned long long)diff, (unsigned long long)diff);


	free(heap_var);
	return 0;
}
