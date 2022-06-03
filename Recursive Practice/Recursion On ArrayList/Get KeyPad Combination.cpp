//TC->O(N)

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string words[10]={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

vector<string> getKPC(string s) {
  //Write your code here
  if(s.length()==0){
    vector<string> v;
    v.push_back("");
    return v;
  }
  char c=s[0];              // "7"
  string rst=s.substr(1);   // "8"
  vector<string> rres=getKPC(rst);
  vector<string> myArr;
  // fnd the index of the character to add
  int numberToAdd=c-'0'; 
  // add all char present in the index of the charcter
  for(char charToAdd : words[numberToAdd]){ 
      // we add it to the allready present combination of strings in list, no new is created all will be added
      for(string str : rres){
          string newStr=charToAdd+str;
          myArr.push_back(newStr);
      }
  }
  return myArr;
}


int main() {
  string s;
  cin >> s;
  vector<string> ans = getKPC(s);
  int cnt = 0;

  cout << '[';
  for (string str : ans) {
    if (cnt != ans.size() - 1)
      cout << str << ", ";
    else
      cout << str;
    cnt++;
  }
  cout << ']';
}