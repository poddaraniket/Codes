bool subArrayExists(int arr[], int n)
    {
        //Your code here
        map<int,int> mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(arr[i]==0 || sum==0)
             return true;
            if(mp[sum]!=0)
             return true;
            mp[sum]=1;
        }
        return false;
    }