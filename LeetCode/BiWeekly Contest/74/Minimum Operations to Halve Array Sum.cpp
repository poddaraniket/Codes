//O(NlogN)
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double total=0,sum=0;
        for(int i=0;i<nums.size();i++){
            total+=(double)nums[i];
            pq.push((double)nums[i]);
        }
        sum=total/2.0;
        int count=0;
        while(1){
            if(total<=sum)
                break;
            count++;
            double val=pq.top();
            pq.pop();
            val/=2.0;
            total-=val;
            pq.push(val);
        }
        return count;
    }
};