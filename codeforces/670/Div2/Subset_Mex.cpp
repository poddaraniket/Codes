#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
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
	    vector<int> left(202,0),right(202,0);
	    for(int i=0;i<n;i++)
	     {
	       // cout<<"*"<<endl; 
	        if(left[a[i]]==0)
	         left[a[i]]=1;
	        else
	         right[a[i]]=1;
	     }
	    int meal=-1,mear=-1; 
	    for(int i=0;i<=100;i++)
	     {
	       //  cout<<"*"<<endl;
	         if(meal!=-1 && (mear!=-1 || right.size()==0))
	          break;
	         if(left[i]==0 && meal==-1)
	          meal=i;
	         if(right[i]==0 && mear==-1 && right.size()>0)
	          mear=i;
	     }
	    if(mear==-1)
	     cout<<meal+0<<endl;
	    else
	     cout<<meal+mear<<endl;
	}
	return 0;