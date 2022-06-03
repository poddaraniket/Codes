#include<biys/stdc++.h>

using namespace std;

int remainderWith7(string n)
{
	int i,s=0;
    for(i=0;i<n.length();i++)
     {
        s=(s*10)+(n[i]-'0');
        if(s>=7)
         {
            s%=7;
         }
     }
    return s; 
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	  string s;
	  cin>>s;
	  cout<<remainderWith7(s)<<endl;
	}
}