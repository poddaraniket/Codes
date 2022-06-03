//O(N)
// Inplace and keeping the Order maintained
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)
             return 1;
        int index=0;
        for(int i=0;i<nums.size();){
            int val=nums[i];
            nums[index++]=val;
            while(val==nums[i]){
                  i++;
                if(i==nums.size())
                   break;  
            }
        }
        return index;
    }
};