/* Fork Example-1 */

#include <sys/wait.h> 
#include <unistd.h> 
#include <stdio.h>


int main()
{
    pid_t pid = fork();
    
    if(pid > 0){
        // Parent:
        wait(NULL);	// Parent Waits Its Child to Finish
        printf("\nParent: %d, pid: %d\n", pid, getpid());
    }
    
    else if(pid == 0){
        // Child:
        sleep(1);
        printf("Child: %d, my pid : %d\n", pid, getpid());
        printf("My Parent's pid  : %d\n", getppid());
        
    }
    else{
        printf("Error!\n");
    }
    
    
return 0;
}
