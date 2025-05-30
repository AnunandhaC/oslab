#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
int main()
{
	struct dirent*data;
	struct stat status;
	DIR*dir=opendir(".");
	if(dir==NULL)
	{
		printf("opendir failed");
		exit(1);
	}
	while((data=readdir(dir))!=NULL)
	{
		printf("directory is %s\n",data->d_name);
		int i=(stat(data->d_name,&status));
		if(i!=-1)
		printf("status is %o\n",status.st_mode);
	}
	closedir(dir);
	return 0;
}
