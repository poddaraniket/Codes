int distinctSubKOdds(vector<int> arr, int n, int k)
{
	// Write your code here
    set<string> st;
    map<string,pair<int,int>> mp;
    vector<string> s;
    vector<int> v(n,0);
     s.push_back(to_string(arr[0]));
    if(arr[0]%2==1)
        v[0]=1;
    for(int i=1;i<n;i++){
        s.push_back(to_string(arr[i]));
        v[i]=v[i-1];
        if(arr[i]%2==1){
            v[i]++;
        }
    }
    int ans=0;
    //O(N^3)
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int count=v[j];
            if(i>0){
               count-=v[i-1]; 
            }
            if(count<=k){
                string t="";
                for(int k=i;k<=j;k++){
                    t+=s[k];
                    t+='-';
                }
                st.insert(t);
            }
        }
    }
    return st.size();
}