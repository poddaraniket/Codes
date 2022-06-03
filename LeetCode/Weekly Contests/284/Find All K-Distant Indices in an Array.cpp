//O(N+M)
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> indices;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key)
                indices.push_back(i);
        }
        int j=0,i=0;
        vector<int> ans;
        while(j<indices.size()){
            if(i<=indices[j]){
                if(j>0 && i-indices[j-1]<=k)
                    ans.push_back(i);
                else if(indices[j]-i<=k)
                    ans.push_back(i);
                i++;
            }
            else{
                j++;
            }
        }
        j--;
        while(i<nums.size()){
            if(i-indices[j]<=k)
                ans.push_back(i++);
            else
               break; 
        }
        return ans;
    }
};