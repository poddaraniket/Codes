#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int temp;
	    string enc,dec="";
	    cin>>enc;
	    int exo=0;
	    for(int i=0;i<=enc.length()/2;i++)
	     {
	        if(enc[i]>='0' && enc[i]<='9')
	          temp=enc[i]-'0';
	        else
	         temp=enc[i]-55;
	        int c=exo^temp; 
	        exo^=c;
	        if(c<=9)
	          c+='0';
	        else
	         c+=55;
	        dec+=(char)c; 
	     }
	    cout<<dec<<endl; 
	}
	return 0;
}