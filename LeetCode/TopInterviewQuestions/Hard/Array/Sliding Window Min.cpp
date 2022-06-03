class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n=nums.size();
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        vector<int> v;
        for(int i=k;i<n;i++){
            v.push_back(nums[dq.front()]);
            while(!dq.empty() && dq.front()<=i-k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        v.push_back(nums[dq.front()]);
        return v;
    }
};