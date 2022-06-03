#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends




vector <int> nearlySorted(int arr[], int num, int K){
    // Your code here
    vector<int> v;
    // priority_queue<int,vector<int>,greater<int>> pq(arr,arr+num);
    // while(!pq.empty())
    //  {
    //     v.push_back(pq.top());
    //     pq.pop();
    //  }
    if(K<num)
     {
        priority_queue<int,vector<int>,greater<int>> pq(arr,arr+K+1);
        int index=0;
        for(int i=K+1;i<num;i++)
         {
            v.push_back(pq.top());
            pq.pop();
            pq.push(arr[i]);
         }
        while(!pq.empty())
         {
            v.push_back(pq.top());
            pq.pop();
         }
     }
    else
     {
        priority_queue<int,vector<int>,greater<int>> pq(arr,arr+num);
        while(!pq.empty())
        {
            v.push_back(pq.top());
            pq.pop();
        } 
     }
    return v;  
}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    
	    vector <int> res = nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends