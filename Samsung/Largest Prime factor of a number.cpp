long long int largestPrimeFactor(int N){
        // code here
        int maxPrime;
        while(N%2==0)
         {
             maxPrime=2;
             N/=2;
         }
        for(int i=3;i<=sqrt(N);i+=2)
        {
            while(N%i==0)
             {
                 maxPrime=i;
                 N/=i;
             }
        }
        if(N>2)
         maxPrime=max(maxPrime,N);
        return maxPrime; 
    }