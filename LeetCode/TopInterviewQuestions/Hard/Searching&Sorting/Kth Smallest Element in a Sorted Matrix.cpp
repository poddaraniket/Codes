//O(NlogN)

class Solution {
public:
    
    //O(N)
    int findElementsLessThanMid(vector<vector<int>>& matrix, int val){
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]>val)
             return ans;
            if(matrix[i][m-1]<=val)
             {
                 ans+=m;
                 continue;
             }
            for(int j=m-1;j>=0;j--)
            {
                if(matrix[i][j]<=val)
                 {
                     ans+=j+1;
                     break;
                 }
            }
        }
        return ans;
    }
    
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=matrix[0][0];
        int high=matrix[n-1][m-1];
        //O(log|high-low|) -> O(logN)
        while(low<high){
          int mid=(low+high)/2;
          int count=findElementsLessThanMid(matrix,mid);
          if(count<k)
           low=mid+1;
          else
           high=mid;
        }
        return low;
    }
};