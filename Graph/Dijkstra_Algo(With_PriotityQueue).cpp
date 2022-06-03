//O(V+ElogV)

#include <bits/stdc++.h>
using namespace std;

//#define INT_MAX 100000000
int V;

void addEdge(vector<pair<int,int>>adj[],int u,int v,int wt)
{
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}

void printSPF(int dist[],int parent[])
{
    cout<<"V D P"<<endl;
    for(int i=0;i<V;i++)
     {
        cout<<i<<" "<<dist[i]<<" "<<parent[i]<<endl; 
     }
}

// int minDist(int dist[],bool vis[])
// {
//     int min=INT_MAX,node;
//     for(int i=0;i<V;i++)
//      {
//         if(dist[i]<min && vis[i]==false)
//          {
//             min=dist[i];
//             node=i;
//          }
//      }
//     return node;  
// }

void dijkstra(vector<pair<int,int>> adj[],int src,int V)
{
    int dist[V]={0};
    int parent[V]={-1};
    for(int i=0;i<V;i++)
     {
        if(i!=src)
         dist[i]=INT_MAX;
     }
    bool vis[V]={false};
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,src));
    vis[src]=true;
    while(!pq.empty())
    {
       int u=pq.top().second;
       pq.pop();
       for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            int weight=adj[u][i].second;
            if(dist[v]>dist[u]+weight && vis[v]==false)
            {
             dist[v]=dist[u]+weight;
             parent[v]=u;
             pq.push(make_pair(dist[v],v));
            }
        }
    }
    printSPF(dist,parent);
}


int main() {
	// your code goes here
    V = 9; 
    vector<pair<int,int>> adj[V];
    //  making above shown graph 
    addEdge(adj,0, 1, 4); 
    addEdge(adj,0, 7, 8); 
    addEdge(adj,1, 2, 8); 
    addEdge(adj,1, 7, 11); 
    addEdge(adj,2, 3, 7); 
    addEdge(adj,2, 8, 2); 
    addEdge(adj,2, 5, 4); 
    addEdge(adj,3, 4, 9); 
    addEdge(adj,3, 5, 14); 
    addEdge(adj,4, 5, 10); 
    addEdge(adj,5, 6, 2); 
    addEdge(adj,6, 7, 1); 
    addEdge(adj,6, 8, 6); 
    addEdge(adj,7, 8, 7); 
    dijkstra(adj,0,V);
	return 0;
}
