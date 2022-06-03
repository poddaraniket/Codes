// O(N*log(logN))

 vector<int> primeRange(int M, int N) {
        // code here
        bool prime[N+1];
        memset(prime,true,sizeof(prime));
        for(int p=2;p*p<=N;p++)
         {
             if(prime[p])
              {
                  for(int i=p*p;i<=N;i+=p)
                   {
                       prime[i]=false;
                   }
              }
         }
        vector<int> v;
        for(int i=2;i<=N;i++)
         {
             if(i>=M && prime[i])
              v.push_back(i);
         }
        return v; 
    }