#include <stdio.h>  // for io
#include <stdlib.h> // for general funcitons(exit)
#include <unistd.h> // for POSIX syscalls (fork, exec, execvp)
#include <sys/wait.h> // for waitpid() to wait for the child processes

int main(int argc, char *argv[]){ 
	// here argc -- argument count (it is 3 --> prog.c sleep 10) this includes the program name and cmds 
	// argv -- array of strings (cmd line arguments)
	// check if the argc is 3
	if(argc!=3){
		fprintf(stderr, "Usage: %s <command> <argument>\n", argv[0]);
		return 1;
	}
	// now create a new process 
	pid_t pid = fork();

	if(pid<0){
		perror("fork failed");
		return 1;
	}
	if(pid == 0){
		// child process 
		// char *cmd[] = {argv[1], argv[2], NULL};
		execlp(argv[1], argv[1], argv[2], (char *)NULL);
		
		// if execlp returns, there was an error 
		perror("execlp failed");
        exit(1);
    } else {
        // Parent waits for child to complete
        int status;
        waitpid(pid, &status, 0);
        printf("Child process exited with status %d\n", WEXITSTATUS(status));
    }

    return 0;
}
