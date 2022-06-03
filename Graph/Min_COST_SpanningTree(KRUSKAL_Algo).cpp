// select min weight edges ignore if by taking that edge we get a

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt,vector<pair<int,pair<int,int>>> &edges)
{
    adj[u].push_back({v,wt});
    edges.push_back({wt,{u,v}});
   // adj[v].push_back(u);
}

bool comp(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b)
{
    return a.first<b.first;
}

void print(vector<pair<int,int>> result,int sum)
{
    cout<<sum<<endl;
    for(int i=0;i<result.size();i++)
     cout<<result[i].first<<" "<<result[i].second<<endl;
}

int find(int parent[],int val)
{
    if(parent[val]!=val)
     parent[val]=find(parent,parent[val]);
    return parent[val]; 
}

void Union(int parent[],int rank[],int u,int v)
{
    int xroot=find(parent,u);
    int yroot=find(parent,v);
    
    if(rank[xroot]>rank[yroot])
     {
        parent[yroot]=xroot; 
     }
    else if(rank[yroot]>rank[xroot])
     {
        parent[xroot]=yroot; 
     }
    else
     {
        parent[xroot]=yroot;
        rank[yroot]++;
     }
}

// find the correct edges
// to detect cycle we have used Disjoint Set(By Rank and Path Compression) Method

void kruskal(vector<pair<int,pair<int,int>>> edges,int V,int &sum)
{
    vector<pair<int,int>> result;
    int parent[V];
    for(int i=0;i<V;i++)
     parent[i]=i;
    int rank[V]={0};
    for(int i=0;i<edges.size();i++)
      {
            //cout<<"*"<<endl;
        int u=edges[i].second.first;    
        int v=edges[i].second.second;
        int wt=edges[i].first;
        //cout<<u<<" "<<v<<endl;
        int x=find(parent,u);
        int y=find(parent,v);
        // if the edge makes the graph cyclic avoid that edge
        if(x!=y)
         {
            //cout<<u<<" "<<v<<endl; 
            result.push_back({u,v}); 
            sum+=wt;
            Union(parent,rank,u,v); 
          }
            //cout<<parent[v]<<endl;
      }
    print(result,sum);
}

int main()
{
    // your code goes here
    vector<pair<int,pair<int,int>>> edges;
    int V=9;
    vector<pair<int,int>> adj[V];
    addEdge(adj, 0, 1, 4,edges); 
    addEdge(adj, 0, 7, 8,edges); 
    addEdge(adj, 1, 2, 8,edges); 
    addEdge(adj, 1, 7, 11,edges); 
    addEdge(adj, 2, 3, 7,edges); 
    addEdge(adj, 2, 8, 2,edges); 
    addEdge(adj, 2, 5, 4,edges); 
    addEdge(adj, 3, 4, 9,edges); 
    addEdge(adj, 3, 5, 14,edges); 
    addEdge(adj, 4, 5, 10,edges); 
    addEdge(adj, 5, 6, 2,edges); 
    addEdge(adj, 6, 7, 1,edges); 
    addEdge(adj, 6, 8, 6,edges); 
    addEdge(adj, 7, 8, 7,edges);
    // store all the edges in sorted weight order
    sort(edges.begin(),edges.end(),comp);
    //cout<<"/"<<edges.size()<<endl;
    int sum=0;
    kruskal(edges,V,sum);
}