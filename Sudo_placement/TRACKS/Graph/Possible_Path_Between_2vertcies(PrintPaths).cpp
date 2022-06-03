#include <bits/stdc++.h>
using namespace std;

bool vis[1000];

vector<vector<int>> res;

void path(vector<int> adj[],int src,int dest,vector<int> vec)
{
    if(src==dest)  
     {
        res.push_back(vec);
        return;
     }
    vis[src]=true;
    for(int i=0;i<adj[src].size();i++)
     {
        if(vis[adj[src][i]]==false)
         {
            vec.push_back(adj[src][i]); 
            path(adj,adj[src][i],dest,vec);
            vec.pop_back();
         }
     }
    vis[src]=false; 
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int N,M;
	    cin>>N>>M;
	    vector<int> adj[N];
	    memset(vis,false,sizeof(vis));
	    for(int i=0;i<M;i++)
	     {
	       int u,v;
	       cin>>u>>v;
	       adj[u].push_back(v);
	     }
	    int count=0; 
	    int src,dest;
	    cin>>src>>dest;
	    vector<int> vec;
	    vec.push_back(src);
	    path(adj,src,dest,vec);
	    for(int i=0;i<res.size();i++)
	     {
	         for(int j=0;j<res[i].size();j++)
	          { 
	             cout<<res[i][j];  
	            if(j!=res[i].size()-1)  
	             cout<<"->";
	          }
	         cout<<endl; 
	     }
	    //cout<<count<<endl;
	}
	return 0;
}
