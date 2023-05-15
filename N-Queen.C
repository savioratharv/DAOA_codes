#include<stdio.h>
#include<stdlib.h>
int x[100];
int place(int k,int i)
{
  int j;
  for(j=1;j<k;j++)
  {
    if(x[j]==i || abs(x[j]-i)==abs(j-k))
    {
       return 0;
    }
  }
  return 1;
}
void n_queen(int k,int n)
{
  int i,j;
  for(i=1;i<=n;i++)
  {
    if(place(k,i)==1)
    {
      x[k]=i;
      if(k==n)
      {
	printf("Solution: \n");
	for(j=1;j<=n;j++)
	{
	  printf("%d ",x[j]);
	}
	printf("\n");
      }
      else
      {
	n_queen(k+1,n);
      }
    }
  }
}
void main()
{
  int n;
  printf("Enter value of n\n");
  scanf("%d",&n);
  n_queen(1,n);
}