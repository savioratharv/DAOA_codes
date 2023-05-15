#include<stdio.h>
void main()
{
  int c[100][100];
  int w[4]={0,2,3,3};
  int p[4]={0,1,2,4};
  int max[7]={0,1,2,3,4,5,6};
  int target=6;
  int i,j;
  for(i=0;i<4;i++)
  {
    for(j=0;j<7;j++)
    {
      if(i==0 || j==0)
      {
	c[i][j]=0;
      }
      else if(w[i]>j)
      {
	c[i][j]=c[i-1][j];
      }
      else
      {
	if(p[i]+c[i-1][j-w[i]]>c[i-1][j])
	{
	  c[i][j]=p[i]+c[i-1][j-w[i]];
	}
	else
	{
	  c[i][j]=c[i-1][j];
	}
      }
    }
  }
  for(i=0;i<4;i++)
  {
    for(j=0;j<7;j++)
    {
      printf("%d ",c[i][j]);
    }
    printf("\n");
  }
  //Backtracking
  i=3;
  j=6;
  while(j>0)
  {
    if(c[i][j]!=c[i-1][j])
    {
       printf("%d\n",w[i]);
       target=target-w[i];
       j=target;
       i=i-1;
    }
  }
}