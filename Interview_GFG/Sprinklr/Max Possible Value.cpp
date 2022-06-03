long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code 
        long long ans=0,x,y;
        long long mini=1e10,tot=0;
        for(int i=0;i<N;i++)
         {
             x=A[i];
             y=B[i];
             // Only even numbers of side included
             if(y%2!=0)
              y--;
             // to know which is the smallest  value (if needed to exclude)
             // ony those included in comparison those have sides
             if(y>=2)
              mini=min(mini,x);
             ans+=(y*x);
             tot+=y; // how many sides have been included in total so far
         }
        // we need 4n sides to make rectangle / squares
        // means we have extra side [it can be only 2 so remove the smallest one]
        if(tot%4!=0)
         {
            ans-=mini*2; 
         }
        return ans; 
    }