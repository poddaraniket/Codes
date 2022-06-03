using namespace std;


long long int blk;

struct Query{
    long long int L,R,index;
};

bool comp(Query x1,Query x2)
{
    if(x1.L/blk!=x2.L/blk)
     return (x1.L/blk)<(x2.L/blk);
    else
     return x1.R < x2.R;
}

void queryResults(long long int a[],Query q[],long long int n,long long int m,long long int freq[],long long int k)
{
    long long int ans[10011]={0};
    long long int currL=0,currR=0,count=0;
    for(long long int i=0;i<m;i++)
     {
        long long int l=q[i].L-1;
        long long int r=q[i].R-1;
        while(currR<=r)    // R is included in the count
         {
            freq[a[currR]]++;
            if(freq[a[currR]]==k)
             count++;
            currR++; 
         }
        while(currL>l)   // L is not include in the count
         {
             freq[a[currL-1]]++;
             if(freq[a[currL-1]]==k)
              count++;
             currL--; 
         }
        while(currL<l)
         {
             freq[a[currL]]--;
             if(freq[a[currL]]==k-1)
              count--;
             currL++; 
         }
        while(currR>r+1)
         {
             freq[a[currR-1]]--;
             if(freq[a[currR-1]]==k-1)
              count--;
             currR--; 
         }
        ans[q[i].index]=count; 
     }
    for(long long int i=0;i<m;i++)
     {
        cout<<ans[i]<<" "; 
     }
}

int main() {
	// your code goes here
	long long int t;
	cin>>t;
	while(t--)
	{
	    long long int n,m,k;
	    cin>>n>>m>>k;
	    long long int a[n];
	    for(long long int i=0;i<n;i++)
	     {
	         cin>>a[i];
	     }
	    Query q[10011];
	    for(long long int i=0;i<m;i++)
	     {
	         cin>>q[i].L>>q[i].R;
	         q[i].index=i;
	     }
	    //cout<<"*"<<endl; 
	    long long int freq[1001]={0};
	    blk=sqrt(n);
	    sort(q,q+m,comp);
	    //cout<<"*"<<endl;
	    queryResults(a,q,n,m,freq,k);
	    cout<<endl;
	}
	return 0;
}
