/*
TC-> O(N)
E-> 1 will print itsefl and its family
F-> 10,11,12,13...19 will print itself and its family

F->E : if 10,11..19 will print itself and its family then we have printed 1 ka pura family it just needs to print itself


// print itself
// call its family



                             

                       10...19 20..29            (call its family)
                            \    |
                             1   2    3 ......9  (print itself)
*/












#include<bits/stdc++.h>

using namespace std;

void lexico(int n,string st){
    if(st.size()>0){
        //print itself
        if(stoi(st)<=n){
            cout<<st<<endl;
        }else{
            return;
        }
    }
    
    //call its family
    for(int i=0;i<=9;i++){
        if(i==0 && st.size()==0)
         continue;
        char ch=(char)i+48;
        st.push_back(ch);
        lexico(n,st);
        st.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    string s;
    lexico(n,s); 
}