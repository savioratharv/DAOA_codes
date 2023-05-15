#include <stdio.h>
int c[100];
int p[100];
int w[100];
float ratio[100];
void sort(int n)
{
    int i,j,temp;
    float t2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(ratio[j]<ratio[j+1])
            {
                t2=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=t2;
                temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
            }
        }
    }
}
void main()
{
    int i,n;
    float cw,rw,tp;
    float frac;
    printf("Enter number of processes: \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        c[i]=i+1;
        printf("Enter profit\n");
        scanf("%d",&p[i]);
        printf("Enter weight\n");
        scanf("%d",&w[i]);
        ratio[i]=(float)p[i]/(float)w[i];
    }
    printf("Input\n");
    for(i=0;i<n;i++)
    {
        printf("%d   %d   %d   %f\n",c[i],p[i],w[i],ratio[i]);
    }
    sort(n);
    printf("Sorted\n");
    for(i=0;i<n;i++)
    {
        printf("%d   %d   %d   %f\n",c[i],p[i],w[i],ratio[i]);
    }
    cw=0.00;
    tp=0.00;
    printf("Enter max weight\n");
    scanf("%f",&rw);
    for(i=0;i<n;i++)
    {
        if(rw==0.00)
        {
            break;
        }
        else if(w[i]<=rw)
        {
            rw=rw-w[i];
            cw=cw+w[i];
            tp=tp+p[i];
            printf("Current Weight is %f\n",cw);
            printf("Remaining Weight is %f\n",rw);
            printf("Total Profit is %f\n",tp);
        }
        else if(w[i]>rw)
        {
            frac=rw/w[i];
            rw=rw-frac*w[i];
            cw=cw+frac*w[i];
            tp=tp+frac*p[i];
            printf("Current Weight is %f\n",cw);
            printf("Total Profit is %f\n",tp);
        }
    }
}
