using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long sum=0;
	    int n;
	    cin>>n;
	    sum=(n*(n+1)*(2*n+1))/6;
	    cout<<sum<<endl; 
	}
	return 0;
}