#include<stdio.h>
#include<string.h>
#define FREE 0
#define BUSY 1
void main()
{
	struct process
	{
		int id,psize,blockno;
	}p[10]={0};
	struct block
	{
		int num,bsize,fragment,status;
	}b[10]={0};
	struct block bcopy[10];
	int nump,numb,i,j,totfrag=0;
	printf("enter num of processes\n");
	scanf("%d",&nump);
	printf("enter num of blocks\n");
	scanf("%d",&numb);
	printf("enter process size\n");
	for(i=1;i<=nump;i++)
	{
		scanf("%d",&p[i].psize);
		p[i].blockno=0;
		p[i].id=i;
	}
	printf("enter block size\n");
	for(i=1;i<=numb;i++)
	{
		scanf("%d",&b[i].bsize);
		b[i].num=i;
		b[i].status=FREE;
		bcopy[i]=b[i];
	}
	printf("---FIRST FIT---\n");
	for(i=1;i<=nump;i++)
	{
		for(j=1;j<=numb;j++)
		{
			if(b[j].status==FREE)
			{
				if(p[i].psize<=b[j].bsize)
				{
					b[j].status=BUSY;
					b[j].fragment=b[j].bsize-p[i].psize;
					p[i].blockno=j;
					break;
				}
			}
		}
	}
	printf("\nprocess num\t\tprocess size\t\tblock num\t\tblocksize\t\tfragment\n");
	for(i=1;i<=nump;i++)
	{
		if(p[i].blockno==0)
			continue;
		printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].psize,p[i].blockno,b[p[i].blockno].bsize,b[p[i].blockno].fragment);
		totfrag+=b[p[i].blockno].fragment;
	}
	printf("total internal fragmentation %d\n",totfrag);
	
	printf("---BEST FIT---\n");
//	p[10]={0};
//	b[10]={0};
	//memset(p, 0, sizeof(p));
	//memset(b, 0, sizeof(b));
	 for(i=1;i<=nump;i++)
        {
		p[i].blockno=0;
	}
	int bestblock=0;
	int bestblockno=0;
	for(i=1;i<=numb;i++)
	{
		b[i]=bcopy[i];
		//b[i].status=FREE;
		if(b[i].bsize>bestblock)
			bestblock=b[i].bsize;
	}
	totfrag=0;
	int temp;
	temp=bestblock;
	for(i=1;i<=nump;i++)
	{
		bestblock=temp;
		bestblockno=0;
		for(j=1;j<=numb;j++)
		{
			if(b[j].status==FREE)
			{
				if((b[j].bsize>=p[i].psize)&&(bestblock>=(b[j].bsize-p[i].psize)))
				{
					bestblockno=j;
					bestblock=b[j].bsize-p[i].psize;
				}
			}
		}
		if(bestblockno!=0)
		{
			b[bestblockno].status=BUSY;
			b[bestblockno].fragment=b[bestblockno].bsize-p[i].psize;
			p[i].blockno=bestblockno;
		}
	}
	 printf("\nprocess num\t\tprocess size\t\tblock num\t\tblocksize\t\tfragment\n");
        for(i=1;i<=nump;i++)
        {
                if(p[i].blockno==0)
                        continue;
                printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].psize,p[i].blockno,b[p[i].blockno].bsize,b[p[i].blockno].fragment);
                totfrag+=b[p[i].blockno].fragment;
        }
        printf("total internal fragmentation %d\n",totfrag);

	printf("\n---WORST FIT---\n");
	for(i=1;i<=nump;i++)
	{
		p[i].blockno=0;
	}
	for(i=1;i<=numb;i++)
	{
		b[i]=bcopy[i];
	}
	bestblockno=0;
	bestblock=0;
	totfrag=0;
	 for(i=1;i<=nump;i++)
        {
                bestblockno=0;
		bestblock=0;
                for(j=1;j<=numb;j++)
                {
                        if(b[j].status==FREE)
                        {
                                if((b[j].bsize>=p[i].psize)&&(bestblock<=(b[j].bsize-p[i].psize)))
                                {
                                        bestblockno=j;
                                        bestblock=b[j].bsize-p[i].psize;
					printf("%d process allocated to %d block",p[i].psize,b[i].bsize);
                                }
                        }
                }
                if(bestblockno!=0)
                {
                        b[bestblockno].status=BUSY;
                        b[bestblockno].fragment=b[bestblockno].bsize-p[i].psize;
                        p[i].blockno=bestblockno;
                }
        }
	 printf("\nprocess num\t\tprocess size\t\tblock num\t\tblocksize\t\tfragment\n");
        for(i=1;i<=nump;i++)
        {
                if(p[i].blockno==0)
                        continue;
                printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].psize,p[i].blockno,b[p[i].blockno].bsize,b[p[i].blockno].fragment);
                totfrag+=b[p[i].blockno].fragment;
        }
        printf("total internal fragmentation %d\n",totfrag);
}
