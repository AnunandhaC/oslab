#include<stdio.h>
int p,b,blocksize[10],processsize[10],i,j;
int blockallocated[10],allocation[10];
int totalint=0,totalext=0;
int main()
{
	printf("enter no of blocks");
	scanf("%d",&b);
	printf("enter num of process");
	scanf("%d",&p);
	printf("enter blocksizes");
	int blockSizeCopy[b];
	for(i=0;i<b;i++)
	{
		scanf("%d",&blocksize[i]);
		 blockSizeCopy[i] = blocksize[i];
	}
	printf("enter processsize");
	for(i=0;i<p;i++)
	{
		scanf("%d",&processsize[i]);
	}
	printf("---first fit---\n");
	firstfit();
	display();
	 for (int i = 0; i < b; i++) {
        blocksize[i] = blockSizeCopy[i];
    }

	printf("---best fit----\n");
	bestfit();
	display();
	for(int i=0;i<b;i++)
	{
		blocksize[i]=blockSizeCopy[i];
	}
	printf("---worst fit---\n");
	worstfit();
	display();
}
void firstfit()
{
	totalint=0,totalext=0;
	for(i=0;i<p;i++)
	{
		allocation[i]=-1;
	}
	for(j=0;j<b;j++)
	{
		blockallocated[j]=0;
	}
	for(i=0;i<p;i++)
	{
		for(j=0;j<b;j++)
		{
			if(blocksize[j]>=processsize[i])
			{
				allocation[i]=j;
				blockallocated[j]=1;
				blocksize[j]-=processsize[i];
				break;
			}
		}
	}
	for(i=0;i<b;i++)
	{
		if(blockallocated[i])
		{
			totalint+=blocksize[i];
		}
		else
		{
			totalext+=blocksize[i];
		}
	}	
}
void bestfit()
{
	 totalint=0,totalext=0;
        for(i=0;i<p;i++)
        {
                allocation[i]=-1;
        }
        for(j=0;j<b;j++)
        {
                blockallocated[j]=0;
        }
        for(i=0;i<p;i++)
        {
		int bestindex=-1;
                for(j=0;j<b;j++)
                {
			if(blocksize[j]>=processsize[i])
			{
				if(bestindex==-1||blocksize[j]<blocksize[bestindex])
				{
					bestindex=j;
				}
			}
		}
		if(bestindex!=-1)
		{
			allocation[i]=bestindex;
			blockallocated[bestindex]=1;
			blocksize[bestindex]-=processsize[i];
		}
	}
	 for(i=0;i<b;i++)
        {
                if(blockallocated[i])
                {
                        totalint+=blocksize[i];
                }
                else
                {
                        totalext+=blocksize[i];
                }
        }
	
}
void worstfit()
{
	totalint=0,totalext=0;
	for(i=0;i<p;i++)
		allocation[i]=-1;
	for(i=0;i<b;i++)
		blockallocated[i]=0;
	for(i=0;i<p;i++)
	{
		int worstindex=-1;
		for(j=0;j<b;j++)
		{
			if(blocksize[j]>=processsize[i])
			{
				if(worstindex==-1||blocksize[j]>blocksize[worstindex])
				{
					worstindex=j;
				}
			}
		}
		if(worstindex!=-1)
		{
			allocation[i]=worstindex;
			blockallocated[worstindex]=1;
			blocksize[worstindex]-=processsize[i];
		}
	}
	for(i=0;i<b;i++)
	{
		if(blockallocated[i])
			totalint+=blocksize[i];
		else
			totalext+=blocksize[i];
	}
}
void display()
{
	printf("processno\tprocesssize\tblocknum\n");
	for(i=0;i<p;i++)
	{
		printf("%d\t%d\t",i+1,processsize[i]);
		if(allocation[i]!=-1)
			printf("%d\n",allocation[i]+1);
		else
			printf("not allocated\n");
	}
	printf("total internal fragmentation:%d\n",totalint);
	printf("total external fragmentation:%d\n",totalext);
}
