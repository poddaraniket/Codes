eg-1565554


#include <bits/stdc++.h>
using namespace std;

int search(string s,int l,int r,char key,int n)
{
    while(l<=r)
     {
        int mid=(l+r)/2;
        if(key>=s[mid])
         {
            r=mid-1; 
         }
        else if(key<s[mid])
         {
            if(key>=s[mid+1] || mid==n)
             return mid;
            else
             l=mid+1;
         }
     }
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    //char mini;
	    int f=-1;
	    string s;
	    cin>>s;
	    int i;
	    for(i=s.length()-1;i>0;i--)
	     {
	        if(s[i]>s[i-1])
	         {
	             //swap(s[i],s[i-1]);
	             break;
	         }
	     }
	    if(i==0)
	     cout<<"not possible"<<endl;
	    else
	     {
	       int index=search(s,i,s.length()-1,s[i-1],s.length()-1);
	       swap(s[i-1],s[index]);
	       sort(s.begin()+i,s.end());
	       cout<<s<<endl; 
	     }
	}
	return 0;
}