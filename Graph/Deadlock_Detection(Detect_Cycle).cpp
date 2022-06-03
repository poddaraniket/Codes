#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> adj[numCourses];
    for(int i=0;i<prerequisites.size();i++)
     {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
     }
    queue<int> q;
    int indegree[numCourses]={0};
    for(int i=0;i<numCourses;i++)
     {
        for(int j=0;j<adj[i].size();j++)
         {
            indegree[adj[i][j]]++;
         }
     }
    for(int i=0;i<numCourses;i++)
     {
        if(indegree[i]==0)
          q.push(i);
     }
    int p=0;
    while(!q.empty())
     {
        int u=q.front();
        p++;
        q.pop();
        for(int i=0;i<adj[u].size();i++)
         {
            int v=adj[u][i];
            indegree[v]--;
            if(indegree[v]==0)
              q.push(v);
         }
     }
    if(p==numCourses)
      return true;
    return false;
}


int main() {
    // your code goes here
    int numCourses=2;
    vector<vector<int>> prerequisites{{1,0},{0,1}};
    cout<<canFinish(numCourses,prerequisites)<<endl;
    return 0;
}
