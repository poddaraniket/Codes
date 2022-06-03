class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n=nums.size();
        bool isExist=false;
       for(int i=0;i<n;i++){
           if(nums[i]==1)
           {
               isExist=true;
               break;
           }
       }
       if(!isExist)
           return 1;
        // convert unwanted numbers to 1
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n)
                nums[i]=1;
        }
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                return i+1;
        }
        return n+1;
    }
};