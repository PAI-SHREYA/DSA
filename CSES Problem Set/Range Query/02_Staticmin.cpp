#include<iostream>
#include<limits.h>
using namespace std;
long long int query(long long int index,long long int low,long long int high,long long int l,long long int r,long long int seg[])
{
    if(low>r || high<l) return INT_MAX;
    if(low>=l && high<=r) return seg[index];
    long long int mid=(low+high)/2;
    long long int left=query(2*index+1,low,mid,l,r,seg);
    long long int right=query(2*index+2,mid+1,high,l,r,seg);
    return min(left,right);


}
void build(long long int index,long long int low,long long int high,long long int arr[],long long int seg[])
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
int main()
{
    long long int n,q;
    cin>>n>>q;
    long long int arr[n],seg[n*4];
    for(long long int i=0;i<n;i++)
    {

        cin>>arr[i];
    }

    build(0,0,n-1,arr,seg);
    long long int l,r;


    for(int i=0;i<q;i++)
    {
        cin>>l>>r;
        cout<<query(0,0,n-1,l-1,r-1,seg)<<endl;

    }

    return 0;
}
