//Initial Template for C++
 
#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265359
 
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        float ans,side;
        cin>>n;
        side=(1/(sin(pi/(2*n))));   //finds the side before rotation that will become the hypotenuse
        //side*=2;
        //float teta_rotate=(360.0/(4*n));
        //float radian_rotate=teta_rotate*(pi/(4*n));
        cout<<fixed<<setprecision(9)<<side*cos(pi/(4*n))<<endl;   // the cos angle is the degree by which u rotated the polygon to fix it in the min size square 
                                                                  //possible cos of the side will give me the length of sqaure
    }
}  // } Driver Code Ends