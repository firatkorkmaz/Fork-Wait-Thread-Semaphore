/* Semaphore Example-1 */

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


#define MAX_NUM 2
// Each Function Has A "for" Loop to Run Their Own Process for MAX_NUM=2 Times,
// ...but on Each Iteration, Another Function is Activated to Run Its Own Iteration

sem_t sem1, sem2, sem3;

void *f1(void* p){
	for(int i=1; i<=MAX_NUM; i++){
		sem_wait(&sem1);					// This Function Runs First, Because: sem_init(&sem1, 0, 1);
		printf("f1(): %d\n", 1);
		sem_post(&sem2);					// Activating sem2 and Switching to the f2 Function...
	}										// ...which is Waiting for sem2
return NULL;	// Since the Function is void*, This Prevents the Warning: "Control Reaches End of Non-Void Function"
}

void *f2(void* p){
	for(int i=1; i<=MAX_NUM; i++){
		sem_wait(&sem2);					// This Function Runs After the Current Iteration in f1 Function
		printf("f2(): %d\n", 2);
		sem_post(&sem3);					// Activating sem3 and Switching to f3 to Run Its Own Iteration
	}
return NULL;	// Since the Function is void*, This Prevents the Warning: "Control Reaches End of Non-Void Function"
}

void *f3(void* p){
	for(int i=1; i<=MAX_NUM; i++){
		sem_wait(&sem3);					// This Function Runs After the Current Iteration in f2 Function
		printf("f3(): %d\n", 3);
		sem_post(&sem1);					// Activating sem1 and Switching to f1 to Run Its Own Iteration
	}
return NULL;	// Since the Function is void*, This Prevents the Warning: "Control Reaches End of Non-Void Function"
}


int main()
{
	pthread_t p1, p2, p3;
	
	sem_init(&sem1, 0, 1);		// Here, 1 Means This is Initially Activated
	sem_init(&sem2, 0, 0);		// Not Activated Initially
	sem_init(&sem3, 0, 0);		// Not Activated Initially

	pthread_create(&p1, NULL, f1,  (void*)NULL);	// The p1 Thread is Created for f1 Function
	pthread_create(&p3, NULL, f3,  (void*)NULL);	// The p3 Thread is Created for f3 Function
	pthread_create(&p2, NULL, f2,  (void*)NULL);	// The p2 Thread is Created for f2 Function
	
	pthread_join(p2, NULL);		// Since There is An Activation Order by sem# Values,
	pthread_join(p1, NULL);		// ...the Order of This List is Not Important
	pthread_join(p3, NULL);		// The Result will Always Be: "1-2-3-1-2-3-..."
	
	// All the Processes Ended, Destroying the Semaphores
	sem_destroy(&sem1);
	sem_destroy(&sem2);
	sem_destroy(&sem3);

return 0;
}
