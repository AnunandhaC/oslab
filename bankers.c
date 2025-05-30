#include<stdio.h>
int i,j,m,n,k;
int alloc[20][20],max[20][20],avail[20],need[20][20],work[20],seq[20],finish[20];
int main()
{
	printf("enter num of processes");
	scanf("%d",&n);
	printf("enter num of resources");
	scanf("%d",&m);
	printf("enter allocation matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("enter max matrix");
	 for(i=0;i<n;i++)
        {
                for(j=0;j<m;j++)
                {
                        scanf("%d",&max[i][j]);
                }
        }
	printf("enter available resources\n");
	for(j=0;j<m;j++)
	{
		scanf("%d",&avail[j]);
	}
	printf("need matrix\n");
	 for(i=0;i<n;i++)
        {
                for(j=0;j<m;j++)
                {
			need[i][j]=max[i][j]-alloc[i][j];
			printf("%d",need[i][j]);
		}
		printf("\n");
	}
	isSafe();
//	resourcerequest();
	return 0;
}

int isSafe()
{
	int x=0,y;
	for(i=0;i<n;i++)
	{
		work[i]=avail[i];
	}
	for(i=0;i<n;i++)
	{
		finish[i]=0;
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			if(finish[i]==0)
			{
				int flag=0;
				for(j=0;j<m;j++)
				{
					if(need[i][j]>work[j])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					seq[x++]=i;
					for(y=0;y<m;y++)
					{
						work[y]+=alloc[i][y];
						finish[i]=1;
					}
				}		
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(finish[i]==0)
		{
			printf("\nsystem is in unsafe state deadlock possible");
			return 0;
		}
	}
	printf("system is in safe state\nsafe sequence: ");
	for(i=0;i<n;i++)
	{
		printf("P%d ",seq[i]);
	}
	return 1;
}
