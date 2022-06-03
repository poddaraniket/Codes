ll findSubarray(vector<ll> arr, int n ) {
        //code here 
        unordered_map<ll,int> mp;
        mp[0]=1;
        int count=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp[sum]!=0)
             {
                 count+=mp[sum];
                 mp[sum]++;
             }
            else
              mp[sum]=1;
        }
        return count;
    }