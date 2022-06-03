#include <iostream>
using namespace std;

int findProduct(int arr[],int n,int left,int index)
{
    if(index==n)
     return 1;
    int curr=arr[index]; 
    int right=findProduct(arr,n,left*arr[index],index+1);
    cout<<right<<" ";
    arr[index]=left*right;
    cout<<arr[index]<<" ";
    cout<<curr<<endl;
    return curr*right;
}


int main() {
	// your code goes here
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	 {
	     cin>>a[i];
	 }
	findProduct(a,n,1,0); 
// 	for(int i=0;i<n;i++)
// 	 cout<<a[i]<<" ";
	cout<<endl; 
	return 0;
}
