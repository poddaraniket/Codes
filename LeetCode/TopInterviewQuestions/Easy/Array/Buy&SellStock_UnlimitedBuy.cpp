//O(N) -> O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],sell=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<prices[i-1]){
               ans+=(sell-buy);
                buy=prices[i];
                sell=prices[i];
            }
            else{
                sell=prices[i];
            }
        }
        ans+=(sell-buy);
        return ans;
    }
};