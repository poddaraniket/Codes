class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long int sum=0;
        for(int i=0;i<target.size();i++){
            pq.push(target[i]);
            sum+=target[i];
        }
        while(pq.top()!=1){
            int u=pq.top();
            pq.pop();
            sum-=u;
            if(sum<=0 || sum>=u)
                return false;
            u%=sum; // it will 
            pq.push(u>0?u:sum);
            sum+=u;
        }
        return true;
    }
};