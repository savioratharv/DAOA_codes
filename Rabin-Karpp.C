#include<stdio.h>
#include<string.h>
void main()
{
  char a[100],b[100];
  int len_a,len_b;
  int i,j,flag,k;
  int na[100],nb[100];
  int sum=0;
  int insum;
  printf("Enter larger string\n");
  scanf("%s",a);
  printf("Enter smaller string\n");
  scanf("%s",b);
  len_a=strlen(a);
  len_b=strlen(b);
  for(i=0;i<len_a;i++)
  {
    na[i]=((int)a[i])-96;
  }
  for(i=0;i<len_b;i++)
  {
    nb[i]=((int)b[i])-96;
    sum=sum+nb[i];
  }
  for(i=0;i<len_a;i++)
  {
    insum=0;
    for(j=i;j<len_b+i;j++)
    {
      insum=insum+na[j];
    }
    if(insum==sum)
    {
      flag=0;
      k=0;
      for(j=i;j<len_b+i;j++)
      {
	 if(a[j]==b[k])
	 {
	   flag++;
	 }
	 k++;
      }
      if(flag==len_b)
      {
	printf("Match found at position%d\n",i);
	break;
      }
    }
  }
}