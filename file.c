#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char buffer[50];
	char msg[30]="hello welcome";
	int fd=open("file.txt",O_RDWR);
	printf("fd is %d\n",fd);
	if(fd!=-1)
	{
		printf("file opened\n");
		write(fd,msg,sizeof(msg));
		lseek(fd,0,SEEK_SET);
		read(fd,buffer,sizeof(msg));
		printf("%s written to file",buffer);
		close(fd);
	}
	return 0;
}
