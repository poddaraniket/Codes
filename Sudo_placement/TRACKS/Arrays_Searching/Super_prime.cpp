//Super prime is a prime number who is made of sum of two prime numbers


using namespace std;
#define MAX 10000007
#define ll long long int
//bool prime[10000001];
bitset <MAX> prime;
vector<ll> s;

void seive()
{
    ll p,i;
    prime[0]=1;
    prime[1]=1;
    //memset(a,true,sizeof(a));
    //cout<<prime[5]<<endl;
    for(p=2;p*p<=10000007;p++)
     {
         if(prime[p]==0)
          {
              for(i=p*p;i<=10000007;i+=p)
               {
                   prime[i]=1;
               }
          }
     }
    for(ll i=2;i<=10000007;i++)
    {
       if(prime[i]==0 && prime[i-2]==0)
       s.push_back(i);
    } 
}

int main() {
	//code
    //cout<<prime[3]<<endl; 
	int t;
	cin>>t;
	seive();
	while(t--)
	{
	    int n;
	    cin>>n;
	    ll c=upper_bound(s.begin(),s.end(),n)-s.begin();
	    cout<<c<<endl;
	}
	return 0;
}