long long countPairs(int n, int arr[], int k) {
        // code here
        long long cnt=0;
        vector<long long> v(k);
        for(int i=0;i<n;i++)
         arr[i]=arr[i]%k;
        for(int i=0;i<n;i++)
         {
             v[arr[i]]++;
         }
        // (kn+k1) - (km+k2) / k possible only if (k1-k2=0 or k1=k2) 
        for(int i=0;i<k;i++)
         {
            // counting for ame frequency 
            cnt+=(v[i]*(v[i]-1))/2; 
         }
        return cnt; 
    }