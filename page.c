#include<stdio.h>
void main()
{
	int rs[20],fr[10],i,j,nop,nof,faults=0,hits=0;
	printf("enter no of pages\n ");
	scanf("%d",&nop);
	printf("enter no of frames\n");
	scanf("%d",&nof);
	for(i=1;i<=nof;i++)
		fr[i]=-1;
	printf("enter reference string\n");
	for(i=1;i<=nop;i++)
	{
		scanf("%d",&rs[i]);
	}
	printf("---FIFO---\n");
	for(i=1;i<=nop;i++)
	{
		for(j=1;j<=nof;j++)
		{
			if(fr[j]==-1)
			{
				faults++;
				fr[j]=rs[i];
				break;
			}
			else if(fr[j]==rs[i])
			{
				hits++;
				break;
			}
		}
		if(j>nof)
		{
			faults++;
			if(faults%nof==0)
				fr[nof]=rs[i];
			else
				fr[faults%nof]=rs[i];
		}
		 for(j=1;j<=nof;j++)
		{
			if(fr[j]==-1)
				printf("-\t");
			else
				printf("%d\t",fr[j]);
		}
		printf("\n");
	}
	printf("total page faults %d\n",faults);
	printf("total page hits %d\n",hits);

	printf("---LRU---\n");
	 for(i=1;i<=nof;i++)
                fr[i]=-1;
	hits=0;
	faults=0;
	 for(i=1;i<=nop;i++)
        {
                for(j=1;j<=nof;j++)
                {
                        if(fr[j]==-1)
                        {
                                faults++;
                                fr[j]=rs[i];
                                break;
                        }
                        else if(fr[j]==rs[i])
                        {
                                hits++;
                                break;
                        }
                }
                if(j>nof)
                {
                        faults++;
			int dup=0;
			for(j=i-nof;j<i;j++)
			{
				for(int k=j+1;k<i;k++)
				{
					if(rs[j]==rs[k])
					{
						dup++;
					}
				}
			}
			int lru=rs[i-nof-dup];
			for(j=1;j<=nof;j++)
			{
				if(lru==fr[j])
				{
					fr[j]=rs[i];
					break;
				}
			}
		}
		 for(j=1;j<=nof;j++)
                {
                        if(fr[j]==-1)
                                printf("-\t");
                        else
                                printf("%d\t",fr[j]);
                }
                printf("\n");
	}
	 printf("total page faults %d\n",faults);
        printf("total page hits %d\n",hits);

	printf("---LFU---\n");
	 for(i=1;i<=nof;i++)
                fr[i]=-1;
        hits=0;
        faults=0;
	int freq[20]={0},pos[20]={0};
         for(i=1;i<=nop;i++)
        {
                for(j=1;j<=nof;j++)
                {
                        if(fr[j]==-1)
                        {
                                faults++;
				fr[j]=rs[i];
				freq[rs[i]]++;
				pos[rs[i]]=i;
				break;
			}
			else if(fr[j]==rs[i])
			{
				hits++;
				freq[rs[i]]++;
				break;
			}
		}
		if(j>nof)
		{
			faults++;
			int similar=0,frame=1,loc=0,lowestfreq=freq[fr[1]];
			for(j=2;j<=nof;j++)
			{
				if(freq[fr[j]]==lowestfreq)
					similar++;
				else if(freq[fr[j]]<lowestfreq)
				{
					lowestfreq=freq[fr[j]];
					similar=0;
				}
			}
			if(similar>0)
			{
				for(j=1;j<=nof;j++)
				{
					if(freq[fr[j]]==lowestfreq)
					{
						if(loc==0||loc>pos[fr[j]])
						{
							loc=pos[fr[j]];
							frame=j;
						}
					}
				}
			}
			fr[frame]=rs[i];
			pos[fr[frame]]=i;
			freq[fr[frame]]=1;
		}
		 for(j=1;j<=nof;j++)
                {
                        if(fr[j]==-1)
                                printf("-\t");
                        else
                                printf("%d\t",fr[j]);
                }
                printf("\n");
        }
         printf("total page faults %d\n",faults);
        printf("total page hits %d\n",hits);
}
