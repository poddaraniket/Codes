class Solution {
public:
    
    bool isSafe(int row,int col,vector<int> columns,vector<int> lDig,vector<int> rDig,int n)     {
        if(columns[col] || lDig[row-col+n-1] || rDig[row+col]){
            return false;
        }
        return true;
    }
    
    void Queens(int n,int currRow,vector<int> columns,vector<int> lDig,vector<int> rDig,int &ans){
        if(currRow==n){
            ans++;
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(currRow,col,columns,lDig,rDig,n)){
                columns[col]=1;
                lDig[currRow-col+n-1]=1;
                rDig[currRow+col]=1;
                Queens(n,currRow+1,columns,lDig,rDig,ans);
                columns[col]=0;
                lDig[currRow-col+n-1]=0;
                rDig[currRow+col]=0;
            }
        }
    }
    
    int totalNQueens(int n) {
        int ans=0;
        vector<int> columns(n,0);
        vector<int> lDig(2*n-1,0),rDig(2*n-1,0);
        Queens(n,0,columns,lDig,rDig,ans);
        return ans;
    }
};