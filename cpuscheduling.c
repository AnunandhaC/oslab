#include<stdio.h>
#include<stdlib.h>

struct process
{
	int pid;
	int bt;
	//int at;
	int wt;
	int tat;
	int ct;
	int at;
}p[10];
//int tottat=0,totwt=0;
struct process temp;
int i,j,n;
int main()
{
	//struct process temp;
	printf("enter no of processes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		//p[i].pid=i+1;
		printf("enter process id,burst time and arrival time for process %d\n",i+1);
		scanf("%d%d%d",&p[i].pid,&p[i].bt,&p[i].at);
	}
	int choice;
	while(1)
	{
		printf("enter your choice\n1.FCFS\n2.SJF\n3.exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
	 			printf("----FCFS scheduling----\n");
				fcfs();
				break;
			case 2:printf("----SJF scheduling----\n");
				sjf();
				break;
			case 3:printf()
			case 3:exit(0);
		}
	}
}
void fcfs()
{
	int tottat=0,totwt=0;
	//sort process according to at
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].at>p[j].at)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	//p[0].wt=0;
	//p[0].tat=p[0].bt;
	p[0].ct=p[0].at+p[0].bt;
	//totwt=p[0].wt;
	//tottat=p[0].tat;
	for(i=1;i<n;i++)//calculating ct
	{
		if(p[i].at>p[i-1].ct)
		{
			p[i].ct=p[i].at+p[i].bt;
		}
		else
		{
			p[i].ct=p[i-1].ct+p[i].bt;
		}
	}
	//calculating tat and wt
	for(i=0;i<n;i++)
	{
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		totwt+=p[i].wt;
		tottat+=p[i].tat;
	}
	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	printf("total waiting time=%d\n",totwt);
	printf("total turnaround time=%d\n",tottat);
	printf("average waiting time=%.2f\n",(float)totwt/n);
	printf("average turnaround time=%.2f\n",(float)tottat/n);
	return 0;
}

void sjf()
{
	int tottat=0,totwt=0;
	//sort according to burst time
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].bt>p[j].bt)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	p[0].ct=p[0].at+p[0].bt;
	for(i=1;i<n;i++)
	{
		if(p[i].at>p[i-1].ct)
		{
			p[i].ct=p[i].at+p[i].bt;
		}
		else
		{
			p[i].ct=p[i-1].ct+p[i].bt;
		}
	}
	for(i=0;i<n;i++)
	{
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		tottat+=p[i].tat;
		totwt+=p[i].wt;
	}
	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	 printf("total waiting time=%d\n",totwt);
        printf("total turnaround time=%d\n",tottat);
        printf("average waiting time=%.2f\n",(float)totwt/n);
        printf("average turnaround time=%.2f\n",(float)tottat/n);
        return 0;
}
