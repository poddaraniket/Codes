#include <bits/stdc++.h>
using namespace std;

int bit[100000];

int getSum(int i)
{
    int sum=0;
    int index=i+1;
    while(index!=0)
     {
       sum+=bit[index];    
       index-=index&(-index); //O(1) time bt takes O(n) space
     }
    return sum;
}

void Update(int i,int val,int size)
{
   int index=i+1;    
   while(index<=size)
    {
        bit[index]+=val;
        index+=index&(-index);
        //Update(index,val,size);
    }
   return;    
}

void Create(int freq[],int n)
{
    for(int i=0;i<n;i++)
     {
        Update(i,freq[i],n+1);
     }
}

int main() {
	// your code goes here
	int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	int n=sizeof(freq)/sizeof(freq[0]);
	bit[n+1]={0};
	Create(freq,n);
	cout<<getSum(5)<<endl;
	
	// update and sum 
// 	freq[3]+=6;
// 	Update(3,6,n+1);
// 	cout<<getSum(5)<<endl;
	
	cout<<getSum(7)-getSum(5)<<endl;
	return 0;
}
