/*
Given 2 strings s1 and s2 we need to find the length of the largest common subsequence.
For example:
In s1="abcd" and s2="ad" The common subsequnces are "a" , "ad" and "d". Out of "ad" with length 2 is the longest.

The following code have following time and space complexity:
  Time O(n * m)
  Space O(m)
  where n=length of first string and m=length of second string.
 */
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
