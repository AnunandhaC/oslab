#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#define MAX_BUFFER_SIZE 5

int x=0;//x is item
sem_t mutex,full,empty;
void producer()
{
	sem_wait(&empty);//wait until an empty space
	sem_wait(&mutex);//decrements mutex value to 0 for lock
	x++;//produces item
	printf("producer produces item %d\n",x);
	sem_post(&full);//signalling there is an item
	sem_post(&mutex);//release lock mutex=1
}
void consumer()
{
	sem_wait(&full);
	sem_wait(&mutex);
	 printf("consumer consumes item %d\n",x);
	x--;
	sem_post(&empty);
	sem_post(&mutex);
}
int main()
{
	int choice;
	//initializing semaphores
	sem_init(&mutex,0,1);//initial=1
	sem_init(&full,0,0);//full=0
	sem_init(&empty,0,MAX_BUFFER_SIZE);
	while(1)
	{
		printf("1.producer\n2.consumer\n3.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:if(x<MAX_BUFFER_SIZE)
					producer();
				else
					printf("buffer is full\n");
				break;
			case 2:if(x>0)
					consumer();
				else
					printf("buffer is empty\n");
				break;
			case 3:sem_destroy(&mutex);
				sem_destroy(&full);
				sem_destroy(&empty);
				exit(0);
		}
	}
	return 0;
}
