//O(N)  // <O(N) space

#include <bits/stdc++.h>
using namespace std;

int findRepeatingNumber(int arr[],int n)
{
    //define the size of blocks
    int sq=sqrt(n);
    
    // define the number of blocks
    int nums= (n/sq) + 1;
    
    int blocks[nums]={0};
    
    // divide the numbers in these blocks
    for(int i=0;i<=n;i++)
     {
        blocks[(arr[i]-1)/sq]++; 
     }
     
    // find the blocks whose count is greater then sq bcoz that block will have the duplicate value
    int selected=nums-1;
    for(int i=0;i<nums-1;i++)
     {
         if(blocks[i]>sq){
          selected=i;     
          break;
         }
     }
     
    // then using ma we can get the duplicate value 
    unordered_map<int,int> mp;
    for(int i=0;i<=n;i++)
    {
        if((selected*sq)<arr[i] && arr[i]<=((selected+1) *sq)){
          mp[arr[i]]++;
          if(mp[arr[i]]>1)
             return arr[i];
        }
    }
    return -1;
}


int main() {
	// your code goes here
	int arr[] = { 1, 1, 2, 3, 5, 4 };
 
    // array of size 6(n + 1) having
    // elements between 1 and 5
    int n = 5;
 
    cout << "One of the numbers repeated in"
         " the array is: "
         << findRepeatingNumber(arr, n) << endl;
	return 0;
}
