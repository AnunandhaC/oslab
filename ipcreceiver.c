#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<unistd.h>

int main()
{
	void *shared_memory;
	char buffer[100];
	int shmid=shmget((key_t)1222,1024,0666);
	printf("key of shared memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("process attached at %p",shared_memory);
	printf("data read from shared memory is %s\n",(char *)shared_memory);
	return 0;
}
