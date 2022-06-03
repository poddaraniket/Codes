//Kanpsack exxample
//O(KN) k->num of types of tires ; N->num of laps

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        vector<long long int> withoutChange(19,INT_MAX);
        //Min time for ith lap (without changing tire)
        for(int i=0;i<tires.size();i++){
            int f=tires[i][0];
            int r=tires[i][1];
            long long int timeToComplete=0;
            for(int j=1;j<=numLaps;j++){
                long long int t=f*(long long int)pow(r,j-1);
                timeToComplete+=t;
                if(timeToComplete>pow(2,17)){
                    break;
                }
                withoutChange[j]=min(withoutChange[j],timeToComplete);
            }
        }
        long long int dp[numLaps+1];
        //Min time for ith lap (with changing tire)
        for(int i=1;i<=numLaps;i++){
            // changing in jth lap
            dp[i]=i<19 ? withoutChange[i] : INT_MAX;
            for(int j=1;j<i;j++){
                // i-j means change in jt lap so count till j +  min time to complete (i-j) laps already there in dp[i-j]
                dp[i]=min(dp[i],dp[j]+changeTime+dp[i-j]) ; 
            }
        }
        return dp[numLaps];
    }
};