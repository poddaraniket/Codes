// find min edge but that should have a connection with one of the already selected node

#include <bits/stdc++.h>
using namespace std;

map<int,int> result;
bool vis[10000]={false};
int sum=0;


//print the min cost and the edges selected for the min spanning tree
void print()
{
    cout<<sum<<endl;
    for(int i=0;i<result.size();i++)
     {
        cout<<result[i]<<" -- "<<i<<endl; 
     }
}

// create the graph 
void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt)
{
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}

int parent(int i) { return (i - 1) / 2; }

int left(int i) { return (2 * i + 1); }

int right(int i) { return (2 * i + 2); }



void decreaseKey(vector<pair<int,int>> &vec,int &V,int i)
{
    while(i!=0 && vec[parent(i)].first> vec[i].first)
    {
     swap(vec[i],vec[parent(i)]);
     i=parent(i);
    }
}

// after extracing the min weighted edge we have to rearrange the tree 

void MeanHeapify(vector<pair<int,int>> &vec,int &V,int i)
{
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if(l<V && vec[l].first<vec[i].first)
     smallest=l;
    if(r<V && vec[r].first<vec[smallest].first)
     smallest=r;
    if(smallest!=i)
    {
     swap(vec[i],vec[smallest]);
     MeanHeapify(vec,V,smallest);
    }
}

int minExtract(vector<pair<int,int>> &vec,int &V,int pop[])
{
    if(V<=0)
     return -1;
    if(V==1)
     {
        V--; 
        //result.push_back({vec[V].second,pop[V]});
        vis[vec[V].second]=true;
        sum+=vec[V].first;
        return vec[V].second;
     }
    int root=vec[0].second;
    vis[vec[0].second]=true;
    sum+=vec[0].first;
    swap(vec[0],vec[V-1]);
    V--;
    MeanHeapify(vec,V,0);
    return root;
}

// find the v node and check its weight and if the eight is less update it and send the index value so that it can be rearranged  

int isWeight(vector<pair<int,int>> &vec,int v,int weight)
{
    for(int i=0;i<vec.size();i++)
     {
        if(vec[i].second==v)
         {
            if(weight<vec[i].first)
            {
             //cout<<vec[i].second<<endl;    
             vec[i].first=weight;
             return i;
            }
         }
     }
    return -1; 
}

void prims(vector<pair<int,int>> adj[],int src,int V)
{
    // vec will store the node and the weight that it has currently
    vector<pair<int,int>> vec(V);
    for(int i=0;i<V;i++)
     {
        vec[i].first=INT_MAX;
        vec[i].second=i;
     }
    vec[src].first=0;
    while(1)
     {
        // extract node that has got the least weight 
        int u=minExtract(vec,V,pop);

        // since its an infinite loop as soon as the vec is empty it will break 
        if(u==-1)
         break;
        // update the weight of all the nodes that is connected to this node
        for(int i=0;i<adj[u].size();i++)
         {
            
            int v=adj[u][i].first;
            int weight=adj[u][i].second;
            if(vis[v]==false)
             { 
                //vec[v].first=weight;   // this was wrong vec[v] shouldn't be bcoz v is the vec[i].first
                int j=isWeight(vec,v,weight);
                if(j!=-1)
                {
                 decreaseKey(vec,V,j);
                 result[v]=u;
                }
             }
         }
     }
}

int main() {
    // your code goes here
    int V=9;
    vector<pair<int,int>> adj[V];
    addEdge(adj, 0, 1, 4); 
    addEdge(adj, 0, 7, 8); 
    addEdge(adj, 1, 2, 8); 
    addEdge(adj, 1, 7, 11); 
    addEdge(adj, 2, 3, 7); 
    addEdge(adj, 2, 8, 2); 
    addEdge(adj, 2, 5, 4); 
    addEdge(adj, 3, 4, 9); 
    addEdge(adj, 3, 5, 14); 
    addEdge(adj, 4, 5, 10); 
    addEdge(adj, 5, 6, 2); 
    addEdge(adj, 6, 7, 1); 
    addEdge(adj, 6, 8, 6); 
    addEdge(adj, 7, 8, 7);
    prims(adj,0,V);
    print();
    return 0;
}
