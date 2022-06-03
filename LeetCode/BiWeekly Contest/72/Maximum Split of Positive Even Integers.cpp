class Solution {
public:
    
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> v;
        if(finalSum%2!=0)
            return v;
        long long val=2;
        while(val<=finalSum){
            v.push_back(val);
            finalSum-=val;
            val+=2;
        }
        v[v.size()-1]+=finalSum; 
        return v;
    }
};