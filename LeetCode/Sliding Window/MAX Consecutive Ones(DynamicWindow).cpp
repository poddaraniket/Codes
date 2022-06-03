class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
      int maxWindowSize=0; 
      int count=0;
      int windowStart=0,windowEnd;
      for(windowEnd=0;windowEnd<A.size();windowEnd++)
       {
         if(A[windowEnd]==0)
             count++;
         while(count>K)
          {
             maxWindowSize=max(maxWindowSize,windowEnd-windowStart);
             if(A[windowStart]==0)
                 count--;
             windowStart++;
          }
       }
      //cout<<windowStart<<endl;  
      return max(maxWindowSize,windowEnd-windowStart);   
    }
};