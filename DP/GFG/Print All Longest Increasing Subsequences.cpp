// 10 22 9 33 21 50 41 60 80 1
//  1  2 1 3  2  4  4  5   6  1

#include<bits/stdc++.h>

using namespace std;

struct Pair {
        
        int l;
        int i;
        int v;
        string psf;
        
        Pair(int l, int i, int v, string psf){
            this->l = l;
            this->i = i;
            this->v = v;
            this->psf = psf;
        }
    };

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
     {
        cin>>arr[i]; 
     }
    vector<int> LIS(n,1);
    int maxi=0,maxL=-1;
    for(int i=1;i<n;i++)
     {
        for(int j=0;j<i;j++)
         {
            if(arr[i]>=arr[j])
             {
                LIS[i]=max(LIS[j]+1,LIS[i]); 
                if(maxi<LIS[i])
                 {
                    maxi=LIS[i];
                    maxL=i;
                 }
             }
         }
     }
    queue<Pair*> q;
    q.push(new Pair(maxi,maxL,arr[maxL],to_string(arr[maxL])));
    
    while(!q.empty())
    {
        Pair* p=q.front();
        q.pop();
        if(p->l==1)
         cout<<p->psf<<endl;
        int start=p->i; 
        int val=p->l-1;
        for(int i=start-1;i>=0;i--)
         {
            if(LIS[i]==val && arr[i]<=p->v)
             {
                q.push(new Pair(val,i,arr[i],to_string(arr[i])+"->"+p->psf)); 
             }
         }
    }
}