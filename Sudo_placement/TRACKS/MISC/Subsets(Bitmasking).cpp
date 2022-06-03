using namespace std;

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
	     cin>>a[i];
	    sort(a,a+n);
	    set<vector<int>> s;
	    vector<int> v;
	    for(int i=0;i<pow(2,n);i++)
	     {
	         v.clear();
	         for(int j=0;j<n;j++)
	          {
	              if(i&1<<j)
	               v.push_back(a[j]);
	          }
	         s.insert(v); 
	     }
	    for(auto it=s.begin();it!=s.end();it++)
	     {
	         vector<int> temp=*it;
	         int len=temp.size();
	         cout<<"(";
	         for(int i=0;i<len;i++) 
	          {
	              cout<<temp[i];
	              if(i!=len-1)
	               cout<<" ";
	          }
	         cout<<")"; 
	     }
	   cout<<endl;  
	}
	return 0;
}