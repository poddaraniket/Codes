using namespace std;

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 


int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   int n;
	   cin>>n;
	   int a[n];
	   for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	   if(n==1)
	    cout<<a[0]<<endl;
	   else
	    {
	        int c=gcd(a[0],a[1]);
	        for(int i=2;i<n;i++)
	         {
	           c=gcd(a[i],c);
	         }
	        cout<<c<<endl; 
	    }
	}
	return 0;
}