#include <iostream>
using namespace std;

void combination(int arr[],int n,string ans,int k,int i)
{
    if(k>n)
     return;
    if(k==0)
     {
      cout<<ans<<endl;
      return;
     }
    for(int j=i;j<n;j++)
     {
        combination(arr,n,ans+" "+to_string(arr[j]),k-1,j+1); 
     }
}

int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	 {
	     cin>>a[i];
	 }
    combination(a,n,"",k,0); 
// 	for(int i=0;i<n;i++)
// 	 cout<<a[i]<<" ";
	cout<<endl; 
	return 0;
}
