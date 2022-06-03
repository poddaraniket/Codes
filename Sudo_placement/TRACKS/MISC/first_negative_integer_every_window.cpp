
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    queue<int> q;
	    int n,i;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	     {
	        cin>>a[i];
	        if(a[i]<0)
	         q.push(i);
	     }
	    int k;
	    cin>>k;
	    for(i=0;i<=n-k;i++)
	     {
	        if(q.front()>=i && q.front()<i+k)
	         cout<<a[q.front()]<<" ";
	        else
	         cout<<"0"<<" ";
	        if(q.front()==i)
	         q.pop();
	     }
	    cout<<endl; 
	}
	return 0;
}