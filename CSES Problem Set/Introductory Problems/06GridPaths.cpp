#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    char c='?';
    int i=0, res=0;
    while(s[i])
    {
        if(s[i]==c)
        {
            res++;
        }
        i++;
    }
    res=((res)*4)+((s.length())-res);
    cout<<res<<endl;

    return 0;
}
