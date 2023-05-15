#include<stdio.h>
void main()
{
  int arr[5][5]={{1000,27,12,23,74},
		{27,1000,47,15,71},
		{12,47,1000,28,87},
		{23,15,28,1000,75},
		{74,71,87,75,1000}};
  int selected[100];
  int cut[100];
  int i,j,k;
  int cost,len_sel,len_cut,trav,flag,min,mini,mincol,ccol;
  selected[0]=0;
  len_sel=1;
  cut[0]=0;
  len_cut=1;
  cost=0;
  while(len_cut<5)
  {
  min=1000;
  for(trav=0;trav<len_sel;trav++)
  {
    ccol=selected[trav];
    for(i=0;i<5;i++)
    {
      flag=0;
      for(j=0;j<len_cut;j++)
      {
	if(i==cut[j])
	{
	  flag=1;
	}
      }
      if(flag==1)
      {
	continue;
      }
      else
      {
	if(arr[i][ccol]<min)
	{
	  min=arr[i][ccol];
	  mini=i;
	  mincol=ccol;
	}
      }
    }
  }
  printf("Connecting %d to %d with cost %d \n",mincol,mini,min);
  selected[len_sel]=mini;
  len_sel++;
  cut[len_cut]=mini;
  len_cut++;
  cost=cost+min;
  }
  printf("Final cost is %d \n",cost);
}