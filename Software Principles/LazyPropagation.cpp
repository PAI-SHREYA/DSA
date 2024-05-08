#include<iostream>
#include<vector>
using namespace std;
class ST
{
    vector<long long int> seg,lazy;
public:
    ST(long long int n)
    {
        seg.resize(4*n);
        lazy.resize(4*n);
    }
     void Build (long long int index,long long int low,long long int high,vector <long long int> arr)
     {

         if(low==high)
         {
             seg[index]=arr[low];
             return;
         }
         long long int mid=(low+high)>>1;
         Build(2*index+1,low,mid,arr);
         Build(2*index+2,mid+1,high,arr);
         seg[index]=seg[2*index+1]+seg[2*index+2];
         return;
     }
     void update(long long int index,long long int low,long long int high,long long int l,long long int r,long long int val)
     {

         /// update previous
         if(lazy[index]!=0)
         {
            seg[index]+=(high-low+1)*lazy[index];

             //seg[index]+=lazy[index];
             ///propagate downwards for the remaining nodes to be updated
            if(low!=high)
             {
               lazy[2*index+1]+=lazy[index];
               lazy[2*index+2]+=lazy[index];
             }
             lazy[index]=0;
         }
         ///no overlap
         if(l>high ||  r<low) return;

         ///complete overlap
         if(low>=l && high<=r)
         {
             seg[index]+= (high-low+1)*val;
             if(low!=high)
             {
                 lazy[2*index+1]+=val;
                 lazy[2*index+2]+=val;
             }
             return;
         }

         ///partial overlap
         long long int mid=(low+high)>>1;
         update(2*index+1,low,mid,l,r,val);
         update(2*index+2,mid+1,high,l,r,val);

         seg[index]=seg[2*index+1]+seg[2*index+2];
     }
     long long int pos(long long int index,long long int low,long long int high,long long int k)
     {

         if(low==high)
         {
             cout<<"lazy index "<<lazy[index]<<endl;
             seg[index]+=lazy[index];
             lazy[index]=0;
             return seg[index];
         }
         long long int mid=(low+high)/1;
         if(k<=mid)  return pos(2*index+1,low,mid,k);
         else  return pos(2*index+2,mid+1,high,k);
     }
     void display()
     {
         for(long long int i=0;i<seg.size();i++)
         {
             cout<<seg[i]<<"  ";
         }
         cout<<endl<<endl;
     }
};

int main()
{
    long long int n,w;
    cin>>n>>w;
    vector<long long int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ST q(n);
    q.Build(0,0,n-1,arr);
    q.display();
    long long int a,b,c,d;
    while(w--)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c>>d;
            q.update(0,0,n-1,b-1,c-1,d);
            q.display();
        }
        else
        {
            cin>>b;
            cout<<q.pos(0,0,n-1,b-1)<<endl;
        }
    }

    return 0;
}
