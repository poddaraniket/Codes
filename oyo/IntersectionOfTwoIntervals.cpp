#include <bits/stdc++.h>
using namespace std;

void printIntervals(vector<vector<int> > arr1,vector<vector<int> > arr2)
{
    int i=0,j=0;
    int n=arr1.size();
    int m=arr2.size();
    while(i<n && j<m)
    {
      int l=max(arr1[i][0],arr2[j][0]);
      int r=min(arr1[i][1],arr2[j][1]);
      if(l<=r)
       cout<<l<<" "<<r<<endl;
      if(arr1[i][1]<arr2[j][1])
       i++;
      else
       j++;
    }
}

int main() {
	// your code goes here
	vector<vector<int> > arr1 = { { 0, 4 }, { 5, 10 }, { 13, 20 }, { 24, 25 } }; 
  
    vector<vector<int> > arr2 = { { 1, 5 }, { 8, 12 }, { 15, 24 }, { 25, 26 } }; 
  
    printIntervals(arr1, arr2); 
	return 0;
}
