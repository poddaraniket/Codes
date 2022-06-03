// select min weight edges ignore if by taking that edge we get a
// Sorting Edges -> O(ElogE) find & Union of each edge -> O(logV) -> O(ElogV)
// TC -> O(ElogE + ElogV)
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

void print(vector<pair<int,int>> result,int mst)
{
    cout<<mst<<endl;
    for(int i=0;i<result.size();i++)
     cout<<result[i].first<<" "<<result[i].second<<endl;
}


// find the correct edges
// to detect cycle we have used Disjoint Set(By Rank and Path Compression) Method

void Union(int parU,int parV,int parent[],int size[]){
    if(size[parU]<size[parV])
     {
        parent[parU]=parV; 
        size[parV]+=size[parU]; 
     }
    else
     {
        parent[parV]=parU; 
        size[parU]+=size[parV];  
     }
}

int find(int parent[],int src)
{
    if(parent[src]!=src)
     parent[src]=find(parent,parent[src]);
    return parent[src]; 
}

void kruskal(vector<pair<int,pair<int,int>>> edges,int V,int &mst)
{
    int parent[V],size[V];
    vector<pair<int,int>> result;
    for(int i=0;i<V;i++)
     {
         parent[i]=i;
         size[i]=1;
     }
    for(int i=0;i<edges.size();i++)
     {
        int wt=edges[i].first;
        int u=edges[i].second.first;
        int v=edges[i].second.second;
        int parU=find(parent,u);
        int parV=find(parent,v);
        if(parU!=parV)
         {
            mst+=wt; 
            Union(parU,parV,parent,size);
            result.push_back({u,v});
         }
     }
    print(result,mst); 
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
    int mst=0;
    kruskal(edges,V,mst);
}