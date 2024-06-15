#include<iostream>
using namespace std;
 int longestCommonSubsequence(string text1, string text2) {
        vector <int> prev(text2.length()+1 ,0),curr(text2.length()+1,0);
        for(int i=1;i<text1.length()+1;i++)
        {
           for(int j=1;j<text2.length()+1;j++)
           {
            if(text1[i-1]==text2[j-1])
            {
                curr[j]=prev[j-1]+1;
            }
            else
            {
                curr[j]=max(curr[j-1],prev[j]);
            }
           }
           prev=curr;
        }
        return prev[text2.length()];
        
    }

int main()
{
  
  string s1,s2;
  cin>>s1>>s2;
  cout<<"Length of LCS is "<<longestCommonSubsequence(s1, s2);
  return 0;
}
