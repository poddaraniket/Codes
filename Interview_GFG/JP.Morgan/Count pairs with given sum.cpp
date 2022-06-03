 int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
         {
           mp[arr[i]]++;
         }
        int cnt=0; 
        for(auto it : mp){
            int val=it.first;
            int freq=it.second;
            if(k%2==0 && k/2==val)
             {
                 cnt+=freq*(freq-1)/2;
             }
            else
             {
                 if(mp.find(k-val)!=mp.end()){
                  cnt+=mp[val]*mp[k-val];
                  mp[k-val]=0;
                 }
                  
             }
            mp[val]=0; 
        }
        return cnt;
    }