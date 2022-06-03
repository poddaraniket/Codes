int binarySearchCol(vector<int> matrix,int target,int low,int high){
    int mid=(low+high)/2; 
    while(low<=high){
        if(target<matrix[mid])
            high=mid-1;
        else if(target>matrix[mid])
            low=mid+1;
        else
            return true;
        mid=(low+high)/2;
    }
    return false;
}


int binarySearchRow(vector<vector<int>>& matrix,int target,int low,int high){
    int mid=(low+high)/2;
    //int mid;
    while(low<high){
        if(target<matrix[mid][0]){
           high=mid-1; 
        }
        else{
           if(target>=matrix[mid+1][0])
               low=mid+1;
           else
            return mid;
        }
        mid=(low+high)/2;
    }
    return mid;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int index=0;
        if(matrix.size()>1){
            index=binarySearchRow(matrix,target,0,matrix.size()-1);
        }    
        return binarySearchCol(matrix[index],target,0,matrix[index].size()-1);
    }
};