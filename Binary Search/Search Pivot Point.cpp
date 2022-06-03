int pivot(vector<int>& nums){
        int s=0,e=nums.size()-1;
        while(s<e)
        {
            int m=s+(e-s)/2;
            if(nums[0]<=nums[m]) 
                s=m+1;
            else{
                e=m;
            }
        }
        return s;
    }
    
    int searchUtil(int s,int e,vector<int>& nums,int target){
        while(s<=e){
            int m=(s+e)/2;
            if(nums[m]==target)
               return m;
            if(nums[m]>target)
                e=m-1;
            else
                s=m+1; 
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        // find pivot element
        int index=pivot(nums);
        if(target>=nums[0])
           return searchUtil(0,index,nums,target);
        return searchUtil(index,nums.size()-1,nums,target);
    }