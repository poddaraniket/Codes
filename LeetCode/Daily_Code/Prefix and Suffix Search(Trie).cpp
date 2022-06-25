/*
Insert and search costs O(key_length), however, the memory requirements of Trie is O(ALPHABET_SIZE * key_length * N) where N is the number of keys in Trie


*/


class Trie{
  public:  
    Trie* child[26];
    vector<int> indexes;
    Trie(){
        this->indexes=vector<int>();
        for(int i=0;i<26;i++){
            this->child[i]=NULL;
        }
    }
    void insert(string word,int idx){
        Trie* root=this;
        for(int i=0;i<word.length();i++){
            int index=word[i]-'a';
            if(root->child[index]==NULL){
                root->child[index]=new Trie();
            }
            root->child[index]->indexes.push_back(idx);
            root=root->child[index];
        }
    }
    
    vector<int> startsWith(string word){
        Trie* root=this;
        vector<int> v;
        for(int i=0;i<word.length();i++){
            int index=word[i]-'a';
            if(root->child[index]==NULL)
                return v;
            root=root->child[index];
        }
        return root->indexes;
    }
};

class WordFilter {
public:
    Trie* pre;
    Trie* suf;
    map<string,int> check;
    WordFilter(vector<string>& words) {
        pre=new Trie();
        suf=new Trie();
        for(int i=0;i<words.size();i++){
            pre->insert(words[i],i);
            reverse(words[i].begin(),words[i].end());
            suf->insert(words[i],i);
        }
    }
    
    int f(string prefix, string suffix) {
        map<int,int> mp;
        string s=prefix+'#'+suffix;
        if(check.find(s)!=check.end()){
            return check[s];
        }
        vector<int> pr=pre->startsWith(prefix);
        reverse(suffix.begin(),suffix.end());
        vector<int> sf=suf->startsWith(suffix);
        int l1=pr.size()-1, l2=sf.size()-1;
        while(l1>=0 && l2>=0){
            if(pr[l1]==sf[l2]){
                check[s]=pr[l1];
                return pr[l1];
            }else if(pr[l1]>sf[l2]){
                l1--;
            }else{
                l2--;
            }
        }
        check[s]=-1;
        return -1;
    }
};