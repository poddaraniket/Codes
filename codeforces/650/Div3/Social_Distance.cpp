#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k,count=0,sum=0,flag=0;
	    cin>>n>>k;
	    string s;
	    cin>>s;
	   // vector<pair<int,int>> v;
	    //inint t one[n];
	    for(int i=0;i<s.length();i++)
	     {
	         if(s[i]=='0')
	          count++;
	         else
	          {
	              flag=1;
	              count-=k;
	              if(count>0)
	               sum+=((count+k)/(k+1));
	              count=-k;
	          }
	     }
	    sum+=((count+k)/(k+1)); 
	    cout<<sum<<endl; 
	}
	return 0;
}