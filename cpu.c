#include<stdio.h>

struct process
{
        int id;
        int bt;
        int wt;
        int tt;
        int ct;
        int at;
	int firstentry,finish;
}p[10]={0};
struct process pq[10]={0};
struct process temp;
int i,j,n,tq;
//int orgbt[10];
int main()
{
        printf("enter no of processes\n");
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
                printf("enter process id,arrival time and burst time for process %d\n",i);
                scanf("%d%d%d",&p[i].id,&p[i].at,&p[i].bt);
		 //orgbt[i]=p[i].bt;
        }
        int choice;
        while(1)
        {
                printf("enter your choice\n1.RR\n2.SJF\n3.exit");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
				printf("enter time quantum");
				scanf("%d",&tq);
                                printf("----RR scheduling----\n");
                                rr();
				break;
			case 2:printf("---SJF---\n");
				sjf();
				break;
                }
	}
}
void rr()
{
	//int orgbt[10];
	for(i=1;i<=n;i++)
	{	
		pq[i]=p[i];
		//pq[i].bt=orgbt[i];
	}
	//sort based on at
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(pq[j].at>pq[j+1].at)
			{
				temp=pq[j];
				pq[j]=pq[j+1];
				pq[j+1]=temp;
			}
		}
	}
	struct process rq[100];
	int rear,front,entryt,exitt,procidx;
	rear=front=procidx=1;
	entryt=exitt=0;
	rq[rear++]=pq[procidx];
	printf("gantt chart\n");
	while(front!=rear)
	{
		if(rq[front].firstentry==0)
		{
			rq[front].firstentry=1;
			if(rq[front].at>exitt)
			{
				exitt=rq[front].at;
			}
		}
		if(rq[front].at>exitt)
		{
			entryt=rq[front].at;
		}
		else
		{
			entryt=exitt;
		}
		exitt=entryt+tq;
		if(rq[front].bt>tq)
		{
			rq[front].bt-=tq;
		}
		else
		{
			rq[front].finish=1;
			exitt=entryt+rq[front].bt;
			//rq[front].ct=exitt;
			rq[front].bt=0;
			p[rq[front].id].ct=exitt;
			p[rq[front].id].tt=exitt-rq[front].at;
			p[rq[front].id].wt=p[rq[front].id].tt-p[rq[front].id].bt;
		}
		while((procidx<n)&&(pq[procidx+1].at<=exitt))
			rq[rear++]=pq[++procidx];
		if(rq[front].finish!=1)
			rq[rear++]=rq[front];
		printf("p%d(%d)\t",rq[front].id,exitt);
		front++;
		if((front==rear)&&(procidx<n))
			rq[rear++]=pq[++procidx];
	}
	printf("\nprocess\tat\tbt\tct\ttt\twt\n");
	float ttt,twt;
	ttt=twt=0;
	for(i=1;i<=n;i++)
	{
		printf("\np%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
		ttt+=p[i].tt;
		twt+=p[i].wt;
	}
	printf("sum&avg of tt-%f,%f",ttt,ttt/n);
	printf("sum&avg of wt-%f,%f",twt,twt/n);
}
void sjf()
{
	//int orgbt[10];
        for(i=1;i<=n;i++)
	{
                pq[i]=p[i];
		pq[i].bt=orgbt[i];
	}
        //sort based on at
        for(i=1;i<n;i++)
        {
                for(j=1;j<=n-i;j++)
                {
                        if(pq[j].at>pq[j+1].at)
                        {
                                temp=pq[j];
                                pq[j]=pq[j+1];
                                pq[j+1]=temp;
                        }
                }
        }
        struct process rq[100];
        int rear,front,entryt,exitt,procidx;
        rear=front=procidx=1;
        entryt=exitt=0;
        exitt=pq[front].at;
	while((pq[procidx].at<=exitt)&&(procidx<n))
	{
		rq[rear++]=pq[procidx++];
	}
	printf("Gantt chart\n");
	while(front!=rear)
	{
		for(i=front;i<rear;i++)
		{
			for(j=front;j<rear-1;j++)
			{
				if(rq[j].bt>rq[j+1].bt)
				{
					struct process temp=rq[j];
					rq[j]=rq[j+1];
					rq[j+1]=temp;
				}
			}
		}
		entryt=exitt;
		exitt=entryt+rq[front].bt;
		p[rq[front].id].ct=exitt;
		p[rq[front].id].tt=exitt-rq[front].at;
		p[rq[front].id].wt=p[rq[front].id].tt-rq[front].bt;
		 while((pq[procidx+1].at<=exitt)&&(procidx<n))
        	{
                	rq[rear++]=pq[++procidx];
        	}
		printf("%d|p%d|%d\t",entryt,rq[front].id,exitt);
		front++;
		if((front==rear)&&(procidx<n))
		{
			exitt=pq[procidx+1].at;
			 while((pq[procidx+1].at<=exitt)&&(procidx<n))
                	{
                        	rq[rear++]=pq[++procidx];
			}        
		}
	}
	printf("\nprocess\tat\tbt\tct\ttt\twt\n");
        float ttt,twt;
        ttt=twt=0;
        for(i=1;i<=n;i++)
        {
                printf("\np%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
                ttt+=p[i].tt;
                twt+=p[i].wt;
        }
        printf("sum&avg of tt-%f,%f",ttt,ttt/n);
        printf("sum&avg of wt-%f,%f",twt,twt/n);
}
