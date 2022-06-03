#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,d,integral,residual;
	    int c=0,i;
	    cin>>n>>d;
	    string inte="",deci="";
	    integral=n/d;
	    inte+=to_string(integral);
	    int rem=n%d;
	    map<int,int> mp;
	    if(rem!=0)
	    {
	        while(rem!=0 && mp.find(rem)==mp.end())
	        {
	            mp[rem]=deci.length();
	            rem*=10;
	            residual=rem/d;
	            deci+=to_string(residual);
	            rem%=d;
	        }
	       if(rem==0)
	        cout<<inte<<"."<<deci<<endl;
	       else
	        {
	            string res_part=deci.substr(mp[rem]);
	            string resi_part=deci.substr(0,mp[rem]);
	            cout<<inte<<"."<<resi_part<<"("<<res_part<<")"<<endl;
	        }
	    }
	   else
	    cout<<inte<<endl;
	}
	return 0;
}