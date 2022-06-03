#include <iostream>
using namespace std;

int main() {
	//code
	int t;
    cin>>t;
    while(t--)
    {
        int a,b,n=1,cnt=0;
        cin>>a>>b;
        for(int i=0;i<32;i++)
         {
             if((a&n)!=(b&n))
              cnt++;
             n<<=1; 
         }
        cout<<cnt<<endl; 
    }
	return 0;
}