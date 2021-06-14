#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>

int n = 50000;
int a[50000]; //Define a to an array with 50000 elements

sem_t s0, s1, s2; //Define 3 sempaphore, 0 for empty, 2 for full, 1 for in running 


void* S1(){
	int i;
	while(1){
		
		sem_wait(&s0);
		sem_wait(&s1);
		sem_getvalue(&s2, &i);
		
		a[i] = rand() % (n-1); //Adding a random value at position i
		i++;
		printf("Pushed new element to array a, number of elements is: %2d \n", i);
		
		
		//After having elements, we can now unlock the popping
		sem_post(&s1);
		sem_post(&s2);
	}
}

void* S2(){
	int i;
	while(1){
		
		sem_wait(&s2);
		sem_wait(&s1);
		sem_getvalue(&s2, &i);
		
		if(i <= 0){
			printf("Nothing to pop from array. Array a is empty.\n");
		}
		else{
			int takePos = (rand() % i) - 1; //Find a random position
			int sa = a[takePos]; //Save the pop element into sa
			printf("Popped %2d from array, number of elements remain: %2d \n", sa, i);
			for(int temp = takePos; temp < i; temp++){
				a[temp] = a[temp+1]; //Move all the element behind temp to be forward
			}
		}
			
		//After popping, we can unlock the empty and running stage
		sem_post(&s1);
		sem_post(&s0);
	}

}

int main(void){
	sem_init(&s1, 0, 1);
	sem_init(&s2, 0, 0);
	sem_init(&s0, 0, n);
	
	pthread_t t1,t2;
	pthread_create(&t1, NULL, S1, NULL);
	pthread_create(&t2, NULL, S2, NULL);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	while(1){};

}
