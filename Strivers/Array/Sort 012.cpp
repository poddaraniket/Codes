// left of low is 0 && right of high is 2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==1)
            return;
        int l=0,m=0,h=nums.size()-1;
        while(m<=h){
            if(nums[m]==0){
                // here we no till m al elements are in correct position
                swap(nums[m++],nums[l++]);
            }else if(nums[m]==2){
                // m not increased bcoz not sure of it position
                swap(nums[m],nums[h--]);
            }else{
                m++;
            }
        }
    }
};