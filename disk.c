#include<stdio.h>
#include<stdlib.h>
int i,totseek=0,size,request[20],totreq,initial,cont,choice;
int main()
{
	//int i,totseek=0,size,request[20],totreq,initial;
	printf("enter no of requests");
	scanf("%d",&totreq);
	printf("enter initial head position");
	scanf("%d",&initial);
	printf("enter requests");
	for(i=1;i<=totreq;i++)
	{
		scanf("%d",&request[i]);
	}
	printf("enter disk size");
	scanf("%d",&size);
	cont=1;
	while(cont)
	{
	printf("enter your choice\n1.FCFS\n2.SCAN\n3.C-SCAN\n4.EXIT\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("---FCFS---\n");
			fcfs();
			break;
		case 2:printf("---SCAN---\n");
			scan();
			break;
		case 3:printf("---C-SCAN---\n");
			cscan();
			break;
		case 4:return 0;
	}
	printf("press 1 to continue");
	scanf("%d",&cont);
	}
}
void fcfs()
{
	 printf("%d->",initial);
        for(i=1;i<=totreq;i++)
        {
		printf("%d->",request[i]);
		totseek+=abs(request[i]-initial);
                initial=request[i];
                //printf("%d->",initial);
        }
        printf("total seek time=%d",totseek);
}
void scan()
{
	int dir,j,headpos;
	printf("enter direction right(1) or left(0)");
	scanf("%d",&dir);
	request[0]=0;
	request[totreq+1]=initial;
	request[totreq+2]=size;
	for(i=0;i<=totreq+2;i++)
	{
		for(j=0;j<=(totreq+2)-i-1;j++)
		{
			if(request[j]>request[j+1])
			{
				int temp=request[j];
				request[j]=request[j+1];
				request[j+1]=temp;
			}
		}
	}
	for(i=0;i<=totreq+2;i++)
	{
		if(request[i]==initial)
		{
			headpos=i;
			break;
		}
	}
	if(dir==1)
	{
		for(i=headpos;i<=totreq+2;i++)
		{
			printf("%d->",request[i]);
			totseek+=abs(request[i]-initial);
			initial=request[i];
		}
		for(i=headpos-1;i>0;i--)
		{
			printf("%d->",request[i]);
			totseek+=abs(request[i]-initial);
			initial=request[i];
		}
	}
	else
	{
		for(i=headpos;i>=0;i--)
		{
			printf("%d->",request[i]);
			totseek+=abs(initial-request[i]);
			initial=request[i];
		}
		for(i=headpos+1;i<totreq+2;i++)
		{
			printf("%d->",request[i]);
			totseek+=abs(request[i]-initial);
			initial=request[i];
		}
	}
	printf("total seek time=%d",totseek);
}
void cscan()
{
	 int dir,j,headpos;
        request[0]=0;
        request[totreq+1]=initial;
        request[totreq+2]=size;
        for(i=0;i<=totreq+2;i++)
        {
                for(j=0;j<=(totreq+2)-i-1;j++)
                {
                        if(request[j]>request[j+1])
                        {
                                int temp=request[j];
                                request[j]=request[j+1];
                                request[j+1]=temp;
                        }
                }
        }
        for(i=0;i<=totreq+2;i++)
        {
                if(request[i]==initial)
                {
                        headpos=i;
                        break;
                }
        }
	for(i=headpos;i<=totreq+2;i++)
        {
                        printf("%d->",request[i]);        
                totseek+=abs(request[i]-initial);
                        initial=request[i];
         }
          for(i=0;i<headpos;i++)
          {
                        printf("%d->",request[i]);
                        totseek+=abs(request[i]-initial);
                        initial=request[i];
          }
	  printf("total seek time=%d",totseek);
}
