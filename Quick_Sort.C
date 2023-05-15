#include<stdio.h>
#include<stdlib.h>
int a[]={1,3,4,5,2,1,6,7,3};
int n =sizeof(a)/sizeof(a[0]);
void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
int partition(int low,int high)
{
  int pivot=low;
  int i=low;
  int j=high;
  do
  {
    if(a[i]<=a[pivot])
    {
      i++;
    }
    if(a[j]>=a[pivot])
    {
      j--;
    }
    if(i<=j)
    {
      swap(&a[i],&a[j]);
    }
  }while(i<=j);
  swap(&a[j],&a[pivot]);
  return j;
}
void sort(int low,int high)
{
  int p;
  if(low<high)
  {
    p=partition(low,high);
    sort(low,p);
    sort(p+1,high);
  }
}
void main()
{
  int i,low,high;
  low=0;
  high=n-1;
  sort(low,high);
  printf("Sorted array:\n");
  for(i=0;i<n;i++)
  {
    printf("%d < ",a[i]);
  }
  printf("\n");
}
