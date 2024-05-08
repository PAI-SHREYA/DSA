#include<iostream>
using namespace std;
int main()
{
    int t;
    long long int a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a>b) swap(a,b);

        if(a*2<b) cout<<"NO"<<endl;
        else
        {
            a%=3;
            b%=3;
            if(a>b) swap(a,b);

            if((a==0 and b==0) or (a==1 and b==2 )){
              cout<<"YES"<<endl;
            }
            else {cout<<"NO"<<endl;}
        }




    }

    return 0;
}
