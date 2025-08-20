#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid = fork();

	if(pid<0){
		perror("fork failed");
		return 1;
	}
	else if(pid==0){
		printf("I am child, PID: %d\n", getpid());
		exit(0);
	}
	else{
		wait(NULL);
		printf("I am parent, PID: %d\n", getpid());
	}
	return 0;
}
