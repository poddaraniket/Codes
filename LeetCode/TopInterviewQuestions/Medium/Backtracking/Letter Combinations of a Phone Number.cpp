class Solution {
public:
    string s[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void possible(string digits,vector<string> &v,string &word,int index){
        if(index==digits.length()){
            v.push_back(word);
            return;
        }
        int k=digits[index]-'2';
        string temp=s[k];
        for(int i=0;i<temp.length();i++){
            //do
            word.push_back(temp[i]);
            //recur
            possible(digits,v,word,index+1);
            //undo
            word.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if(digits.length()==0)
            return v;
        string word;
        possible(digits,v,word,0);
        return v;
    }
};