#include <bits/stdc++.h>
using namespace std;

int Transform(string s1,string s2){
    int a=s1.length()-1,b=s2.length()-1;
    if(a!=b)
     return -1;
    int countA[256]={0};
    int countB[256]={0};
    for(int i=0;i<s1.length();i++){
        countA[s1[i]]++;
    }
    for(int i=0;i<s2.length();i++){
        countB[s1[i]]++;
    }
    for(int i=0;i<256;i++){
        if(countA[i]!=countB[i])
          return -1;
    }
    int count=0;
    while(b){
        if(s1[a]==s2[b]){
            a--;
            b--;
        }
        else{
            count++;
            s1=s1[a]+s1.substr(0,a)+s1.substr(a+1);
        }
    }
    return count;
}

int main() {
    string S1,s2;
    cin>>s1>>s2;
    Transform(s1,s2);
	return 0;
}
