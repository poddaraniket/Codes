#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    double h,m;
	    cin>>h>>m;
	    if(m==60)
	     {
	       if(h>=1 && h<=6)
	        cout<<(h*30);
	       else 
	        cout<<360-(h*30)<<endl;
	     }
	    else
	      {
	         double hr=(h*30)+(0.5*m);
	         //cout<<hr<<endl;
	         //cout<<m*
	         double diff=abs(hr-(m*6));
	         //cout<<diff<<endl;
	         if(diff<=180)
	          cout<<floor(diff)<<endl;
	         else
	          cout<<floor(360-diff)<<endl;
	      }
	}
	return 0;
}