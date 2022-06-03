#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int n,i,num;
  cin>>n;
  int a[n+1]={0};
  a[0]=1;
  vector<int>adj[n+1];
  vector<int> v;
  for(i=1;i<=n;i++)
   {#include<bits/stdc++.h>
using namespace std;
 
vector<int> root;
vector<int>adj[30009];
bool vis[30009];
int dist[30009];
 
int bfs(int num)
{
  int i;
    queue<int> q;
    q.push(num);
    vis[num]=1;
    dist[num]=1;
    int ans=1;
    while(!q.empty())
     {
       int t=q.front();
       q.pop();
       for(i=0;i<adj[t].size();i++)
        {
          if(vis[adj[t][i]])
           continue;
          vis[adj[t][i]]=1;
          q.push(adj[t][i]);
          dist[adj[t][i]]=dist[t]+1;
          ans=max(ans,dist[adj[t][i]]); 
        }
     }
    return ans; 
} 
 
int main() {
  int n,i,num;
  cin>>n;
  for(i=1;i<=n;i++)
   {
     cin>>num;
     if(num!=-1)
     {
        adj[num].push_back(i);
        adj[i].push_back(num);
     }
     else
       root.push_back(i); 
   }
  int ans=0; 
  for(i=0;i<root.size();i++)
   {
     ans=max(ans,bfs(root[i]));
   } 
  cout<<ans<<endl; 
}
     cin>>num;
     if(num!=-1)
      adj[num].push_back(i);
     else
       v.push_back(i); 
   }
  for(i=0;i<v.size();i++)
   {
     if(adj[i].size()>0)
      
   } 
}