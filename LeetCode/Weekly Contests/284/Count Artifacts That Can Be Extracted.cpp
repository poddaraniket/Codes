//O(N^2)

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        for(int i=0;i<dig.size();i++){
            visited[dig[i][0]][dig[i][1]]=1;
        }
        int count=0;
        for(int k=0;k<artifacts.size();k++){
            vector<int> v=artifacts[k];
            int lr=v[0];
            int lc=v[1];
            int rr=v[2];
            int rc=v[3];
            bool flag=true;
            for(int i=lr;i<=rr;i++){
                for(int j=lc;j<=rc;j++){
                    if(visited[i][j]==0)
                        flag=false;
                }
            }
           if(flag)
               count++;
        }
       return count; 
    }
};