#include <bits/stdc++.h>
using namespace std;

vector<string> v;

void Power(string s,int index,string curr)
{
    if(index==s.length())
     {
      v.push_back(curr);
      return;
     }
    Power(s,index+1,curr+s[index]);
    Power(s,index+1,curr);
}

vector <string> powerSet(string s)
{
   //Your code here
   v.clear();
   Power(s,0,"");
   return v;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   string s;
	   cin>>s;
	   vector<string> ans=powerSet(s);
	   sort(ans.begin(),ans.end());
	   for(int i=0;i<v.size();i++)
	    cout<<ans[i]<<" ";
	   cout<<endl;
	}
	return 0;
}