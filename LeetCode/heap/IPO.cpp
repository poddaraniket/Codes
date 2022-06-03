#include<bits/stdc++.h>
using namespace std;


priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> feasible;
priority_queue<int> Max_Profit;

// In feasible push all the capital,profit pair in increasing order of there capital i.e, lower capital will come first irrespective of there profit 
// In Max_Profit push only the profits of those capital which is less than the capital W that he has currently
// In W add the Max Profit (the top element of Max_Profit) for that kth project 


int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) 
{
    //O(logN)
    int N=Profits.size();
    for(int i=0;i<N;i++)
     {
        feasible.push({Capital[i],Profits[i]});
     }
    while(k--)
     {
        //O(2*NlogN) since it pops and push evenery element
        while(!feasible.empty() && feasible.top().first<=W)
         {
            Max_Profit.push(feasible.top().second);
            feasible.pop();
         }
        if(Max_Profit.empty())
          return W;
        W+=Max_Profit.top();
        Max_Profit.pop(); //O(klogN) as we are gonna pop max K elements
     }
    // O(logN + 2NlogN + klogN) => O(NlogN)
    return W;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> Profits,Capital;
        for(int i=0;i<n;i++)
         {
            int a;
            cin>>a;
            Profits.push_back(a);
         }
        for(int i=0;i<n;i++)
         {
            int a;
            cin>>a;
            Capital.push_back(a);
         } 
        int W,k;
        cin>>W>>k; 
        cout<<findMaximizedCapital(k,W,Profits,Capital)<<endl; 
    }
}

// Time Complexity  --> O(t*NlogN)