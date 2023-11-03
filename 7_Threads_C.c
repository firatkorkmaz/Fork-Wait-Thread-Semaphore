/* Thread Example in C */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *worker(void *data){
	
    char *name = (char*)data;					// Getting String Data
	int r;										// Variable for Random Integer
	
	for(int i=0; i < 7; i++){
		r = (rand() % (1000 - 20 + 1)) + 20;	// Random Integer within: [20, 1000]
		
		// On Each Iteration, There will Be Different Durations Before printf()
		for(int j=0; j < r*10000; j++)
			for(int k=0; k < (int)r/20; k++);
			
		printf("Thread Name: %s\n", name);		// The printf() process of the void* Function
	}
 
    printf("Thread %s is Done!\n", name);

return NULL;
}


int main(void){
	
    pthread_t th1, th2;							// Definition of Threads
    srand(time(NULL));
    
    pthread_create(&th2, NULL, worker, "Y");	// Creating "th2" Thread for the void* Function
    pthread_create(&th1, NULL, worker, "X");	// Creating "th1" Thread for the void* Function
    
    pthread_join(th1, NULL);					// Joining the "th1" Thread
	pthread_join(th2, NULL);					// Joining the "th2" Thread
    
    printf("\nExiting from Main Program...\n");
    sleep(1);
    
    return 0;
}
