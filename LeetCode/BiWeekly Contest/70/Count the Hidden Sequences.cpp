class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long sum=0;
        long long mini=sum,maxi=sum;
        for(int i=0;i<differences.size();i++){
            sum+=differences[i];
            maxi=max(maxi,sum);
            mini=min(mini,sum);
        }
        long up=upper-maxi,lb=lower-mini;
        return (up-lb+1)>0 ? up-lb+1:0;
    }
};