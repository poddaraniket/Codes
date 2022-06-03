#include <bits/stdc++.h>
using namespace std;

void equalSum(string s,int index,int n,int diff)
{
    if(index==n)
     {
      if(diff==0)    
        cout<<s<<endl;
      return; 
     }
    for(int i=0;i<=9;i++)
     {
        if(index==0 && i==0)
         continue;
        else
         {
             if(index%2==0)
               equalSum(s+(char)(i+48),index+1,n,diff+i);
             else
               equalSum(s+(char)(i+48),index+1,n,diff-i);
         }
     }
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	equalSum("",0,n,0);
	return 0;
}
