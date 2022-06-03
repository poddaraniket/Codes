//O(N*M)

 Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected,int src,vector<bool> &vis){
        vis[src]=true;
        for(int j=0;j<isConnected.size();j++){
            if(!vis[j] && isConnected[src][j]==1)
                dfs(isConnected,j,vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int m=isConnected[0].size();
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(isConnected,i,vis);
            }
        }
        return count;
    }
};