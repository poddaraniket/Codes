using namespace std;

bool comp(pair<int,int> a, pair<int,int> b)
{
    return ((double)a.first/(double)a.second)>((double)b.first/(double)b.second);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    vector<pair<int,int>> v;
	    int n,W,i;
	    cin>>n>>W;
	    int a[2*n];
	    for(int i=0;i<2*n;i++)
	     cin>>a[i];
	    for(int i=0;i<2*n;i+=2)
	    {
	       v.push_back(make_pair(a[i],a[i+1])); 
	    }
	    
	    // sort vector by max value for each kg
	    sort(v.begin(),v.end(),comp);
	    
	    // fractional knapsack
	    double final_ans=0.0;
	    for(i=0;i<v.size();i++)
	    {
	       if(v[i].second<=W)
	        {
	            W-=v[i].second;
	            final_ans+=(double)v[i].first;
	        }
	       else
	        {
	            final_ans+=(double)((double)v[i].first/(double)v[i].second)*W;
	            W=0;
	            break;
	        }
	    }
	   cout<<fixed<<setprecision(2)<<final_ans<<endl; 
	}
	return 0;
}