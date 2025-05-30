#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
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
		printf("child id:%d",getpid());
		printf("parent id:%d",getppid());
		exit (0);
	}
	else
	{
		printf("parent executing");
		printf("parent id:%d",getppid());
		wait(NULL);
		printf("child exits");
		exit (0);
	}
}
