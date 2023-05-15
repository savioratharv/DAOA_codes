#include<stdio.h>
void main()
{
  int s[]={5,1,3,0,5,8};
  int f[]={9,2,4,6,7,9};
  int a[]={1,2,3,4,5,6};
  int n=6;
  int i,j,temp,prev;
  int sol[100],k;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(f[j]>f[j+1])
      {
	 temp=f[j];
	 f[j]=f[j+1];
	 f[j+1]=temp;
	 temp=s[j];
	 s[j]=s[j+1];
	 s[j+1]=temp;
	 temp=a[j];
	 a[j]=a[j+1];
	 a[j+1]=temp;
      }
    }
  }
  sol[0]=a[0];
  k=1;
  prev=0;
  printf("%d -> ",a[0]);
  for(i=1;i<n;i++)
  {
    if(s[i]>=f[prev])
    {
      sol[k]=a[i];
      prev=i;
      k++;
      printf("%d -> ",a[i]);
    }
  }
  printf("\n");
}