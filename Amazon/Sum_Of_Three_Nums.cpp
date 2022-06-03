//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> , int );

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        
        cout << threeSumClosest(vec, target) << "\n";
    }
}


 // } Driver Code Ends


// User function template for C++

// arr : given vector of elements
// target : given sum value

int threeSumClosest(vector<int> arr, int target) {
    // Your code goes here
    int first,last,closest_sum=INT_MAX;
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++)
     {
        first=i+1;
        last=n-1;
        while(first<last)
         {
            int sum=arr[i]+arr[first]+arr[last];
            if(abs(1LL*target-sum)<abs(1LL*target-closest_sum))
             closest_sum=sum;
            if(abs(1LL*target-sum)==abs(1LL*target-closest_sum))
            {
                closest_sum=max(closest_sum,sum);
            }
            if(sum<=target)
             first++;
            else
             last--;
         }
     }
    return closest_sum;  
}



// { Driver Code Starts.
  // } Driver Code Ends