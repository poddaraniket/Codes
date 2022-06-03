bool cmp(pair<string,int> a,pair<string,int> b){
    return a.second>b.second;
}

class Solution
{
  public:
  
    string secFrequent (string arr[], int n)
    {
        //code here.
        vector<pair<string,int>> v;
        sort(arr,arr+n);
        int freq=1;
        int i;
        for(i=0;i<n-1;i++){
            if(arr[i]==arr[i+1])
              freq++;
            else{
               v.push_back({arr[i],freq});
               freq=1;
            }
        }
        v.push_back({arr[i],freq});
        sort(v.begin(),v.end(),cmp);
        return v[1].first;
    }
};
