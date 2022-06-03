#include <bits/stdc++.h>
using namespace std;
#define maxN 100000
 
// adjacency List to store the graph
vector<int> graph[maxN];
 
// Array to store the in-degree of node
int indegree[maxN];
 
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

bool isCyclic(int n)
{
    int count=0;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)
         {
             q.push(i);
             count++;
         }
    }
    while(!q.empty()){
        int src=q.front();
        q.pop();
        for(int i=0;i<graph[src].size();i++){
            indegree[graph[src][i]]--;
            if(indegree[graph[src][i]]==0){
              q.push(graph[src][i]);
              count++;
            }
        }
    }
    return (count==n);
}  

bool canFinish(int n,vector<pair<int, int> > prerequisites){
    for(int i=0;i<n;i++){
        addEdge(prerequisites[i].first,prerequisites[i].second);
    }
    
    return isCyclic(n);
}

int main()
{
    int numTasks = 2;
 
    vector<pair<int, int> > prerequisites;
 
    // for prerequisites: [[1, 0], [2, 1], [3, 2]]
 
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(0,1));
    //prerequisites.push_back(make_pair(3, 2));
    if (canFinish(numTasks, prerequisites)) {
        cout << "Possible to finish all tasks";
    }
    else {
        cout << "Impossible to finish all tasks";
    }
 
    return 0;
}
