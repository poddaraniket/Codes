// T->O(N*M)  S->O(N+M) 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0){
                   row.insert(i);
                   col.insert(j) ;
                }
            }
        }
        for(auto s : row){
            for(int i=0;i<matrix[0].size();i++)
            {
                matrix[s][i]=0;
            }
        }
        for(auto c : col){
            for(int i=0;i<matrix.size();i++)
            {
                matrix[i][c]=0;
            }
        }
    }
};