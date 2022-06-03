int findPeakElement(vector<int>& nums) {
       if(nums.size()==1)
            return 0;
       int s=0,e=nums.size()-1;
        while(s<e){
            int m=(s+e)/2;
            if(nums[m]<nums[m+1]){
                s=m+1;
            }else
            {
                e=m;  // we assumed here the mid we get is either the ans or in the descending section
            }
        }
       return s; 
    }