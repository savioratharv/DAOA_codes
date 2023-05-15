#include<stdio.h>
int cost[4][4]={{1000,10,15,20},
		{5,1000,9,10},
		{6,13,1000,12},
		{8,8,9,1000}};
int visited[4]={0,0,0,0};
int c=0;
int n=4;
int min_city(int city)
{
  int i;
  int min=1000;
  int next_city=999,kmin;
  for(i=0;i<n;i++)
  {
    if(visited[i]==0 && i!=city && cost[city][i]<min)
    {
      next_city=i;
      min=cost[i][0]+cost[city][i];
      kmin=cost[city][i];
    }
  }
  if(min != 1000)
  {
    c=c+kmin;
  }
  return next_city;
}
void find_path(int start_city)
{
  int i,next_city;
  int current_city=start_city;
  visited[start_city]=1;
  printf("%d -> ",start_city);
  for(i=0;i<n;i++)
  {
    next_city=min_city(current_city);
    visited[next_city]=1;
    if(next_city==999)
    {
      break;
    }
    cost[next_city][i]=1000;
    cost[i][next_city]=1000;
    printf("%d -> ",next_city);
    current_city=next_city;
  }
  c=c+cost[current_city][0];
  printf("%d\n",start_city);
}
void main()
{
  int start_city=0;
  find_path(0);
}