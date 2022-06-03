class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i=0;i<k;i++){
            int val=pq.top();
            pq.pop();
            val++;
            pq.push(val);
        }
        long long int pro=1;
        while(!pq.empty()){
            int val=pq.top();
            pq.pop();
            pro*=val;
            pro%=1000000007;
        }
        return (int)pro;
    }
};