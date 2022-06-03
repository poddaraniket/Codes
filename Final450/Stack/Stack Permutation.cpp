#include <bits/stdc++.h>
using namespace std;

bool checkStackPermutation(int input[],int output[],int n){
    queue<int> ip,op;
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        ip.push(input[i]);
    }
    int p=0;
    while(!ip.empty()){
        int t=ip.front();
        ip.pop();
        if(t!=output[p])
        {
           st.push(t); 
        }
        else{
            if(t==output[p])
            {
                p++;
               while(!st.empty()){
                   if(st.top()==output[p])
                    {
                        p++;  
                        st.pop();
                    }
                   else
                    break;
               } 
            }
        }
    }
    if(ip.empty() && st.empty())
     return true;
    return false; 
}

int main() {
     int input[] = {1, 2, 3};
  
    // Output Queue
    int output[] = {3,1,2};
  
    int n = 3;
  
    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
	return 0;
}
