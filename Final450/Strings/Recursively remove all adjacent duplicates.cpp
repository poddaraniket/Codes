#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string temp="";
    int i=0;
    while(i<s.length()){
        if(temp.length()==0) {
            temp+=s[i];
            i++;
        }
        else if(s[i]==temp.back()){
            while(s[i]==temp.back())
            {
                i++;
            }
            temp.pop_back();
        }
        else{
            temp+=s[i];
            i++;
        }
    }
    cout<<temp<<endl;;
}