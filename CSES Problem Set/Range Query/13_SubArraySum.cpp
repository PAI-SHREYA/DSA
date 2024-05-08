#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 long long int n,m;
 vector<long long int>arr,seg;
void build(long long int index,long long int left,long long int right,vector<long long int> arr)
{
    if(left==right)
    {
        //if(arr[left]<1) seg[index]=0;
       // else
        //{
            seg[index]=arr[left];
        //}

        return;
    }
    else
    {
        long long int mid=(left+right)/2;
        build(2*index+1,left,mid,arr);
        build(2*index+2,mid+1,right,arr);
        seg[index]=(seg[2*index+1]+seg[2*index+2]);
    }
}
long long int kadane( )
{
     long long int sum=0,i=0,j=0,maxi=0;
    for(i=0;i<n;i++)
    {

        sum+=arr[i];
        if(sum>maxi) maxi=sum;
        else if(sum<0) sum=0;
    }
    return maxi;
}
//void update(long long int index,long long int low,long long int high,long long int k)
int main()
{

    cin>>n>>m;
   // long long int arr[n];
    arr.resize(n);
    seg.resize(4*n);
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
       // ;
    }
    build(0,0,n-1,arr);
    for(long long int i=0;i<seg.size();i++)
        cout<<seg[i]<<" ";
    cout<<endl;


    long long int k,x;
    while(m--)
    {

        cin>>k>>x;
        arr[k-1]=x;
        build(0,0,n-1,arr);
        for(long long int i=0;i<seg.size();i++)
        cout<<seg[i]<<" ";
    cout<<endl;

        cout<<seg[0]<<endl;

    }


    return 0;
}
