#include<bits/stdc++.h>
using namespace std;
 
//map<int,int> parent; 
int dist[10000];
int cnt[10000];

 
void postorder(vector<int> adj[],int node,int parent)
{
    // if(adj[child].size()==1)
    //  return;
    for(int i=0;i<adj[node].size();i++)
     {
        int child=adj[node][i]; 
        if(parent==child)
         continue;
        postorder(adj,child,node);
        cnt[node]+=cnt[child];
        //cout<<parent<<" "<<cnt[parent]<<endl;
        dist[node]+=dist[child]+cnt[child];
     }
}
 
void preorder(vector<int> adj[],int node,int parent,int N)
{
    for(int i=0;i<adj[node].size();i++)
     {
        int child=adj[node][i]; 
        if(parent==child)
         continue;
        dist[child]=dist[node]-cnt[child]+(N-cnt[child]); 
        preorder(adj,child,node,N);
     }
}
 
int main()
{
    int N,u,v;
    cin>>N;
    vector<int>adj[N];
	for(int i=0;i<N-1;i++)
	 {
		 cin>>u>>v;
		 u--;
		 v--;
		 adj[u].push_back(v);
         adj[v].push_back(u);
	 } 
// 	cout<<"="<<endl; 
    for(int i=0;i<N;i++)
     {
        cnt[i]=1;
        dist[i]=0;
     }
    //cout<<cnt[1]<<endl;
    //int dist[N];
    postorder(adj,0,-1);
    preorder(adj,0,-1,N);
    // for(int i=0;i<N;i++)
    //  cout<<cnt[i]<<" ";
    // cout<<endl; 
    for(int i=0;i<N;i++)
     cout<<dist[i]<<" ";
    cout<<endl; 
}