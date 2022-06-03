#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b) 
{ 
    return ((a.second.first*a.second.second) > (b.second.first*b.second.second)); 
} 

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	   int n,i,j;
	   cin>>n;
	   int a[3*n];
	   vector<pair<int,pair<int,int>>> v,v1(3*n);
	   for(i=0;i<3*n;i++)
	    cin>>a[i];
	   for(i=0;i<3*n;i+=3)
	    v.push_back(make_pair(a[i],make_pair(a[i+1],a[i+2])));
	   int temp=0; 
	   for(i=0;i<n;i++)
	    {
	       v1[temp].first=v[i].first;
	       v1[temp].second.first=max(v[i].second.first,v[i].second.second);
	       v1[temp].second.second=min(v[i].second.first,v[i].second.second);;
	       temp++;
	       
	       v1[temp].first=v[i].second.first;
	       v1[temp].second.first=max(v[i].first,v[i].second.second);
	       v1[temp].second.second=min(v[i].first,v[i].second.second);
	       temp++;
	       
	       v1[temp].first=v[i].second.second;
	       v1[temp].second.first=max(v[i].first,v[i].second.first);
	       v1[temp].second.second=min(v[i].first,v[i].second.first);
	       temp++;
	    }
	   sort(v1.begin(),v1.end(), sortbysec);
	   //for(i=0;i<3*n;i++)
	   // cout<<v1[i].first<<" "<<v1[i].second.first<<" "<<v1[i].second.second<<endl;
	   int ma[3*n],lis[3*n];
	   for(i=0;i<3*n;i++)
	    {
	       ma[i]=v1[i].first;
	       lis[i]=ma[i];
	    }
	   //for(i=0;i<3*n;i++)
	   // cout<<ma[i]<<endl; 
	   //lis[0]=-1;
	   for(i=1;i<3*n;i++)
	    {
	       //lis[i]=-1; 
	       for(j=0;j<i;j++)
	        {
	            if(v1[j].second.first>v1[i].second.first && v1[j].second.second>v1[i].second.second && lis[i]<(ma[i]+lis[j]))
	             lis[i]=lis[j]+ma[i];
	        }
	    }
	   int maxi=0; 
	   for(i=0;i<3*n;i++)
	    maxi=max(lis[i],maxi);
	   cout<<maxi<<endl; 
	 }
	return 0;
}
