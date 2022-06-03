class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            vector<int> v=prerequisites[i];
            adj[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> v;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            v.push_back(u);
            for(int i=0;i<adj[u].size();i++){
                indegree[adj[u][i]]--;
                if(indegree[adj[u][i]]==0)
                    q.push(adj[u][i]);
            }
        }
        if(v.size()==numCourses)
            return true;
        return false;
    }
};