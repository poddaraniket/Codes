class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        if(nums[0]==0)
            return false;
        int steps=0+nums[0],maxReach=0;
        for(int i=1;i<nums.size();i++){
            maxReach=max(nums[i]+i,maxReach);
            if(maxReach==nums.size()-1)
              return true;
            steps--;
            if(steps==0){
               if(i>=maxReach)
                   return false;
               steps=maxReach-i; 
            }
        }
        return true;
    }
};