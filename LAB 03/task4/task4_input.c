#include <stdio.h>

int main(){
	char name[50];

	printf("Enter your name: ");

	//Read string from strandard output
	scanf("%s", name);

	printf("Hello, %s! Welcome to OS class.\n", name);
	return 0;
}
