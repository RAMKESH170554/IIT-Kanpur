#include<stdio.h>
int t,n,m,matrix[500][500],mat[500][500],must[1000],nodes[1000],count=0,p1=1;
char visit[1000];
void DFS()
{
	int i,j,k,p,p1=1;
	for(i=1;i<=n;i++)
	{
		if(visit[i]=='F')
		{
			mat[p1][1]=i,k=2,mat[p1][2]=0;
			p1++;
		    for(j=1;j<=n;j++)
			{
				for(p=1;p<k;p++)
				{
					if(matrix[mat[p1-1][p]][j]==3&&visit[j]=='F')
					{
						visit[j]='T';
						visit[i]='T';
						mat[p1-1][k]=j;
						k++;
						count++;
						j=0;
						break;
					}
				}
			}
		}
	}
	for(i=1;i<p1;i++)
	{
		if(mat[i][2]!=0)
		{
			count=count+2;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(visit[i]=='F')
		{
			count=count+2;
		}
	}

}
int main()
{
	int i,j,ii,jj,v,k;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		count=0;
		scanf("%d%d",&n,&m);
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				matrix[j][k]=100;
			}
			visit[j]='F';
		}
		for(j=1;j<=m;j++)
		{
			scanf("%d%d%d",&ii,&jj,&v);
			matrix[ii][jj]=v;
			matrix[jj][ii]=v;
		}
		DFS();
		printf("%d \n",m-count+2);
	}
	//printf("%d\n",p1);
	k=1;
	for(i=1;i<=n;i++)
	{
		k=1;
		while(mat[i][k]!=0)
		{
			printf("%d ",mat[i][k]);
			k++;
		}
		printf("\n");
	}
	return 0;
}
