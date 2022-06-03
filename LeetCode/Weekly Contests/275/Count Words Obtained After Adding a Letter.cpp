class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> searchSet;
        for(int i=0;i<startWords.size();i++){
            sort(startWords[i].begin(),startWords[i].end());
            searchSet.insert(startWords[i]);
        }
        int count=0;
        for(int i=0;i<targetWords.size();i++){
            string word=targetWords[i];
            sort(word.begin(),word.end());
            bool flag=false;
            for(int k=0;k<word.length();k++){
                string left=(k==0) ? "" : word.substr(0,k);
                string right=(k==word.length()-1) ? "":word.substr(k+1);
                string newWord=left+right;
                if(searchSet.find(newWord)!=searchSet.end()){
                    flag=true;
                    break;
                }
            }
           if(flag)
               count++;
        }
       return count; 
    }
};