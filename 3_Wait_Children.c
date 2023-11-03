/* Wait Children Example */

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int i = 0;
int stop = 3;

void forker(int inpid, int limit){

	if(inpid == 0){
		sleep(1);
		printf("I am Child: %d\n", i);
	}
	else if(inpid > 0){
		i++;
		if(i > limit){
			sleep(1);
			printf("I am Parent *\n");
			return;
		}
		inpid = fork();
		wait(NULL);
		forker(inpid, stop);
	}

return;
}


int main(){
	
	int pid = getpid();
	forker(pid, stop);

return 0;
}
