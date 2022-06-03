//O(2^12 * 12) ~ O(10^3)

class Solution {
public:

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ans;
        int maxi=0;
        // all possible combniations 2^12 =4096
        for(int i=1;i<4096;i++){
            vector<int> bobArrows(12,0);
            int arrows=numArrows;
            int profit=0;
            for(int j=11;j>=0;j--){
                if(i & (1<<j)){
                    if(arrows<=aliceArrows[j])
                        continue;
                    arrows-=(aliceArrows[j]+1);
                    bobArrows[j]=aliceArrows[j]+1;
                    profit+=j;
                }
            }
            // just making sure all arrows are used
            for(int j=0;j<12;j++){
               if(i && (1<<j)){
                    bobArrows[j]+=arrows;
                    break;
                } 
            }
            if(profit>maxi){
                maxi=profit;
                ans=bobArrows;
            }
        }
        return ans;
    }
};