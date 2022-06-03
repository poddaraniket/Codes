class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1)
            return 0;
        if(n==2)
         {
            if(prices[1]>prices[0])
                return prices[1]-prices[0];
            return 0;
         }
        int profit[2][n];
        profit[0][0]=0;
        profit[1][0]=-1*prices[0];
        profit[0][1]=max(profit[0][0],profit[1][0]+prices[1]);
        profit[1][1]=max(profit[1][0],profit[0][0]-prices[1]);
        for(int i=2;i<n;i++)
         {
            profit[0][i]=max(profit[0][i-1],profit[1][i-1]+prices[i]);
            profit[1][i]=max(profit[1][i-1],profit[0][i-2]-prices[i]);
         }
        return profit[0][n-1];  
    }
};