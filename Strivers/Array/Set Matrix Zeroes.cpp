// T->O(m*n) S->O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row=false,col=false;
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                row=true;
                break;
            }
        }
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                col=true;
                break;
            }
        }
        
        
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    // cout<<i<<" "<<j<<endl;
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        // column -> 0
        for(int j=1;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                for(int i=1;i<matrix.size();i++){
                    matrix[i][j]=0;
                }
            }
        }
        //row->0
        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]==0){
                for(int j=1;j<matrix[0].size();j++){
                    matrix[i][j]=0;
                }
            }
        }
        if(row){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j]=0;
            }
        }
        if(col){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
    }
};