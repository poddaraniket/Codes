#include <bits/stdc++.h>
using namespace std;

string mobile[5]={"ABCD","EFGHIJK","LMNOPQ","RST","UVWXYZ"};

set<string> coll;

void possible(int a[],string s,int index,int n,auto mp)
{
    if(index==n)
     {
        coll.insert(s);
        return;
     }
    int dig=a[index];
    if(mp.find(dig)!=mp.end())
     {
        possible(a,s+mp[dig],index+1,n,mp); 
     }
    else
    {
    string temp=mobile[dig];
    for(int i=0;i<temp.length();i++)
     {
        mp[dig]=temp[i]; 
        possible(a,s+temp[i],index+1,n,mp);
     }
    //return; 
    }
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	 {
	     cin>>a[i];
	 }
	unordered_map<int,char> mp; 
	possible(a,"",0,n,mp);
	for(auto it=coll.begin();it!=coll.end();it++)
	  cout<<*it<<endl;
	return 0;
}
