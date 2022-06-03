#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt)
{
   adj[u].push_back(make_pair(v,wt)); 
}

void printPath(int dist[],int parent[],int src,int dest)
{
    int i=dest,maxi=0,sum=dist[dest];
    while(i!=-1)
     {
        if(dist[i]==INT_MAX)
        {
         return;
        }
        cout<<i<<" ";
        maxi=max(maxi,dist[i]-dist[parent[i]]);
        i=parent[i];
     }
    cout<<endl; 
    cout<<(sum-maxi)+(maxi/2)<<endl; 
}

void Dijkstra(vector<pair<int,int>>adj[],int src,int n)
{
    int dist[n]={0};
    for(int i=0;i<n;i++)
     dist[i]=INT_MAX;
    int parent[n]={-1};
    dist[0]=0;
    bool vis[n]={false};
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,src));
    vis[src]=true;
    //cout<<"*"<<endl;
    while(!pq.empty())
     {
        int u=pq.top().second;
        //cout<<u<<endl;
        pq.pop();
        for(int i=0;i<adj[u].size();i++)
         {
            int v=adj[u][i].first;
            int weight=adj[u][i].second;
            if(dist[v]>dist[u]+weight && vis[v]==false)
             {
                dist[v]=dist[u]+weight;
                parent[v]=u;
                //cout<<v<<endl;
                pq.push(make_pair(dist[v],v));
             }
         }
     }
    //cout<<"*"<<endl; 
    printPath(dist,parent,src,2); 
}

int main() {
	// your code goes here
	vector<pair<int,int>> adj[3];
	addEdge(adj,1,2,1);
	addEdge(adj,0,2,7);
	addEdge(adj,1,0,5);
	addEdge(adj,0,1,3);
	Dijkstra(adj,0,3);
	return 0;
}
