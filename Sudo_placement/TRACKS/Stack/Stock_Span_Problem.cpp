#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to calculate span
// price[]: price array in input
// n: size of array
void calculateSpan(int price[], int n, int S[])
{
   // Your code here
   int i,count=0;
   stack<int> s,t;
   for(i=0;i<n;i++)
   {
      S[i]=1;
      count=0;
      if(s.empty() || price[i]<price[s.top()])
       {
           //S[i]=1;
           s.push(i);
       }
      else
       {
           while(!s.empty())
            {
                if(price[i]>=price[s.top()])
                 {
                    count+=S[s.top()];
                    s.pop();
                 }
                else
                 {
                    break;
                 }
            }
           S[i]+=count;
           s.push(i);
       }
   }
   
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n],s[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		calculateSpan(a, n, s);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends