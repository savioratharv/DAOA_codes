#include<stdio.h>
void sum_of_subsets(int arr[100],int subset[100],int n,int idx,int sum,int target_sum)
{
  int i;
  if(idx==n)
  {
    if(target_sum==sum)
    {
      printf("{");
      for(i=0;i<n;i++)
      {
	if(subset[i]==1)
	{
	  printf("%d ",arr[i]);
	}
      }
      printf("}\n");
    }
    return;
  }
  subset[idx]=0;
  sum_of_subsets(arr,subset,n,idx+1,sum,target_sum);
  subset[idx]=1;
  sum_of_subsets(arr,subset,n,idx+1,sum+arr[idx],target_sum);
}
void main()
{
  int arr[100];
  int subset[100];
  int i,n;
  int tar;
  printf("Enter size of the array\n");
  scanf("%d",&n);
  printf("Enter elements of the array one by one\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("Enter the target sum\n");
  scanf("%d",&tar);
  sum_of_subsets(arr,subset,n,0,0,tar);
}