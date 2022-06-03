

// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends

bool comp(pair<int,int>&a, pair<int,int>&b)
{
    return a.second>b.second;
}

// Prints minimum number of platforms reqquired 
void printJobScheduling(Job arr[], int n) 
{ 
    // your code here
    long long sum=0;
    int i,j,maxi=0,count=0;
    vector<pair<int,int>> v;
    for(i=0;i<n;i++)
     {
        maxi=max(maxi,arr[i].dead); 
        // cout<<arr[i].dead<<endl;
        v.push_back(make_pair(arr[i].dead,arr[i].profit)); 
     }
    sort(v.begin(),v.end(),comp);
    // for(i=0;i<v.size();i++)
    //  cout<<v[i].first<<" "<<v[i].second<<endl;
    int dp[maxi+1]={0};
    for(i=0;i<v.size();i++)
     {
        for(j=v[i].first;j>=1;j--)
         {
            if(dp[j]==0)
             {
                //cout<<v[i].second<<" "<<j<<endl; 
                dp[j]=v[i].second;
                sum+=v[i].second;
                count++;
                break;
             }
         }
     }
    cout<<count<<" "<<sum<<endl; 
} 



// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        Job arr[n];
        
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        printJobScheduling(arr, n);
    }
	return 0; 
}


  // } Driver Code Ends