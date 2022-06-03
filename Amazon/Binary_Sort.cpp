//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;
vector<int> SortBinaryArray(vector<int> binArray);


 // } Driver Code Ends


//User function template for C++

// binArray is an array that consists only 0s and 1s
// return sorted binary array 
vector<int> SortBinaryArray(vector<int> binArray)
{
    // Your code goes here
    int n=binArray.size();
    int first=0,last=n-1;
    while(first<last)
     {
        if(binArray[first]==1)
         {
            if(binArray[last]==0)
             {
                int temp=binArray[first];
                binArray[first]=binArray[last];
                binArray[last]=temp;
                first++;
                last--;
             }
            else
             {
                last--; 
             }
         }
        else
         {
            if(binArray[last]==1)
             {
                last--;
             }
            first++;
         }
     }
    return binArray; 
}


// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> binArray(n);
	    
	    for(int i = 0; i  < n; i++)
	      cin>>binArray[i];
	      
	  	vector<int> result = SortBinaryArray(binArray);
	  	for(int i=0; i<n; i++)
	  	    cout<<result[i]<<" ";
	      
	    cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends