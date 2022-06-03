//O(N)
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> zeros(n+1,0),ones(n+1,0);
        for(int i=0;i<n;i++){
            zeros[i+1]=zeros[i];
            zeros[i+1]+=(nums[i]==0) ? 1 : 0;
        }
        for(int i=n-1;i>=0;i--){
            ones[i]=ones[i+1];
            ones[i]+=(nums[i]==1) ? 1 : 0;
        }
        int maxi=0;
        vector<int> v;
        for(int i=0;i<=n;i++){
            int total=zeros[i]+ones[i];
            v.push_back(total);
            maxi=max(maxi,total);
        }
        vector<int> ans;
        for(int i=0;i<=n;i++){
            if(v[i]==maxi)
                ans.push_back(i);
        }
        return ans;
    }
};