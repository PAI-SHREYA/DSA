#include<iostream>
#include <limits.h>
using namespace std;

void build(long long int index,long long int low,long long int high,long long int arr[],long long int seg[] )
{
    if(low==high)
    {
        seg[index]=arr[low];
        return;
    }
    long long int mid=(low+high)/2;
    build(2*index+1,low,mid,arr,seg);
    build(2*index+2,mid+1,high,arr,seg);
    seg[index]=min(seg[2*index+1],seg[2*index+2]);
}
void update(long long int index,long long int low,long long int high,long long int node,long long int seg[],long long int x)
{
   if(low==high)
   {
       seg[index]=x;
       return;
   }
   long long int mid=(low+high)/2;
   if(node<mid)
      update(2*index+1,low,mid,node,seg,x);
   else
      update(2*index+2,mid+1,high,node,seg,x);
    seg[index]=min(seg[2*index+1],seg[2*index+2]);
}
long long int range(long long int index,long long int low,long long int high,long long int l,long long int h,long long int seg[])
{

    if(low>h || high<l)  return INT_MAX;
    if(low>=l && high<=h) return seg[index];
    long long int mid=(low+high)/2;
    long long int left=range(2*index+1,low,mid,l,h,seg);
    long long int right=range(2*index+2,mid+1,high,l,h,seg);
    return min(left,right);
}

int main()
{
    long long int n,q;
    cin>>n>>q;
    long long int arr[n],seg[4*n];

    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build(0,0,n-1,arr,seg);

    int a;
    long long int l,r;
    for(long long int i=0;i<q;i++)
    {

        cin>>a>>l>>r;
        if(a==1)
        {
             update(0,0,n-1,l-2,seg, r);
        }
        else if(a==2)
        {
            cout<<range(0,0,n-1,l-1,r-1,seg)<<endl;
        }
    }



    return 0;
}
