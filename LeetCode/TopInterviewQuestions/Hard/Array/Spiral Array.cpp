class Solution {
public:
    
    void printSpiral(vector<vector<int>>& matrix,int rowStart,int rowEnd,int colStart,int colEnd,vector<int>& v)     {
        //First Row
        for(int j=colStart;j<=colEnd;j++){
            v.push_back(matrix[rowStart][j]);
        }
        //Last Column
        for(int i=rowStart+1;i<=rowEnd;i++){
            v.push_back(matrix[i][colEnd-1]);
        }
        
        //Last Row
        for(int j=colEnd-1;j>=colStart;j--){
            v.push_back(matrix[rowEnd-1][j]);
        }
        
        //First Column
        for(int i=rowEnd-1;i>rowStart;i--){
            v.push_back(matrix[i][colStart]);
        }
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int rowStart=0,rowEnd=matrix.size()-1,colStart=0,colEnd=matrix[0].size()-1;
        while(rowStart<=rowEnd && colStart<=colEnd){
            //First Row from remaining
            for(int j=colStart;j<=colEnd;j++){
               v.push_back(matrix[rowStart][j]);
            }
            rowStart++;
            // Last Column form remainig
             for(int i=rowStart;i<=rowEnd;i++){
                v.push_back(matrix[i][colEnd]);
             }
            colEnd--;
            //Last Row from remaining
            if(rowEnd>=rowStart){
                for(int j=colEnd;j>=colStart;j--){
                    v.push_back(matrix[rowEnd][j]);
                }
                rowEnd--;
            }
             // First Column form remainig
            if(colEnd>=colStart){
              for(int i=rowEnd;i>=rowStart;i--){
                v.push_back(matrix[i][colStart]);
              }
             colStart++;  
            }
        }
        return v;
    }
};