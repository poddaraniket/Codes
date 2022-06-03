// Counts Palindromic Subsequence in a given String
#include<iostream>
#include<cstring>
using namespace std;
 
// Function return the total palindromic subsequence
int countPS(string str);
 
// Driver program
int main()
{
   int t;
	cin>>t;
   while(t--)
	{
	string str;
cin>>str;
cout<<countPS(str)<<endl;
} 
}// } Driver Code Ends


/*You are required to complete below method */
int countPS(string str)
{
   //Your code here
   int i,j,l;
   int n=str.length();
   int count[n][n];
   memset(count,0,sizeof(count));
   for(i=0;i<n;i++)
    count[i][i]=1;
   for(int l=2;l<=n;l++)
    {
        for(i=0;i<=n-l;i++)
         {
            j=i+l-1;
            if(str[i]==str[j])
             count[i][j]=count[i+1][j]+count[i][j-1]+1;
            else
             {
                count[i][j]=count[i+1][j]+count[i][j-1]-count[i+1][j-1]; 
             }
         }
    }
   return count[0][n-1];    
}
 