#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void bfs(int src,vector<int> adj[],vector<bool> vis)
{
    vis[src]=true;
    queue<int> q;
    q.push(src);
    while(q.size()!=0){
        int u=q.front();
        v.push_back(u);
        q.pop();
        for(int i=0;i<adj[u].size();i++)
         {
            int v=adj[u][i];
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
         }
    }
}

void kil(int pid[],int parentpid[],int KillingProcess,int n){
    vector<int> adj[n+1];
    for(int i=0;i<n;i++) {
        adj[parentpid[i]].push_back(pid[i]);
    }
    vector<bool> vis(n,false);
    bfs(KillingProcess,adj,vis);
    for(int i=1;i<v.size();i++)
     cout<<v[i]<<" ";
    cout<<endl; 
}

int main(){
    int pid[]={1,2,3,4,5,6,7,8,9} ;
    int parentpid[]={2,0,2,3,3,3,3,4,5}; 
    int KillingProcess= 3;
    int n=sizeof(pid)/sizeof(pid[0]);
    kil(pid,parentpid,KillingProcess,n);
}