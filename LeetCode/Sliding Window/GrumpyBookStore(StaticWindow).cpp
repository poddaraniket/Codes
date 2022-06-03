class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
     int n=customers.size();
     int maxPoss=0;   
     int grumpyCount=0,nongrumpyCount=0;
     for(int i=0;i<X;i++)
      {
         if(grumpy[i]==0)
             nongrumpyCount+=customers[i];
         if(grumpy[i]==1)
            grumpyCount+=customers[i]; 
      }
      maxPoss=max(maxPoss,grumpyCount);  
      for(int i=X;i<n;i++)
      {
          if(grumpy[i-X]==1)
             grumpyCount-=customers[i-X];
          if(grumpy[i]==0)
             nongrumpyCount+=customers[i];
          if(grumpy[i]==1)
             grumpyCount+=customers[i];
          maxPoss=max(maxPoss,grumpyCount);
      }
      return nongrumpyCount+max(maxPoss,grumpyCount);  
    }
};