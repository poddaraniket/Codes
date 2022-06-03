#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
   {
    int n,i,maxi=0,q;
    cin>>n;
    int a[n];
    int b[n];
    // int count[10000001]={0};
    for(i=0;i<n;i++)
     cin>>a[i];
    for(i=0;i<n;i++)
    {
     cin>>b[i];
     maxi=max(maxi,b[i]);
    }
    int count[maxi+1]={0};
    for(i=0;i<n;i++)
     count[b[i]]++;
    for(i=1;i<=maxi;i++)
     count[i]+=count[i-1];
    cin>>q; 
    while(q--)
    {
        int num;
        cin>>num;
        if(a[num]>=maxi)
         cout<<n<<endl;
        else
         cout<<count[a[num]]<<endl;
    }
   }
	return 0;
}