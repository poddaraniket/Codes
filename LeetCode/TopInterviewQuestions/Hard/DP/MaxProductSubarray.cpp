class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct=nums[0],minProduct=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                int temp=maxProduct;
                maxProduct=minProduct;
                minProduct=temp;
            }
            maxProduct=max(nums[i],maxProduct*nums[i]);
            minProduct=min(nums[i],minProduct*nums[i]);
            // cout<<maxProduct<<" "<<minProduct<<endl;
            ans=max(maxProduct,ans);
        }
       return ans;
    }
};