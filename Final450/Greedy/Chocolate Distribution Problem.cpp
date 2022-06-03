long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    long long ans=INT_MAX;
    for(long long i=0;i<=n-m;i++)
     {
        ans=min(ans,a[i+m-1]-a[i]);
     }
     return ans;
    }   