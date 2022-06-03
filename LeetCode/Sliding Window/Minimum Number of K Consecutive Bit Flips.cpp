class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
      int n=A.size();  
      bool hasflipped[A.size()];
      memset(hasflipped,false,sizeof(hasflipped));
      int timesitflipped=0,ans=0;
      for(int i=0;i<n;i++)
      {
          if(i>=K)
          {
              if(hasflipped[i-K])
                  timesitflipped-=1;
          }
          if(A[i]==0 && (timesitflipped%2)==0)
          {
              //cout<<"*"<<endl;
              if(i+K>n)
                 return -1; 
              timesitflipped+=1;
              ans++;
              hasflipped[i]=true;
          }
          else if(A[i]==1 && (timesitflipped%2)==1)
          {
              if(i+K>n)
                 return -1;
              timesitflipped+=1;
              ans++;
              hasflipped[i]=true;
          }
      }
     return ans;   
    }
};