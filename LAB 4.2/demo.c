#include <stdio.h>
#include <stdlib.h>

//1. BSS Section (Uninitialized global data, defaults to 0)
int bss_global_var;

int main() {
	//2. Stack Section (Local variable)
	int stack_local_var = 42;

	//3. Heap Section (Dynamically allocated memory)
	int *heap_ptr = (int *) malloc(sizeof(int));
	if (heap_ptr == NULL) {
		return -1;

	}
	*heap_ptr = 99; //Assign value to heap memory

	printf("Addresses: \n");
	printf("BSS (Global): %p\n", (void*)&bss_global_var);
	printf("Stack (Local): %p\n", (void*)&stack_local_var);
	printf("Heap (Dynamic): %p\n", (void*)heap_ptr);


	//Breakpoint here to inspect memory
	printf("Ready for GDB inspection!\n");

	free (heap_ptr);
	return 0;
}
