#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool comp(pair<int,int>&a, pair<int,int>&b)
{
    return(a.second<b.second);
}


int activitySelection(int start[], int end[], int n){
    // Your code here
    int i,j;
    int dp[n];
    vector<pair<int,int>> v;
    for(i=0;i<n;i++)
    {
      v.push_back(make_pair(start[i],end[i]));
    }
    sort(v.begin(),v.end(),comp);
    //cout<<v[0].second<<endl;
    //cout<<v[0].second<<endl;
    int temp=0,count=0;
    for(i=0;i<n;i++)
     {
        if(v[i].first<temp)
         continue;
        count++;
        temp=v[i].second; 
     }
    return count;  
}

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        
        cout << activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends