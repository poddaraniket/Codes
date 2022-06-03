#include<bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar) {
  //to avoid run time error
  if(sos>tar)
    return;
  if(idx==arr.size()){
     // this has to be inside to meet condition like 2,6,0
     if(sos==tar){
       cout<<set<<"."<<endl;
     }
    return; 
   }
    printTargetSumSubsets(arr,idx+1,set+to_string(arr[idx])+", ",arr[idx]+sos,tar);
    printTargetSumSubsets(arr,idx+1,set,sos,tar);
}


int main() {
    int n,tar;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i]=a;
    }
    cin>>tar;
    printTargetSumSubsets(arr,0,"",0,tar);
    return 0;
}