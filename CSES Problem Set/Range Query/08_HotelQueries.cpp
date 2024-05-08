
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

typedef long long int LL;

class segTree
{   public:
    vector<LL> tree;

    segTree(LL n)
    {
        tree.resize(4*n);
    }

    void build(LL index,LL low,LL high,vector<LL> arr)
{
    if(low==high)
    {
        tree[index]=arr[low];
        return ;
    }
    LL mid = (low+high)>>1;
    build(2*index+1,low,mid,arr);
    build(2*index+2,mid+1,high,arr);
    tree[index]=max(tree[2*index+1],tree[2*index+2]);

}
void display()
{
    for(LL i=0;i<tree.size();i++) cout<<tree[i]<<" ";
    cout<<endl;
}
void  print(LL index,LL low,LL high,LL val)
{
    if(tree[0]<val)
    {
        cout<<"0 ";
        return;

    }

    if(low==high)
    {
        tree[index]-=val;

            //2*index+1


        cout<<low+1<<" ";
        return;
    }
    LL mid=(low+high)/2;
    if(tree[2*index+1]>=val)
    {
         print(2*index+1,low,mid,val);
        // tree[index]=max(tree[2*index+1],tree[2*index+2]);

    }
    else
    {
         print(2*index+2,mid+1,high,val);
         //tree[index]=max(tree[2*index+1],tree[2*index+2]);

    }
   tree[index]=max(tree[2*index+1],tree[2*index+2]);

}
};

int main()
{
    LL n,m,x;
    cin>>n>>m;
    vector <LL> h(n);
    for(LL i=0;i<n;i++)  cin>>h[i];
    //for(LL i=0;i<m;i++)  cin>>r[i];
    segTree t(n);
    t.build(0,0,n-1,h);
    //t.display();
    //sort(h.begin(),h.end());
    while(m--){
            cin>>x;
        //cout<<endl;
        if(t.tree[0]<x) cout<<"0 ";
        else
        t.print(0,0,n-1,x);
        //t.display();
        //cout<<endl;
    }
        return 0;
}
