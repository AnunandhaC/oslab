#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed");
		exit (1);
	}
	else if(pid==0)
	{
		printf("child executing");
		execlp("./addition","addition","45","15",(char*)NULL);
		exit(0);
	}
	else
	{
		printf("parent executing");
		wait(NULL);
		printf("parent:child finished");
		exit(0);
	}
}
