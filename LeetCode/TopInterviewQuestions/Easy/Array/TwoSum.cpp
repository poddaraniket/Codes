class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,deque<int>> mp;
        int l,r;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(int i=0;i<nums.size();i++){
            int need=target-nums[i];
            l=mp[nums[i]].front();
            mp[nums[i]].pop_front();
            if(mp[need].size()>0){
                r=mp[need].front();
                break;
            }
            mp[nums[i]].push_back(i);
        }
        vector<int> v;
        v.push_back(l);
        v.push_back(r);
        return v;
    }
};


/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> mp;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                 v.push_back(i);
                 v.push_back(mp[target-nums[i]]);
            }
            mp[nums[i]]=i;
        }
        return v;
    }
};

*/