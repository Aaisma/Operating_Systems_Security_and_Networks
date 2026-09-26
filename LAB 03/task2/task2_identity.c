#include <stdio.h>
#include <unistd.h>

int main() {
	//Get current process ID
	pid_t my_pid = getpid();

	//Get parent process ID
	pid_t my_ppid = getppid();

	printf("My PID is: %d\n", my_pid);
	printf("My parent PID is: %d\n", my_ppid);

	printf("Sleeping for 20 seconds...\n");
	sleep(20);


	return 0;
}
