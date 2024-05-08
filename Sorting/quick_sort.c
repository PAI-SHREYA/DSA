#include<stdio.h>
#include<stdlib.h>
int partition(int a[],int l,int r)
{

   int p,i,j,temp;
   p=a[l];
   i=l+1;
   j=r;
   while(i<=j)
   {
       while(i<=j && a[i]<=p)
       {
           i++;
       }
        while(i<=j && a[j]>=p )
       {
           j--;
       }
       if(i<=j){

       temp=a[i];
   a[i]=a[j];
   a[j]=temp;
       }
   }


   temp=a[l];
   a[l]=a[j];
   a[j]=temp;

   return j;
}
void quick_sort(int a[],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(a,l,r);
        quick_sort(a,l,s-1);
        quick_sort(a,s+1,r);
    }
}

int main()
{
    int n,a[10];
    printf("enter n value:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int l,r;
    l=0;r=n-1;
    quick_sort(a,l,r);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
