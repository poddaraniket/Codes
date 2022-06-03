//O(N*N!)  // sarey permutation ko try kari -> N
class Solution {
public:
    
    void permutation(vector<int>& nums,int index,vector<vector<int>>& result){
        if(index==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            //do (swap karna hai)
            swap(nums[i],nums[index]);
            //recur
            permutation(nums,index+1,result);
            //undo (swap maat kar)
            swap(nums[i],nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutation(nums,0,result);
        sort(result.begin(),result.end());
        return result;
    }
};