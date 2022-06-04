class Solution {
public:
    
    vector<vector<string>> ans;
    int n;
    
    bool isSafe(int row,int col,vector<string> queens){
        int n=queens.size();
        for(int i=0;i<row;i++){
            if(queens[i][col]=='Q')
                return false;
        }
        //left diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(queens[i][j]=='Q'){
                return false;
            }
        }
        
        //right diagonal
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(queens[i][j]=='Q')
                return false;
        }
        return true;
    }
    
    void solve(vector<string> queens,int row){
        int n=queens.size();
        if(row>=n){
            cout<<queens[0]<<endl;
            ans.push_back(queens);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(row,col,queens)){
                queens[row][col]='Q';
                solve(queens,row+1);
                queens[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++){
            s+='.';
        }
        vector<string> queens(n,s);
        solve(queens,0);
        return ans;
    }
};