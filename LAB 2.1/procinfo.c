#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void){
	pid_t my_pid = getpid();
	pid_t my_ppid = getppid();

	time_t current_time = time(NULL);
	struct tm * time_info = localtime(&current_time);

	printf("=== Process Information ===\n");
	printf("My process ID (PID): %d\n", my_pid);
	printf("Parent process ID: %d\n", my_ppid);
	printf("Current Time: %s", asctime(time_info));
	printf("Executable path: /proc/self/exe\n");

	return 0;
}
