#include <bits/stdc++.h>
using namespace std;
  
int minSwaps(int arr[],int n){
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
     v[i]={arr[i],i};
    int c=0; 
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
     {
         if(v[i].second==i)
          {
            continue;  
          }
         swap(v[i],v[v[i].second]);
         c++;
         i--;  // Rechecking if the swapped element is in its correct place or not
     }
    return c; 
}  
  
int main(){
    int arr[] = {1, 5, 4, 3, 2};
    int n = (sizeof(arr) / sizeof(int));
    cout << minSwaps(arr, n);
    return 0;
}