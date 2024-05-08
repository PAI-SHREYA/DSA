#include<stdio.h>
#include<stdlib.h>
void Merge(int b[],int p,int c[],int q,int a[])
{
    int i=0,j=0,k=0;
    while(i<p && j<q)
    {
        if(b[i]<=c[j])
        {
            a[k]=b[i];

            i++;
        }
        else
        {
            a[k]=c[j];

            j++;
        }
        k++;
    }
    if(i==p)
    {
        for(i=j;i<q;i++)
        {
            a[k]=c[i];

            k++;
        }
    }
    else
    {
        for(j=i;j<p;j++)
        {
            a[k]=b[j];

            k++;
        }
    }
}
void Merge_sort(int a[],int n)
{
    int b[50],c[50],i,p,q;
    p=ceil(n/2);
    q=n-p;
    if(n>1)
    {
        ///copy a[0,...n/2-1] to b[0,....n/2-1]
        for(i=0;i<p;i++)
        {
            b[i]=a[i];

        }
       int k=0;
        for(i=p;i<n;i++)
        {
            c[k]=a[i];

            k++;
        }
        Merge_sort(b,p);
        Merge_sort(c,q);
        Merge(b,p,c,q,a);
    }

}
int main()
{
   int a[100],n;
   printf("enter size:\n");
   scanf("%d",&n);
   printf("enter array elements:\n");
   for(int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
    for(int i=0;i<n;i++)
   {
       printf("%d ",a[i]);
   }
   Merge_sort(a,n);
   printf("\n sorted array:\n");
   for(int i=0;i<n;i++)
   {
       printf("%d ",a[i]);
   }

}
