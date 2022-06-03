class NumMatrix {
public:
    
    vector<vector<int>> sum;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        sum=vector<vector<int>> (m,vector<int>(n));
        sum[0][0]=matrix[0][0];
        for(int j=1;j<n;j++){
            sum[0][j]=sum[0][j-1]+matrix[0][j];
        }
        for(int i=1;i<m;i++){
            sum[i][0]=sum[i-1][0]+matrix[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=sum[row2][col2];
        if(row1-1>=0){
            ans-=sum[row1-1][col2];
        }
        if(col1-1>=0){
            ans-=sum[row2][col1-1];
        }
        if(row1-1>=0 && col1-1>=0){
            ans+=sum[row1-1][col1-1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */