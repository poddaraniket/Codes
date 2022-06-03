/*

        .|abc        .|acb        .|bac    .|bca    .|cab    .|cba
     (i=0)   \      (i=0) \   (i=0) \   (i=0)\    (i=0)\  (i=0)\
               c|ab        b|ac      c|ba     a|bc      b|ca    a|cb
                   \      /            \       /          \     /
        (i=0)       \    /  (i=1) (i=0) \     / (i=1) (i=0)\   /
                     bc|a                 ac|b              ab|c
                          \                |                /
                    (i=0)  \       (i=1)   |               /   (i=2)
                            \              |              /
                                 
                                        abc|.
*/




#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
    if(str.length()==0)
    {
        cout<<asf<<endl;
        return;
    }
    
    for(int i=0;i<str.length();i++){
        string left=str.substr(0,i);
        string right=str.substr(i+1);
        char chosen=str[i];
        printPermutations(left+right,asf+chosen);
    }
    
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}