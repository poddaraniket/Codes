//O(2^N * N)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int possible=pow(2,n);
        vector<vector<int>> result; 
        for(int i=0;i<possible;i++){
            vector<int> v;
            for(int j=0;j<nums.size();j++){
                if(i & (1<<j)){
                    v.push_back(nums[j]);
                }
            }
            result.push_back(v);
        }
       return result; 
    }
};