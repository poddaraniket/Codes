class Solution {
public:
    int minSwaps(vector<int>& nums) {
       int window=0;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                window++;
        }
        int k=2;
        while(k--){
           for(int i=0;i<nums.size();i++){
              v.push_back(nums[i]);
          } 
        }
        
        int zeros=0;
        for(int i=0;i<window;i++){
            if(v[i]==0)
                zeros++;
        }
        int mini=zeros;
        for(int i=window;i<v.size();i++){
            if(v[i-window]==0)
                zeros--;
            if(v[i]==0)
                zeros++;
            mini=min(mini,zeros);
        }
        return mini;
    }
};