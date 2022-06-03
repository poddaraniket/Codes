#include <bits/stdc++.h>
using namespace std;
#define maxN 100000
 
// adjacency List to store the graph
vector<int> graph[maxN];
 
// Array to store the in-degree of node
int indegree[maxN];
 
// Array to store the time in which
// the job i can be done
int job[maxN];
 
// Function to add directed edge
// between two vertices
void addEdge(int u, int v)
{
    // Insert edge from u to v
    graph[u].push_back(v);
 
    // Increasing the indegree
    // of vertex v
    indegree[v]++;
}

void printOrder(int n, int m)
{
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)
         {
             q.push(i);
             job[i]=1;
         }
    }
    while(!q.empty()){
        int src=q.front();
        q.pop();
        for(int i=0;i<graph[src].size();i++){
            indegree[graph[src][i]]--;
            if(indegree[graph[src][i]]==0)
              q.push(graph[src][i]);
            job[graph[src][i]]=job[src]+1;  
        }
    }
    for(int i=1;i<=n;i++)
     cout<<job[i]<<" ";
    cout<<endl; 
}  

int main()
{
    // Given Nodes N and edges M
    int n, m;
    n = 10;
    m = 13;
 
    // Given Directed Edges of graph
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);
 
    // Function Call
    printOrder(n, m);
    return 0;
}
