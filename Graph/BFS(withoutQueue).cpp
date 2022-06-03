#include <bits/stdc++.h>
using namespace std;


// it creates the stack in the first travserse
void BFS(int curr,int N,vector<int> adj[],vector<int> &v,vector<int> &dp,bool vis[])
{
    //cout<<"*"<<endl;
    while(curr<N)
     {
        //cout<<"*"<<endl; 
        int node=v[curr];
        cout<<node<<" ";
        vis[node]=true;
        for(int i=0;i<adj[node].size();i++)
         {
            int next=adj[node][i]; 
            if(vis[next]==false && dp[next]<dp[node]+1)
            {
             v.push_back(next);
             dp[next]=dp[node]+1;
            }
         }
        curr++; 
     }
}

int main() {
	// your code goes here
	int N = 4; 
  
    // Creating adjacency list 
    // for representing graph 
    vector<int> adj[N]; 
    adj[0].push_back(1); 
    adj[0].push_back(2); 
    adj[1].push_back(2); 
    adj[2].push_back(0); 
    adj[2].push_back(3); 
    adj[3].push_back(3); 
	
	vector<int> dp(N,0),v;
	int src;
	cin>>src;
	v.push_back(src);
    //cout<<v[0]<<endl;
    
    bool vis[N];
    memset(vis,false,sizeof(vis));
    
    //cout<<"*"<<endl;
    BFS(0,N,adj,v,dp,vis);
    
	return 0;
}
