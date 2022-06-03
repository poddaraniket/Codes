
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

class Graph 
{ 
	int V; 
	list<int> *adj; 
    void countPathsUtil(int, int, bool*, int &); 

public: 
    Graph(int V); 
	void addEdge(int u, int v); 
	int countPaths(int s, int d); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V+1]; 
} 

void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
} 


 // } Driver Code Ends


//User function Template for C++
// Function to return number of paths between source and destination
void Graph::countPathsUtil(int src,int dest,bool *vis,int& count)
{
    if(src==dest)
     {
        vis[dest]=false; 
        count++; 
        return;
     }
    else
    {
     vis[src]=true;          // keep track of visited nodes but in a manner that when its all adjacents are called it unvisited 
    for(auto it=adj[src].begin();it!=adj[src].end();it++)           //so that it can nw work as a path for some other path
     {
         if(vis[*it])
          continue;
         countPathsUtil(*it,dest,vis,count); 
     }
    vis[src]=false; 
    }
}

int Graph::countPaths(int s, int d) 
{ 
	// Your code here
	bool vis[100];
    memset(vis,false,sizeof(vis));
    int count=0;
    countPathsUtil(s,d,vis,count);
    return count;
} 



// { Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int N, M;
	    cin>>N>>M;
	    int u, v;
	    Graph g(N);
	    while(M--){
	        cin>>u>>v;
	        g.addEdge(u, v);
	    }
	    int s, e;
	    cin>>s>>e;
	    cout << g.countPaths(s, e)<<endl; 
	}
	return 0; 
} 

  // } Driver Code Ends