#include <bits/stdc++.h>
using namespace std;

int kadane(int a[],int n)
{
    int max_so_far=0,max_ending=0;
    for(int i=0;i<n;i++)
     {
        max_ending+=a[i];
        if(max_ending<0)
         max_ending=0;
        if(max_so_far<max_ending)
         max_so_far=max_ending;
     }
    return max_so_far; 
}

void maxSubarray(int a[],int n)
{
    //int no_wrap=kadane(a,n);
    int sum=0;
    for(int i=0;i<n;i++)
     {
        sum+=a[i];
        a[i]=-a[i];
     }
    //(minsubarray=-maxsubarray) 
    int wrap=kadane(a,n);
    //total sum-(min subarray) 
    cout<<sum+wrap<<endl;
}

int main() {
	// your code goes here
	int a[] = { 11, 10, 20, 5, -3, -5, 8, -13, -10 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    maxSubarray(a,n);
	return 0;
}
