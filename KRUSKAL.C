#include<stdio.h>
void main()
{
  int i,j,ignore;
  int sum=0;
  int min;
  int mini;
  int minj;
  int val[10],vali[10],valj[10];
  int a[5][5]={{0,4,6,0,3},{4,0,5,0,0},{6,5,0,1,0},{0,0,1,0,2},{3,0,0,2,0}};
  for(i=0;i<5;i++)
  {
    mini=0;
    minj=0;
    min=100;
    for(j=0;j<5;j++)
    {
      if(a[i][j]<min && a[i][j]!=0)
      {
	min=a[i][j];
	mini=i;
	minj=j;

      }
    }
    val[i]=min;
    vali[i]=mini;
    valj[i]=minj;
  }
  for(i=0;i<5;i++)
  {
    if(vali[i+1]==valj[i] && vali[i]==valj[i+1])
    {
      ignore=i;
    }
  }
  for(i=0;i<5;i++)
  {
    if(i!=ignore)
    {
      sum=sum+val[i];
    }
  }
  printf("Shortest Distance is : %d\n",sum);
}