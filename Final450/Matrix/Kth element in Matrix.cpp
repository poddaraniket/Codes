int NumberOfLesserElements(int mat[MAX][MAX], int n, int val){
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(mat[i][0]>val)
         return ans;
        if(mat[i][n-1]<=val)
         {
             ans+=n;
             continue;
         }
        for(int j=n-1;j>=0;j--)
        {
            if(mat[i][j]<=val)
             {
                 ans+=j+1;
                 break;
             }
        }
    }
    return ans;
}


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int low=mat[0][0];
  int high=mat[n-1][n-1];
  while(low<high){
      int mid=(low+high)/2;
      int count=NumberOfLesserElements(mat,n,mid);
      if(count<k)
       low=mid+1;
      else
       high=mid;
  }
  return low;
}