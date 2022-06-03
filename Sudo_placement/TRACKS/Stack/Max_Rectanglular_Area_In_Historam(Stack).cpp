#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array
long getMaxArea(long long arr[], int n){
    
    // Your code here
    stack<long> s;
    long i,maxarea=-1,area;
    for(i=0;i<n;)
    {
      if(s.empty() || arr[i]>=arr[s.top()])
        s.push(i++);
      else
       {
         int j=s.top();
         s.pop();
         if(s.empty())
           area=arr[j]*i;
         else
          {
            area=arr[j]*(i-s.top()-1);
          }
         maxarea=max(area,maxarea);  
       }
    }     
    while(!s.empty())
    {
      int j=s.top();
      s.pop();
      if(s.empty())
        area=arr[j]*i;
      else
       {
         area=arr[j]*(i-s.top()-1);
       }
      maxarea=max(area,maxarea);  
    }
    return maxarea;
}

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends