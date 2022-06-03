// O(n^2)

#include <bits/stdc++.h>
using namespace std;

int minPalPartion(string s)
{
    bool palin[s.length()-1][s.length()-1];
    for(int i=0;i<s.length();i++)
     {
         for(int j=0;j<s.length();j++)
          {
            palin[i][j]=false;  
          }
     }
    for(int i=0;i<s.length();i++)
     palin[i][i]=true;
    for(int gap=2;gap<s.length();gap++)
     {
         for(int i=0;i<s.length();i++)
          {
              int j=i+gap-1;
              if(s[i]==s[j])
                {
                    if(gap==2)
                     palin[i][j]=true;
                    else
                     palin[i][j]=palin[i+1][j-1];
                }
               else
                palin[i][j]=false;
          }
     }
    int count[s.length()];
    memset(count,s.length()+1,sizeof(count));
    count[0]=0;
    if(s[0]==s[1])
     count[1]=0;
    else
     count[1]=1;
    for(int j=2;j<s.length();j++)
     {
        for(int i=j;i>0;i--)
         {
            if(palin[i][j])
             count[j]=min(count[j],count[i-1]+1);
         }
     }
    //cout<<count[0]<<endl; 
    // for(int i=0;i<s.length();i++)
    //  cout<<count[i]<<" ";
    // cout<<endl; 
    return count[s.length()-1]; 
}

int main() {
    string str = "abccbc";
    cout << "Min cuts needed for " <<
      "Palindrome Partitioning is " << 
      minPalPartion(str) << endl;
    return 0;
}