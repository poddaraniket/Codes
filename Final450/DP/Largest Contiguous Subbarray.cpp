int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int curr_max=0,max_so_far=-10000000;
        for(int i=0;i<n;i++)
         {
             curr_max+=arr[i];
             max_so_far=max(max_so_far,curr_max);
             if(curr_max<0)
              curr_max=0;
         }
        return max_so_far; 
    }