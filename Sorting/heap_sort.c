#include<stdio.h>
#include<stdlib.h>

void heapify(int a[],int n)
{
    int k,heap,v,j;
    for(int i=n/2;i>=1;i--)
    {
        k=i;
        v=a[k];
        heap=0;
        while(heap!=1 && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(a[j]<a[j+1])
                {
                    j=j+1;
                }
            }
            if(v>=a[j])
            {
                heap=1;
            }
            else
            {
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=v;
    }
}
void heap_sort(int a[],int n)
{
    int temp;
   for(int i=n;i>=1;i--)
   {

        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        heapify(a,i-1);
   }
}
int main()
{
    int a[10],n;
    printf("enter size:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapify(a,n);
    heap_sort(a,n);
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",a[i]);
    }
}
