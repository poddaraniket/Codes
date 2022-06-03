#include <bits/stdc++.h>
using namespace std;

#define MAX_COUNT 10000

bool divisible(string s,int n)
 {
    if(stoi(s)%n==0)
     return true;
    return false; 
 }

string findSmallestMultiple(int n)
{
    queue<string> q;
    q.push("9");
    for(int i=MAX_COUNT;i>=0;i--)
     {
        string s1=q.front();
        q.pop();
        if(divisible(s1,n))
         return s1;
        string s2=s1;
        s1+='0';
        q.push(s1);
        s2+='9';
        q.push(s2);
     }
}

int main()
{
    int n = 7;   
    cout << findSmallestMultiple(n);   
    return 0;
}
