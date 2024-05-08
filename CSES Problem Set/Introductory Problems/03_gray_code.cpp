#include<iostream>
#include<bitset>
#include<math.h>
using namespace std;
long long decimalToBinary(int n){
    long long ans = 0;
    int remainder, i = 1;

    // Until the value of n becomes 0.
    while(n!=0){
        remainder = n % 2;
        ans += remainder*i;
        i = i * 10;
        n = n / 2;
}

    return ans;
    }
int main()
{
    long long int n;
    cin>>n;
    long long int Size=pow(2,n);
    for(long long int i=0;i<Size;i++)
    {

       if(i==0) cout<<"00"<<endl;
       else if(i==1) cout<<"01"<<endl;
       else
        cout<<decimalToBinary(i)<<endl;
    }

    return 0;
}







