#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int n,m,a,reca,sqa,count;
	cin>>n>>m>>a;
	reca=n*m;
	sqa=a*a;
	if(sqa>=reca)
	  cout<<"1"<<endl;
	else
	 {
	     count=reca/sqa;
	     if((reca%sqa)>0)
	      count+=1;
	     if((count%2)==0) 
	       cout<<count<<endl;
	     else
	       cout<<count+1<<endl;
	 }
	return 0;
}
