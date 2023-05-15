#include<stdio.h>
int a[]={1,4,3,2,4,67,9,32,42,24};
int n=sizeof(a)/sizeof(a[0]);
void merge(int low,int mid,int high)
{
  int i=low;
  int j=mid+1;
  int k=low;
  int b[100];
  while(i<=mid && j<=high)
  {
    if(a[i]<a[j])
    {
      b[k]=a[i];
      i++;
      k++;
    }
    else
    {
      b[k]=a[j];
      j++;
      k++;
    }
  }
  while(i<=mid)
  {
    b[k]=a[i];
    k++;
    i++;
  }
  while(j<=high)
  {
    b[k]=a[j];
    k++;
    j++;
  }
  for(i=low;i<=high;i++)
  {
    a[i]=b[i];
  }
}
void merge_sort(int low,int high)
{
  int mid;
  if(low<high)
  {
    mid=(low+high)/2;
    merge_sort(low,mid);
    merge_sort(mid+1,high);
    merge(low,mid,high);
  }
}
void main()
{
  int low=0;
  int high=n-1;
  int i;
  merge_sort(low,high);
  printf("Sorted array: \n");
  for(i=0;i<n;i++)
  {
    printf("%d < ",a[i]);
  }
  printf("\n");
}