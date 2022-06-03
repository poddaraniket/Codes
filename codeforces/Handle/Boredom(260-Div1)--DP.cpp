#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n,i,maxi=0;
	cin>>n;
	long long int a[n];
	long long int cnt[100001]={0};
	long long int f[100001];
// 	map<int,int> mp;
	for(i=0;i<n;i++)
	 {
	     cin>>a[i];
	     maxi=max(maxi,a[i]);
	     cnt[a[i]]++;
	 }
// 	for(i=1;i<=maxi;i++)
// 	 {
// 	     cout<<cnt[i]<<" ";
// 	 }
// 	cout<<endl; 
    f[0]=0;
    f[1]=cnt[1];
    for(i=2;i<=maxi;i++)
     {
         f[i]=max(f[i-1],f[i-2]+cnt[i]*i);
     }
    cout<<f[maxi]<<endl; 
}
