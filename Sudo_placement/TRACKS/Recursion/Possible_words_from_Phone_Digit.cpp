#include <bits/stdc++.h>
using namespace std;

string word[8]={"ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"}; 

void phone(int curr,int arr[],char s[],int n)
{
    // cout<<
    if(curr==n)
    {
     cout<<s<<" ";
     return;
    }
    string temp=word[arr[curr]-2];
    for(int i=0;i<temp.length();i++)
     {
        s[curr]=temp[i];
        //cout<<s<<endl;
        phone(curr+1,arr,s,n);
     }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
   {
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
      cin>>a[i];
     char res[n+1];
     res[n]='\0';
     phone(0,a,res,n); 
     cout<<endl;
   }
	return 0;
}