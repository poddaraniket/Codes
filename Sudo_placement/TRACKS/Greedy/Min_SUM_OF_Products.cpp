using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    long long int sum=0;
	    cin>>n;
	    int a[n],b[n];
	    for(i=0;i<n;i++)
	     cin>>a[i];
	    for(i=0;i<n;i++)
	     cin>>b[i]; 
	    sort(a,a+n);
	    sort(b,b+n);
	    for(i=0;i<n;i++)
	     sum+=(a[i]*b[n-i-1]);
	    cout<<sum<<endl; 
	}
	return 0;
}