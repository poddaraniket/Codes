//O(N*2^N)

class Solution {
public:
    
    void possible(vector<int>& nums,int index,vector<vector<int>> &result,vector<int> &v){
        result.push_back(v);
        for(int i=index;i<nums.size();i++){
            //do : (include karna hai)
            v.push_back(nums[i]);
            //recur
            possible(nums,i+1,result,v);
            //undo : (include nhi karna)
            v.pop_back();
        }
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> v;
        possible(nums,0,result,v);
        sort(result.begin(),result.end());
        return result;
    }
};