#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int minElements(int arr[],int n){
    sort(arr,arr+n,cmp);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int val=0,i=0;
    while(val<sum){
        val+=arr[i];
        sum-=arr[i];
        i++;
    }
    return i;
}

int main() {
    int arr[] = {3, 1, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minElements(arr, n) << endl;
    return 0;
}
