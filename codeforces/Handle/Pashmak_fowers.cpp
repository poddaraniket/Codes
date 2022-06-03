#include<bits/stdc++.h>
using namespace std;
 
int main() {
   long long int n,i,mini=1000000000,maxi=-1,num;
   cin>>n;
   map<long long int,long long int> mp;
   for(i=0;i<n;i++)
    {
      cin>>num;
      mp[num]++;
      mini=min(num,mini);
      maxi=max(num,maxi);
    }
  if(maxi!=mini)  
    cout<<maxi-mini<<" "<<mp[maxi]*mp[mini]<<endl;
  else
   {
     long long int temp=mp[mini],s=0;
     for(i=temp-1;i>=1;i--)
       s+=i;
     cout<<"0"<<" "<<s<<endl;  
   }  
}
