#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
ll n,m;
ll ans=0;
//vector<int> root;
vector<int>adj[1000009];
//bool vis[100000]={0};
ll cat[1000009];
 
void dfs(ll curr,ll prev,ll cats)
{
	cats+=cat[curr];
	if(!cat[curr])
	cats=0;
	if(cats>m)
	return;
	ll c=0;
	for(ll i=0;i<adj[curr].size();i++)
	{
		ll j=adj[curr][i];
		if(j==prev)
		continue;
		c++;
		dfs(j,curr,cats);
	}
	if(c==0&&cats<=m)
	ans++;
}
 
int main() {
  ll x,y,i;
  cin>>n>>m;
  for(i=1;i<=n;i++)
   {
     cin>>cat[i];
   }
  for(i=1;i<=n-1;i++)
   {
     cin>>x>>y;
     adj[x].push_back(y);
     adj[y].push_back(x);
   } 
  dfs(1,-1,0);
  cout<<ans<<endl;
}