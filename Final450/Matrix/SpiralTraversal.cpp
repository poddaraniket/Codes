void print(int startRow,int startCol,int row,int col,vector<vector<int> > matrix,vector<int>& v){
    if(startRow>=row || startCol>=col)
      return;
      
    //First ROW  
    for(int i=startCol;i<col;i++){
        //cout<<"#"<<matrix[startRow][i]<<endl;
        v.push_back(matrix[startRow][i]);
    }  
    
    //Last COL  
    for(int i=startRow+1;i<row;i++){
      // cout<<"*"<<matrix[i][col-1]<<endl;
       v.push_back(matrix[i][col-1]);
    }  
    
    //Last ROW  
    if(row-1!=startRow){
       for(int i=col-2;i>=startCol;i--){
          //cout<<"%"<<matrix[row-1][i]<<endl;
          v.push_back(matrix[row-1][i]);
        }  
    }
     
    
    //First COL
    if(col-1!=startCol){
        for(int i=row-2;i>startRow;i--){
          //  cout<<"_"<<matrix[i][startRow]<<endl;
            v.push_back(matrix[i][startRow]);
        } 
    }
    
    print(startRow+1,startCol+1,row-1,col-1,matrix,v);
}

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> v;
        print(0,0,r,c,matrix,v);
        return v;
    }
};