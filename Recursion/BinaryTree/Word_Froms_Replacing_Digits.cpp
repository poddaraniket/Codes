#include <iostream>
using namespace std;

void recur(int digits[],int n,int i,string str)
{
    if(i==n)
     {
         cout<<str<<endl;
         return;
     }
    string sent="ABCDEFGHIJKLMNOPQRSTUVWXYZ";   // replace digits with character 0 means 'A' and 26 maens 'Z'.
    int sum=0; 
    for(int j=i;j<=min(i+1,n-1);j++)    // this loop hepl to form various combination of words
     {                                  // min(i+1,n-1) prevents combination of disgits gretaer than 2 digits as no. of alphabets are less than 27
         sum=(sum*10)+digits[j];
         if(sum<=26)
          recur(digits,n,j+1,str+sent[sum-1]);
     }
}

int main() {
	// your code goes here
	int digits[]={1,2,2};
	recur(digits,3,0,"");
	return 0;
}
