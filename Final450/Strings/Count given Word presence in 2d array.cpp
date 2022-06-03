int calc(vector<vector<char> > &mat, string target,int i,int j,int row,int col,int idx)
{
    int count=0;
    if(i>=0 && i<row && j>=0 && j<col && target[idx]==mat[i][j]){
      char temp=mat[i][j];
      mat[i][j]='0';
      idx++;    
      if(idx==target.length())
       count=1;
      else{
        count+=calc(mat,target,i+1,j,row,col,idx);
        count+=calc(mat,target,i-1,j,row,col,idx);
        count+=calc(mat,target,i,j+1,row,col,idx);
        count+=calc(mat,target,i,j-1,row,col,idx);  
      } 
      mat[i][j]=temp;
    }
    return count;
}


class Solution{
    public:
    int findOccurrence(vector<vector<char> > &mat, string target){
        int count=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                count+=calc(mat,target,i,j,mat.size(),mat[0].size(),0);
            }
        }
        return count;
    }
};