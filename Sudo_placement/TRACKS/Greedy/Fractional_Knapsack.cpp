
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends



//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


bool comp(Item a,Item b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}
// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    int i=0;
   double finalans=0.0;
   sort(arr,arr+n,comp);
   while(W!=0 && i<n)
    {
        if(arr[i].weight<=W)
         {
            W-=arr[i].weight;
            finalans+=arr[i].value;
         }
        else
         {
            finalans+=((double)arr[i].value/arr[i].weight)*W;
            W=0;
         }
        i++; 
    }
   return finalans;     
}

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends