//O(NlogN)

class Solution {
public:
    
    long long min(long long a,long long b){
        if(a<b)
            return a;
        return b;
    }
    
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long int totalCost=0;
        for(int i=0;i<beans.size();i++){
            totalCost+=beans[i];
        }
        cout<<totalCost<<endl;
        long long mini=LLONG_MAX;
        for(int i=0;i<beans.size();i++){
            long long cost=totalCost-((beans.size()-i+0L)*beans[i]);
            // cout<<cost<<endl;
            mini=min(mini,cost);
       }
        return mini;
    }
};