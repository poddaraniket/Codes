#include <bits/stdc++.h>
using namespace std;



int main() {
	// your code goes here
	int n;
	cin>>n;
	while(true)
	 {
	     vector<pair<int,int>> pos,neg;
	     int arr[n];
	     for(int i=0;i<n;i++)
	      {
	          cin>>arr[i];
	          if(arr[i]>0)
	           pos.push_back({arr[i],i});
	          else
	           neg.push_back({arr[i],i});
	      }
	     long long int sum=0;
	     int p=0,ne=0;
	     while(p<pos.size() && ne<neg.size())
	      {
	          if(pos[p].first>abs(neg[ne].first))
	           {
	              sum+=abs(neg[ne].first)*abs(pos[p].second-neg[ne].second);    
	              pos[p].first=pos[p].first+neg[ne].first;
	              ne++;
	           }
	          else if(pos[p].first<abs(neg[ne].first))
	           {
	               sum+=pos[p].first*abs(pos[p].second-neg[ne].second);   
	               neg[ne].first=pos[p].first+neg[ne].first;
	               p++;
	           }
	          else
	           {
	               sum+=pos[p].first*abs(pos[p].second-neg[ne].second);
	               p++;
	               ne++;
	           }
	      }
	     cout<<sum<<endl; 
	     cin>>n;
	     if(n==0)
	      break;
	 }
	return 0;
}
