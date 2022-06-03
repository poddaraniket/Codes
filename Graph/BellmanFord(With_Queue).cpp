// it is same as Bellman Ford eq.


#include <bits/stdc++.h>
using namespace std;

#define INT_MAX 100000000 

int flag=0;

void BellmanFord(vector<pair<int,int>> adj[],int N,int src,int dist[],int parent[])
{
    // Adding queue makes the Algo a bit faster as we avoid those vertices whose path distance are not improving anymore 
    // by adding count var we caan also brek from the loop if it is fouond to have a negative weight cycle
    // Avg time Complexity --> O(E)
    // worst --> O(VE) same as Bellman Ford. 

    bool inQueue[N]={false};
    int count[N]={0};
    queue<int> q;
    q.push(src);
    count[src]=1;
    inQueue[src]=true;
    while(!q.empty())
    {
       int u=q.front();
       //cout<<u<<" ";
       q.pop();
       inQueue[u]=false;
       for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            int weight=adj[u][i].second;
            if(dist[v]>dist[u]+weight)
             {
                dist[v]=dist[u]+weight;
                parent[v]=u;
                if(!inQueue[v])
                 {
                    q.push(v);
                    count[v]++;
                    if(count[v]==N)
                     {
                        flag=1;
                        return;
                     }
                    inQueue[v]=true;
                 }
             }
        }
    }
}

int main() {
	// your code goes here
// 	int N = 4; 
  
//     // Creating adjacency list 
//     // for representing graph 
//     vector<pair<int,int>> adj[N]; 
//     adj[0].push_back(make_pair(1,1));
//     adj[1].push_back(make_pair(2,3));
//     adj[2].push_back(make_pair(3,2));
//     adj[3].push_back(make_pair(1,-6));
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
    
    BellmanFord(adj,N,0,dist,parent);
    
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
