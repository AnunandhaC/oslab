#include<stdio.h>
int n,rs[20],f,m[10],i,j,k;
//int hits=0,fault=0;
int main()
{
	printf("enter page num\n");
	scanf("%d",&n);
	printf("enter reference string\n");
	for(i=0;i<n;i++)
		scanf("%d",&rs[i]);
	printf("enter no of frames\n");
	scanf("%d",&f);
	for(i=0;i<f;i++)
		m[i]=-1;
	printf("---fifo---\n");
	fifo();
	for(i=0;i<f;i++)
		m[i]=-1;
	printf("---lru---\n");
	lru();
	for(i=0;i<f;i++)
                m[i]=-1;
	printf("---lfu---\n");
	lfu();
	return 0;
}
void fifo()
{	
	int count=0,hits=0,fault=0;
	for(i=0;i<n;i++)
	{
		int pgfound=0;
		for(j=0;j<f;j++)
		{
			if(m[j]==rs[i])
			{
				pgfound=1;
				hits++;
				break;
			}
		}
		if(!pgfound)//fifo
		{
			m[count]=rs[i];
			count=(count+1)%f;
			fault++;
		}
		//printing
		for(k=0;k<f;k++)
		{
			if(m[k]!=-1)
				printf("%d",m[k]);
			else
				printf("-");
		}
		if(pgfound)
			printf("page hit\n");
		else
			printf("page miss\n");
	}
	printf("total page fault(miss): %d\n",fault);
	printf("total page hits: %d\n",hits);
	return 0;
}
void lru()
{
	int age[10];
	int hits=0,fault=0;
	for(i=0;i<f;i++)
	{
		m[i]=-1;
		age[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		int pgfound=0;
		int replaceindex=-1;
		for(j=0;j<f;j++)
		{
			if(m[j]==rs[i])
			{
				pgfound=1;
				hits++;
				age[j]=i;
				break;
			}
		}
		if(!pgfound)
		{
			int oldest=i;
			//replaceindex=0;
			for(k=0;k<f;k++)
			{
				if(m[k]==-1)//free page
				{
					replaceindex=k;
					break;
				}
				if(age[k]<oldest)
				{
					oldest=age[k];
					replaceindex=k;
				}
			}
			m[replaceindex]=rs[i];
			fault++;
			age[replaceindex]=i;
		}
		 for(k=0;k<f;k++)
                {
                        if(m[k]!=-1)
                                printf("%d",m[k]);
                        else
                                printf("-");
                }
                if(pgfound)
                        printf("page hit\n");
                else
                        printf("page miss\n");
	}
	 printf("total page fault(miss): %d\n",fault);
        printf("total page hits: %d\n",hits);
        return 0;
}
void lfu()
{
	int freq[10];
	int lastused[10];
	int hits=0,fault=0;
	for(i=0;i<f;i++)
	{
		m[i]=-1;
		lastused[i]=-1;
		freq[i]=0;
	}
	for(i=0;i<n;i++)
	{
		int pagefound=0;
		
			for(j=0;j<f;j++)
			{
				if(m[j]==rs[i])
				{
					pagefound=1;
					lastused[j]=i;
					hits++;
					freq[j]++;
					break;
				}
			}
			if(!pagefound)
			{
				int minfreq=10000,oldest=10000,minind=-1;
				int replaceindex=-1;
				for(k=0;k<f;k++)
				{
					if(m[k]==-1)
					{
						replaceindex=k;
						break;
					}
					if(freq[k]<minfreq||(freq[k]==minfreq&&lastused[k]<oldest))
					{
						minfreq=freq[k];
						oldest=lastused[k];
						minind=k;
					}
				}
				if(replaceindex==-1)
					replaceindex=minind;
				lastused[replaceindex]=i;
				freq[replaceindex]=1;
				m[replaceindex]=rs[i];
				fault++;
			}
			 for(k=0;k<f;k++)
                {
                        if(m[k]!=-1)
                                printf("%d",m[k]);
                        else
                                printf("-");
                }
                if(pagefound)
                        printf("page hit\n");
                else
                        printf("page miss\n");
		
	}
	printf("total page fault(miss): %d\n",fault);
        printf("total page hits: %d\n",hits);
        return 0;
}

