#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	 {
	   int n,k,i,sum;
	   cin>>n>>k;
	   int a[n];
	   for(i=0;i<n;i++)
	    cin>>a[i];
	   int cnt[2*k+1]={0}; 
	   for(i=0;i<n/2;i++)   //cnt[] to keep count of sets that don't need any change in its pair to get to x
	    {
	     ++cnt[a[i]+a[n-i-1]];
	    }
	   int pref[2*k+1]={0};
	   for(i=0;i<n/2;i++)  //pref[] it needs either one of the member of the pair to change
	   {
	       int l1=a[i]+1;   //l1 & l2 contain min possible value
	       int r1=a[i]+k;  //r1 & r2 contain max possible value
	       int l2=a[n-i-1]+1;
	       int r2=a[n-i-1]+k;
	       assert(max(l1,l2)<=min(r1,r2));
	       ++pref[min(l1,l2)];
	       --pref[max(r1,r2)+1];
	   }
	   for(i=1;i<=2*k+1;i++)
	    {
	        pref[i]+=pref[i-1];
	    }
	   int ans=1000000000; 
	   for(sum=2;sum<=2*k;sum++)
	    {
	        int third=(n/2-pref[sum])*2; // the third section is for those that need both member to change hence *2
	        ans=min(ans,(pref[sum]-cnt[sum])+third);  
	    }
	   cout<<ans<<endl; 
	 }
}