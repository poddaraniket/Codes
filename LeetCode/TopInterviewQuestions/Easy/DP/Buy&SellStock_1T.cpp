class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> left(n,0);
        left[0]=prices[0];
        vector<int> right(n,0);
        right[n-1]=prices[n-1];
        for(int i=1;i<n;i++)
            left[i]=min(left[i-1],prices[i]);
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],prices[i]);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,right[i]-left[i]);
        }
        return maxi;
    }
};