#include <bits/stdc++.h>
using namespace std;

#define MIN -100000

//int segTree[MAX];

//find Max value in the given range

int findMaxQuery(int segTree[],int qlow,int qhigh,int low,int high,int pos)
{
    //cout<<"*"<<endl;
    if(qlow<=low && qhigh>=high)
     return segTree[pos];
    if(qlow>high || qhigh<low)
     return MIN;
    int mid=(low+high)/2; 
    return max(findMaxQuery(segTree,qlow,qhigh,low,mid,2*pos+1),findMaxQuery(segTree,qlow,qhigh,mid+1,high,2*pos+2)); 
}


//Create Segment Tree for Max Query Range
void CreateTree(int inp[],int segTree[],int low,int high,int pos)
{
    if(low==high)
     {
        //cout<<pos<<endl;  
        segTree[pos]=inp[low]; 
        return;
     }
    int mid=(low+high)/2;
    CreateTree(inp,segTree,low,mid,2*pos+1);
    CreateTree(inp,segTree,mid+1,high,2*pos+2);
    segTree[pos]=max(segTree[2*pos+1],segTree[2*pos+2]);
}

int main() {
	// your code goes here
	int arr[] = {1, 3, 2, 7, 9, 11};  
    int n = sizeof(arr)/sizeof(arr[0]); 
    int size;
    if(ceil(log2(n))==floor(log2(n)))
     {
        size=2*n-1; 
     }
    else 
     {
        size=2*pow(2,ceil(log2(n)))-1; 
     }
    int segTree[size];
    memset(segTree,MIN,sizeof(segTree));
    CreateTree(arr,segTree,0,n-1,0);
    
    cout<<findMaxQuery(segTree,2,4,0,n-1,0)<<endl;
	return 0;
}
