 #include <bits/stdc++.h>
using namespace std;



int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     long long int n,s,t=0,i,flag=0,c=0;
	     cin>>n>>s;
	     long long int a[n];
	     //long long int b[s+1]={-1};
	     for(i=0;i<n;i++)
	      {
	       cin>>a[i];
	      }
	     //int b[t]={0} 
	     for(i=0;i<n;i++)
	      {
	         t+=a[i]; 
	         while(t>s)
	          {
	              t-=a[c];
	              c++;
	          }
	         if(t==s)
	          {
	              flag=1;
	              cout<<c+1<<" "<<i+1<<endl;
	              break;
	          }
	      } 
	     if(flag==0)
	      cout<<"-1"<<endl;
	 }
	return 0;
}
