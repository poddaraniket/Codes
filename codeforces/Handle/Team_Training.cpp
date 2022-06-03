#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n,m,c=0;
	cin>>n>>m;
    while((n+m)>2 && m!=0 && n!=0)
    {
	while(n>=m)
	  {
	 	if(n>=2 && m>=1)
	 	  {
	 		n-=2;
	 	  	m--;
	 	  	c++;
	 	  }
	 	else
	 	  break;  
	  }  
	while(m>=n)
	  {
	 	if(m>=2 && n>=1)
	 	 {
	 	   m-=2;
	 	   n--;
	 	   c++;
	 	 }
	 	else
	 	  break;  
	  }
	}
	cout<<c<<endl;   
}
