class Trie{
   public: 
    char c;
    string word;
    Trie* child[26];
    int ends;
    Trie(char c){
        this->c=c;
        this->word="";
        this->ends=0;
        for(int i=0;i<26;i++){
            this->child[i]=NULL;
        }
    }
    
    void insert(string w){
        Trie* curr=this;
        for(int i=0;i<w.length();i++){
            int index=w[i]-'a';
            if(curr->child[index]==NULL){
                // cout<<w[i]<<" ";
                curr->child[index]=new Trie(w[i]);
            }
            curr=curr->child[index];
        }
        curr->ends+=1;
        curr->word=w;
    }
    
    bool search(string w){
        Trie* curr=this;
        for(int i=0;i<w.length();i++){
            int index=w[i]-'a';
            if(curr->child[index]==NULL){
                // cout<<w[i]<<endl;
               return false;
            }
            curr=curr->child[index];
        }
        return true;
    }
};

class Solution {
public:
    
    static bool cmp(string a,string b){
        return a.length()>b.length();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        Trie* root=new Trie('#');
        int ans=0;
        for(int i=0;i<words.size();i++){
            cout<<words[i]<<endl;
            string w=words[i];
            reverse(w.begin(),w.end());
            if(!(root->search(w))){
                // cout<<w<<endl;
                ans+=(w.length())+1;
                root->insert(w);
                // cout<<endl;
            }
        }
        return ans;
    }
};