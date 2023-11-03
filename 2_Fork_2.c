/* Fork Example-2 */

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int main(){
  int pid;
  
  pid = fork();
  if(pid == 0){
	  printf("Child Process A:\npid :%d\nppid:%d\n\n", getpid(), getppid());
  }
  else if(pid > 0){
	  wait(NULL);
	  pid = fork();
	  if(pid == 0){
		printf("Child Process B:\npid :%d\nppid:%d\n\n", getpid(), getppid());
	  }
	  else if(pid > 0){
		  wait(NULL);
		  pid=fork();
		  if(pid == 0){
				printf("Child Process C:\npid :%d\nppid:%d\n\n", getpid(), getppid());
		  }
		  else if(pid > 0){
			wait(NULL);
			printf("Parent Process:\npid :%d\nppid:%d\n",getpid(),getppid());
		  }
      }
  }
  
return 0;
}
