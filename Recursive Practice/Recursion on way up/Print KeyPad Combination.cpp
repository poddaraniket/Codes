// Level & Option Style

//Prerequiste -> get keypad comb & print subsequence

/*
eg -78
level 1 -> solve for 7  (In this level solve all options for 7)
level 2 -> solve for 8 (In this level solve all options for 7)

                      .|tv  .|tw .|tx  .|uv  .|uw .|ux   level 1 : solved all options of 8
                         \   |   /       \   |   /
                          \  |  /         \  |  /
                            8|t             8|u          level 1 : solved all options of 7 
                              \              /
                               \            /
                                \          /
                                    78|.
*/  


#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    // write your code here
    if(ques.length()==0){
        cout<<asf<<endl;
        return;
    }
    char c=ques[0];
    string rst=ques.substr(1);
    // fnd the index of the character to add
    int numberToAdd=c-'0'; 
    // add all char present in the index of the charcter
    for(char charToAdd : codes[numberToAdd]){
        printKPC(rst,asf+charToAdd);
    }
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}