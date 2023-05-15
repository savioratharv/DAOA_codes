#include<stdio.h>
void main()
{
  int i,j,k;
  int d[]={0,1,4,6};
  int n=3;
  int N=8;
  int c[100][100];
  int inf=10000;
  int solution[100];
  for(i=0;i<=N;i++)
  {
    c[i][0]=0;
  }
  for(j=0;j<=N;j++)
  {
    c[0][j]=0;
  }
  for(j=1;j<=N;j++)
  {
     for(i=1;i<=n;i++)
     {
       if(i==1)
       {
	 c[i][j]=1+c[1][j-d[i]];
       }
       else if(j<d[i])
       {
	 c[i][j]=c[i-1][j];
       }
       else
       {
	 if((1+c[i][j-d[i]])<c[i-1][j])
	 {
	   c[i][j]=1+c[i][j-d[i]];
	 }
	 else
	 {
	   c[i][j]=c[i-1][j];
	 }
       }
     }
  }
  for(i=0;i<=n;i++)
  {
    for(j=0;j<=N;j++)
    {
      printf("%d ",c[i][j]);
    }
    printf("\n");
  }
  //Backtracking
  k=0;
  i=n;
  j=N;
  while(j>0 && i>0)
  {
    if(c[i][j]==c[i-1][j])
    {
       i--;
     }
     else
     {
       solution[k]=d[i];
       k++;
       printf("%d \n",d[i]);
       j=j-d[i];
     }
   }
}