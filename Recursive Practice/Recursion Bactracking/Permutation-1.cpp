/*                     
when you return from here since the array is being used its refernace based therefore while coming dow the dat will reamin 12300
so we need to remove from there to add it else where 
                  12300  
                       \
                        \      
                         12000
                              \
                               \
                                10000
                                     \
                                      \           
                                        00000
*/




#include<bits/stdc++.h>

using namespace std;

void display(vector<int> boxes){
    for(int i=0;i<boxes.size();i++){
        cout<<boxes[i];
    }
    cout<<endl; 
}

void permutations(vector<int> boxes, int ci, int ti){
    // write your code here 
    if(ci>ti){
        display(boxes);
        return;
    }
    
    for(int i=0;i<boxes.size();i++){
        if(boxes[i]==0){
            boxes[i]=ci;
            permutations(boxes, ci+1, ti);
            boxes[i]=0;
        }
    }
}


int main(){
    int nboxes,ritems;
    cin>>nboxes>>ritems;
    vector<int> boxes(nboxes,0);
    permutations(boxes, 1, ritems);
}