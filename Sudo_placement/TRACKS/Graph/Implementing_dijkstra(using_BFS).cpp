#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

//#define pair<int,pair<int,int>> pii
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    // Your code here
    queue<int> q;
    q.push(src);
    vector<int> d(V,INT_MAX);
   // memset(d,INT_MAX,sizeof(d));
    d[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0;v<V;v++)
         {
            if(d[v]>d[u]+g[u][v]  && g[u][v]!=0)
             {
              d[v]=d[u]+g[u][v];
              q.push(v);
             }
         }
    }
   return d;    
}