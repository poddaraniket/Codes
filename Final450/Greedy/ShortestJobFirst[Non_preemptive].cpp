#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a,vector<int> b)
{
    if(a[1]<b[1])
     {
        return true; 
     }
    if(a[1]==b[1])
     {
        return a[2]<b[2]; 
     }
    return false; 
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<vector<int>>v(n);
	for(int i=0;i<n;i++)
	 {
	     for(int j=0;j<3;j++)
	      {
	          int x;
	          cin>>x;
	          v[i].push_back(x);
	      }
	 }
	// sort by arrival time 
	sort(v.begin(),v.end(),cmp);
	// queue will contain data of those ids whose current time falls within the the time CPU s empty
	// queue is arranged as per burst time
	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
	pq.push({v[0][2],v[0][0]});
	int currentTime=0;
	vector<int> ans;
	int i=1;
	while(!pq.empty())
	{
	    int burstTime=pq.top()[0];
	    int id=pq.top()[1];
	    pq.pop();
	    currentTime+=burstTime;
	    ans.push_back(id);
	    while(true)
	     {
	         if(i<n && currentTime>=v[i][1]){
	            pq.push({v[i][2],v[i][0]});
                i++;	          
	         }
	         else
	          break;
	     }
	}
	for(int i=0;i<n;i++)
	 cout<<ans[i]<<" ";
	cout<<endl; 
	return 0;
}
