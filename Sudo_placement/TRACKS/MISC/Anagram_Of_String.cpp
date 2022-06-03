#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
 int i,sum=0;    
 int a[26]={0};
 for(i=0;i<str1.length();i++)
  {
    a[str1[i]-'a']++;  
  }
 for(i=0;i<str2.length();i++)
  {
    a[str2[i]-'a']--;  
  }
 for(i=0;i<26;i++)
  {
    sum+=abs(a[i]);  
  }
 return sum;  
 // Your code goes here
}