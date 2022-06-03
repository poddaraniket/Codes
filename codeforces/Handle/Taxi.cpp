#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,count=0,i,rem;
	cin>>n;
	int a[n];
	int b[5]={0};
	b[0]=-1;
	for(i=0;i<n;i++)
	 {
	     cin>>a[i];
	     b[a[i]]++;
	 }
	count+=(b[4]+b[3]); 
	//cout<<"+"<<count<<endl;
	if(b[1]>=b[3])
	  {
	      b[1]-=b[3];
	   //   count+=a[3];
	  }
	else if(b[3]>b[1])
	  {
	   //   count+=a[3]; 
	      b[1]=0;
	  }
	count+=b[2]/2;
	//cout<<"*"<<count<<endl;
	rem=b[2]%2;
	if(rem>0)
	 {
	     if(b[1]<=2)
	      {
	        count++;
	        b[1]=0;
	      }
	     else
	       {
	           count++;
	           b[1]-=2;
	       }
	 }
	//cout<<"**"<<count<<endl; 
	if((b[1]%4)>0)
	   count+=(b[1]/4)+1;
	else
	   count+=(b[1]/4);
	cout<<count<<endl;   
	return 0;
}
