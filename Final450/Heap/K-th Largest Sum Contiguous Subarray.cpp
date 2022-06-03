#include <bits/stdc++.h>
using namespace std;

int kthLargestSum(int a[],int n,int k){
    int sum[n+1];
    sum[0]=0;
    sum[1]=a[0];
    for(int i=2;i<=n;i++)
     {
        sum[i]=a[i]+sum[i-1];
     }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
         {
            int diff=sum[j]-sum[i];
            if(pq.size()<k)
             {
                pq.push(diff); 
             }
            else{
                if(pq.top()<diff)
                 {
                    pq.pop();
                    pq.push(diff);
                 }
            } 
         }
    }
    return pq.top();
}

int main() {
    int a[] = { 10, -10, 20, -40 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 6;
 
    // calls the function to find out the
    // k-th largest sum
    cout << kthLargestSum(a, n, k);
	return 0;
}
