class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(target<matrix[0][0] || target>matrix[n-1][m-1])
           return false;
        for(int i=0;i<n;i++){
            int low=0,high=m-1,best=m;
            while(low<=high){
                int mid=(low+high)/2;
                if(matrix[i][mid]==target)
                    return true;
                else if(matrix[i][mid]>target){
                    best=high;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
           m=best; 
        }
        return false;
    }
};