#include <stdio.h>

// 1. Data Selection (Initialized global data)
int data_global_var = 0x12345678;

// 2. Rodata Section (Read-only string constant literal)
const char *text_string_literal = "Text_Segment_Verification";

// 3. Text Section (Function execution code block)
void check_execution() {
	printf("Executing within the text segment instruction block.\n");
}

int main() {
	printf("Addressing:\n");
	printf("Data (Global Initialized): %p\n", (void*) &data_global_var);
	printf("Text String (ROData): %p\n", (void*) text_string_literal);
	printf("Text Code (Function): %p\n", (void*) &check_execution);

	check_execution();

	// Breakpoint here to inspect text and data layers
	printf("Ready for Text/Data Segment Inspection!\n");
	return 0;
}
