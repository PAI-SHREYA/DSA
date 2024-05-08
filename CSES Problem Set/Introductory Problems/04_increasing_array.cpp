#include<iostream>
using namespace std;
int main()
{
    long long int Count=0,n;
    cin>>n;
    long long arr[n];
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
        for(long long int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            Count=Count+arr[i-1]-arr[i];
            arr[i]=arr[i-1];
        }
    }
    cout<<Count<<endl;


    return 0;
}
