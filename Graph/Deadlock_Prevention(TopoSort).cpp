#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
{
    vector<int> result;
    stack<int> s;
    vector<int> adj[numCourses];
    indegree[numCourses]={0};
    for(int i=0;i<prerequisites.size();i++)
     {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
     }

    for(int i=0;i<numCourses;i++)
     {
        for(int j=0;j<adj[i].size();j++)
         {
            indegree[adj[i][j]]++;
         }
     }

    queue<int> q;
    for(int i=0;i<numCourses;i++)
     {
        if(indegree[i]==0)
            q.push(i);
     }
        
    while(!q.empty())
     {
        int u=q.front();
        s.push(u);
        q.pop();
        for(int i=0;i<adj[u].size();i++)
         {
            indegree[adj[u][i]]--;
            if(indegree[adj[u][i]]==0)
              q.push(adj[u][i]);
         }
     }
        
    if(s.size()==numCourses)
     {
        while(!s.empty())
         {
            result.push_back(s.top());
            s.pop();
         }
     }
    return result;
}


int main() {
    // your code goes here
    int numCourses=2;
    vector<vector<int>> prerequisites{{1,0},{0,1}};
    vector<int> ans=findOrder(numCourses,prerequisites);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
