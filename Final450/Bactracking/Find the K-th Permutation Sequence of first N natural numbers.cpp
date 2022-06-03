#include <bits/stdc++.h>
using namespace std;

string s;

int fact(int n){
    if(n==0)
     return 1;
    return n*fact(n-1); 
}

void permute(vector<int> arr,int &k){
    int n=arr.size();
    if(n==1){
      s+=arr[0]+'0';
      return;    
    }
    int val=fact(n-1);
    int index=k/val;
    if(k%val==0)
     index-=1;
    s+=arr[index]+'0';
    arr.erase(arr.begin()+index);
    k-=val*index;
    permute(arr,k);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++)
     arr.push_back(i+1);
    permute(arr,k); 
    cout<<s<<endl; 
}