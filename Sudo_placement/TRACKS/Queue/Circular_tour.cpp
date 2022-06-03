#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends


/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   //Your code here
   int start=0,capacity=0,deficiency=0;
   for(int i=0;i<n;i++)
    {
        capacity+=p[i].petrol-p[i].distance;
        if(capacity<0)
         {
            start=i+1;
            deficiency+=capacity;
            capacity=0;
         }
    }
    if(capacity+deficiency>=0)
     return start;
    return -1; 
}

