//Here the window will be taken of the elements to be rejected 

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) { 
      int totalSum=0,sum=0;
      int n=cardPoints.size();
      for(int i=0;i<n;i++)
          totalSum+=cardPoints[i];
      for(int i=0;i<n-k;i++)
       {
          sum+=cardPoints[i];
       }
      int maxPoss=totalSum-sum;
      for(int i=n-k;i<n;i++)
       {
          sum-=cardPoints[i-(n-k)];
          sum+=cardPoints[i];
          maxPoss=max(totalSum-sum,maxPoss);
       }
      return maxPoss;  
    }
};