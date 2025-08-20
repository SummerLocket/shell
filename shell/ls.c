#include <unistd.h>

int main(){
	//execl("/usr/bin/ls", "ls", "-l", (char *)NULL);
	execlp("ls", "ls", "-1", (char *)NULL);
	// char *const args[] = {"ls", "-l", NULL};
	// execv("/usr/bin/ls", args);
	return 1;
}
