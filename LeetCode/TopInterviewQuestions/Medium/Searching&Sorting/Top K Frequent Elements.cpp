//O(Nlogk)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // this removes probability of O(Nlogn) 
        if(nums.size()==k)//O(N)
            return nums;
        map<int,int> mp;
        //O(Nlogk)
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        priority_queue<pair<int,int>> pq;
        //O(klogK)
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        vector<int> v;
        while(k--){
            pair<int,int> p=pq.top();
            pq.pop();
            v.push_back(p.second);
        }
        return v;
    }
};