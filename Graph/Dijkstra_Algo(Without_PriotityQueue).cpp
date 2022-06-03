#include <bits/stdc++.h>
using namespace std;

//#define INT_MAX 100000000

#define V 9

void printSPF(int dist[],int parent[])
{
    cout<<"V D P"<<endl;
    for(int i=0;i<V;i++)
     {
        cout<<i<<" "<<dist[i]<<" "<<parent[i]<<endl; 
     }
}

int minDist(int dist[],bool vis[])
{
    int min=INT_MAX,node;
    for(int i=0;i<V;i++)
     {
        if(dist[i]<min && vis[i]==false)
         {
            min=dist[i];
            node=i;
         }
     }
    return node;  
}

void dijkstra(int graph[V][V],int src)
{
    int dist[V]={0};
    int parent[V]={-1};
    for(int i=0;i<V;i++)
     {
        if(i!=src)
         dist[i]=INT_MAX;
     }
    bool vis[V]={false};
    for(int i=0;i<V-1;i++)
     {
       int u=minDist(dist,vis);
       vis[u]=true;
       for(int v=0;v<V;v++)
        {
            if(dist[u]!=INT_MAX && vis[v]!=true && graph[u][v]!=0 && dist[v]>dist[u]+graph[u][v])
             {
                dist[v]=dist[u]+graph[u][v];
                parent[v]=u;
             }
        }
     }
    printSPF(dist,parent);
}


int main() {
	// your code goes here
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    dijkstra(graph, 0); 
	return 0;
}
