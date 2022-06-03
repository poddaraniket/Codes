

int maxSumSubarray(int [], int );

int main() {
	// your code goes here
	
	//taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking total elements
		int n;
		cin>>n;
		int a[n];
		
		//inserting elements in the array
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		
		//calling method maxSumSubarray()
		cout<<maxSumSubarray(a,n)<<endl;
	}
}

// } Driver Code Ends


/*You are required to complete below method */
int maxSumSubarray(int A[], int n)
{
    //Your code here
    int with_deletion=0;
    int without_deletion=A[0];
    int ans=-1000000;
    for(int i=1;i<n;i++)
     {
        /*wihtout_deletion here means u r ignoring current element
with_del+A[i] means u have ignored one element before & keeping curr element
        */
        with_deletion=max(without_deletion,with_deletion+A[i]);
        
        /*
         here either u start from current element 
         or include curr element with previous ones
        */
        without_deletion=max(A[i],without_deletion+A[i]);
        ans=max(ans,max(with_deletion,without_deletion));
     }
    return ans; 
}