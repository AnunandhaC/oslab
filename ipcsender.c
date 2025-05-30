#include<sys/ipc.h>//ipc
#include<sys/shm.h>//ipc
#include<stdlib.h>//exit fn
#include<unistd.h>//read fn used
#include<string.h>//string fn
#include<stdio.h>

int main()
{
	void *shared_memory;//point to shared memory segment
	char buffer[100];
	int shmid=shmget((key_t)1222,1024,0666|IPC_CREAT);
	printf("key of shared memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("process attached at %p\n",shared_memory);
	printf("enter data to be written to shared memory:\n");
	read(0,buffer,100);
	strcpy(shared_memory,buffer);
	printf("written:%s",(char *)shared_memory);//convert void* to char* for string
	return 0;
}
