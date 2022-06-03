#include <bits/stdc++.h>
using namespace std;

bool check(string s1,string s2,string res){
    int l=0,r=0;
    if(s1.length()+s2.length()!=res.length()){
        return false;
    }
    for(int i=0;i<res.length();i++){
        if(l<s1.length() && s1[l]==res[i])
          l++;
        else if(r<s2.length() && s2[r]==res[i])
         r++;
        else
          return false;
    }
    if(l<s1.length() && r<s2.length())
     return false;
    return true; 
}

int main() {
    string a,b,res;
    cin>>a>>b>>res;
    if(check(a,b,res) || check(b,a,res)){
        cout<<"YES"<<endl;
    }else{
        cout<<"No"<<endl;
    }
	return 0;
}
