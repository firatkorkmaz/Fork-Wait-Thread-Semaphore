/* Semaphore Example-2 */

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


sem_t mutex1, mutex2;

void *thread(void* arg) {
	sem_wait(&mutex1); 				// Waiting for mutex1 Semaphore
	
	printf("\nEntered into the Critical Section...\n");
	sleep(1);
	printf("Completed.\n");
	
	sem_post(&mutex2);				// Sending mutex2 Semaphore
	
return NULL;	// Since the Function is void*, This Prevents the Warning: "Control Reaches End of Non-Void Function"
}


int main() {

	printf("Main Function Started...\n");
	
	pthread_t th1, th2;				// Definition of "th1" and "th2" Threads
	
	//sem_init(&mutex1, 0, 1);		// Initiation of mutex1 with Activation
	sem_init(&mutex1, 0, 0);		// Initiation of mutex1 without Activation
	sem_init(&mutex2, 0, 0);		// Initiation of mutex2 without Activation
	
	pthread_create(&th1, NULL, thread, NULL);	// "th1" Thread for the Void* Function is Created
	sleep(1);
	sem_post(&mutex1);				// The Void* Function is Activated and It Runs Now
	
	
	sem_wait(&mutex2);				// 1st Run is Completed
	printf("Returned from 1st Run!\n");
	
	
	pthread_create(&th2, NULL, thread, NULL);	// "th2" Thread for the Void* Function is Created
	sleep(1);
	sem_post(&mutex1);				// The Void* Function is Activated and It Runs Now
	
	
	sem_wait(&mutex2);				// 2nd Run is Completed
	printf("Returned from 2nd Run!\n");
	
	//Join Threads with the Main Thread
	sleep(1);		// After 1 Second...
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	sem_destroy(&mutex1);
	sem_destroy(&mutex2);

return 0;
}
