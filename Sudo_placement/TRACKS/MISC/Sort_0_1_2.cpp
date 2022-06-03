using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,pivot=0;
	    cin>>n;
	    int a[n],b[n];
	    for(i=0;i<n;i++)
	     cin>>a[i];
	    for(i=0;i<n;i++)
	     {
	        if(a[i]==0)
	         b[pivot++]=0;
	     }
	    for(i=0;i<n;i++)
	     {
	        if(a[i]==1)
	         b[pivot++]=1;
	     }
	    for(i=0;i<n;i++)
	     {
	        if(a[i]==2)
	         b[pivot++]=2;
	     } 
	    for(i=0;i<n;i++)
	     {
	        cout<<b[i]<<" ";
	     } 
	    cout<<endl; 
	}
	return 0;
}