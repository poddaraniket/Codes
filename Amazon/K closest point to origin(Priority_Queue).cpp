#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int m,k,num,num1;
	    cin>>m>>k;
	    double a[m][2];
	    for(int i=0;i<m;i++)
	     {
	      cin>>a[i][0]>>a[i][1];
	     }
	   // for(int i=0;i<m;i++)
	   //  {
	   //   cout<<a[i][0]<<" "<<a[i][1]<<endl;
	   //  } 
	    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>val;
	    for(int i=0;i<m;i++)
	     {
	        int temp=(a[i][0]*a[i][0])+(a[i][1]*a[i][1]); 
	        val.push({temp,i});
	     }
	    for(int i=0;i<k;i++)
	     {
	         int front=val.top().second;
	         val.pop();
	         cout<<a[front][0]<<" "<<a[front][1]<<" ";
	     }
	    cout<<endl; 
	}
	return 0;
}
K closest point to origin