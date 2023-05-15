#include<stdio.h>
void main()
{
  int i,j;
  int jobs[]={1,2,3,4,5,6};
  int profits[]={200,180,190,300,120,100};
  int deadline[]={5,3,3,2,4,2};
  int solution[100];
  int n=6;
  int temp;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(profits[j]<profits[j+1])
      {
	temp=profits[j];
	profits[j]=profits[j+1];
	profits[j+1]=temp;
	temp=jobs[j];
	jobs[j]=jobs[j+1];
	jobs[j+1]=temp;
	temp=deadline[j];
	deadline[j]=deadline[j+1];
	deadline[j+1]=temp;
      }
    }
  }
  for(i=0;i<n;i++)
  {
    solution[i]=0;
  }
  for(i=0;i<n;i++)
  {
    for(j=n-1;j>=0;j--)
    {
      if(solution[j]==0 && deadline[i]>=j+1)
      {
	printf("Placing %d at %d\n",jobs[i],j);
	solution[j]=jobs[i];
	break;
      }
    }
  }
  for(i=0;i<n;i++)
  {
    printf("%d ",solution[i]);
  }
  printf("\n");
}