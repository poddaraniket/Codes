#include <bits/stdc++.h>
using namespace std;

#define INT_MAX 100000000 

int flag=0;

void BellmanFord(vector<pair<int,int>> adj[],int N,int dist[],int parent[])
{
    int curr=0;
    while(curr<N-1)
     {
        for(int u=0;u<N;u++)
         {
            //cout<<curr<<"-->"<<u<<endl; 
            for(int i=0;i<adj[u].size();i++)
             {
                int v=adj[u][i].first;
                int wt_uv=adj[u][i].second;
                if(dist[u]!=INT_MAX)
                 {
                    if(dist[v]>dist[u]+wt_uv)
                     {
                        dist[v]=dist[u]+wt_uv;
                        parent[v]=u;
                     }
                 }
             }
         }
        curr++; 
     }
    //to check if there is a negative weighted cycle in the graph 
    // negative weight cycle means the sum of the weights of the edges in the graph is negative
    // if there is a negative weight cycle the shortest path will never come as the sum will keep decreasing
    for(int u=0;u<N;u++)
      {
        for(int i=0;i<adj[u].size();i++)
         {
            int v=adj[u][i].first;
            int wt_uv=adj[u][i].second;
            if(dist[u]!=INT_MAX)
            {
              if(dist[v]>dist[u]+wt_uv)
                {
                  flag=1;
                  return;
                }
            }
         }
      } 
}

int main() {
	// your code goes here
	int N = 5; 
  
    // Creating adjacency list 
    // for representing graph 
    vector<pair<int,int>> adj[N]; 
    adj[0].push_back(make_pair(1,-1));
    adj[0].push_back(make_pair(2,4));
    adj[1].push_back(make_pair(2,3));
    adj[1].push_back(make_pair(3,2));
    adj[3].push_back(make_pair(1,1));
    adj[1].push_back(make_pair(4,2));
    adj[4].push_back(make_pair(3,-3));
    adj[3].push_back(make_pair(2,5));
    
    int dist[N];
    for(int i=0;i<N;i++)
      dist[i]=INT_MAX;
    dist[0]=0;
    int parent[N]={-1};
    
    BellmanFord(adj,N,dist,parent);
    
    if(flag==1)
     {
        cout<<"We have a nrgative weight cycle"<<endl; 
     }
    else
     {
        cout<<"Vertex   Dist     Parent"<<endl; 
        for(int i=0;i<N;i++)
         {
            cout<<"  "<<i<<"       "<<dist[i]<<"       "<<parent[i]<<endl; 
         }
     }
	return 0;
}
