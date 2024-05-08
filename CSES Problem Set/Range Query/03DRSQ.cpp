#include<limits>
#include<iostream>
using namespace std;
void build(long long int i,long long int n,long long int fen[],long long int add)
{


    while(i<=n)
    {

        fen[i]+=add;

        i+=(i& -i);


    }
}
void update(long long int i,long long int n,long long int fen[],long long int add,long long int w)
{




    while(i<=n)
    {

        fen[i]+=add-w;

        i+=(i& -i);


    }
}
long long int sum(long long int r, long long int fen[]) {
    long long int s = 0;
    while (r >0) {

        s += fen[r]; // Adjust index to 0-based
        r -= r & -r;
    }
    return s;
}

long long int range(long long int l,long long int r,long long int fen[])
{

    return sum(r,fen)-sum(l-1,fen);
}

int main()
{
    long long int n,q;
    cin>>n>>q;
    long long int fen[n+1],arr[n];

    for(long long int i=0;i<=n;i++)
    {
      fen[i]=0;
    }

    for(long long int i=0;i<n;i++)
    {

       cin>>arr[i];
       build(i+1,n,fen,arr[i]);
    }

    long long int a,b,c;
    while(q--)
    {
        cin>>a>>b>>c;
        if(a==1)
        {
            update(b,n,fen,c,arr[b-1]);
            arr[b-1]=c;


        }
        else if(a==2)
        {
            cout<<range(b,c,fen)<<endl;

        }

    }

    return 0;
}
