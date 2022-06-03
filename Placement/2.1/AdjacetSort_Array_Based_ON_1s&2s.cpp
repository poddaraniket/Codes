//the numbers of same type(1 or 0) must be arranged in there order if yes we can sort

/*
eg 1 4 3 2 5   NO
   1 0 1 1 1

eg 1 4 2 3 5
   1 0 1 1 0   
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
     { 
        int n,i;
        cin>>n;
        long long int a[n],b[n],f=0;
		vector<long long int> one,zero;
		one.push_back(-1);
		zero.push_back(-1);
        for(i=0;i<n;i++)
        {
         cin>>a[i];
        }
        for(i=0;i<n;i++)
		{
         cin>>b[i];
		 if(b[i]==1)
		  {  
		   one.push_back(a[i]);
		   if(one[one.size()-2]>one[one.size()-1])
		    f=1;
		  }
		 else
		 {
		   zero.push_back(a[i]); 
		   if(zero[zero.size()-2]>zero[zero.size()-1])
		    f=1;
		 }
		}
		if(f==1)
		 cout<<"NO"<<endl;
		else cout<<"YES"<<endl;  
     }
}