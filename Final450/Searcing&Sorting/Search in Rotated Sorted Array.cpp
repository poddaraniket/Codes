    int search(vector<int>& nums, int target) {
        // Divide and Conquer 
        // Search always done in sorted segment
        // shift to that segement where ur no. can fall into
        int start=0,end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target)
               return mid;  
            // looking for sorted segemnt
            if(nums[mid]<nums[end]){
                //Checking of that target lies in that range else shift to other segment
                if(target>nums[mid] && target<=nums[end])
                    start=mid+1;
                else
                    end=mid-1; 
            }
            else {
                if(target>=nums[start] && target<nums[mid])
                    end=mid-1;
                else
                    start=mid+1;
            }
        }
        return -1;     
    }