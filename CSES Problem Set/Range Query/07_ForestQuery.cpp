#include<iostream>
using namespace std;
typedef long long int lli;
int main()
{
    int n,a,b,c,d;
    lli q;
    char C;
    cin>>n>>q;
    int arr[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>C;
            if(C=='*') arr[i][j]=1;
            else arr[i][j]=0;

            arr[i][j] = arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            if( C== '*')    arr[i][j]++;





        }
    }




    while(q--)
    {
        cin>>a>>b>>c>>d;
        cout<<arr[c][d]-arr[a-1][d]-arr[c][b-1]+arr[a-1][b-1]<<endl;
        //cout<<arr[c-1][d]-arr[a-1][d]-arr[c][b-1]+arr[a][b]<<endl;
    }

    return 0;
}
