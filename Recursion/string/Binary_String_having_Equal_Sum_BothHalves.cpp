#include <bits/stdc++.h>
using namespace std;

int val;


void balance(string s,int n,int sum,int half)
{
    if(val==0)
     {
        if(s.length()==n) 
          half=sum; 
     }
    else
     {
        if(s.length()==n-1)
         half=sum;
     }
    if(n==0)
     {
        int t=s.length(); 
        if(val==0)
         {
             if((half*2)==sum)
              cout<<s<<" ";
         }
        else
         {
             if(s[(t-1)/2]=='1')
              sum=sum-1;
             if((half*2)==sum)
              cout<<s<<" ";
         }
        return; 
     }
     
    balance(s+'1',n-1,sum+1,half);
    balance(s+'0',n-1,sum,half);
    
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	if(n%2==0)
	  val=0;
	else
	 val=1;
	string s;
	s+='1';
	balance(s,n-1,1,0);
	return 0;
}
