//O(n*l) where n = number of words inserted in Trie and l = length of longest word inserted in Trie

#include<bits/stdc++.h>

using namespace std;


struct node{
    char c;
    int pc;
    node *child[26];
};

struct node *getNode(char s)
{
    node *newNode=new node;
    newNode->c=s;
    newNode->pc=0;
    for(int i=0;i<26;i++)
     newNode->child[i]=NULL;
    return newNode; 
}

node *root=getNode('/');

void insert(string s){
    node *curr=root;
    int i=0,index;
    while(s[i])
     {
        index=s[i]-'a';
        if(curr->child[index]==NULL)
         {
            curr->child[index]=getNode(s[i]); 
         }
        curr->pc+=1;
        curr=curr->child[index];
        i++;
     }
    curr->pc+=1; 
}

int countWords(vector<string> words,string pf)
{
    for(int i=0;i<words.size();i++)
     {
         insert(words[i]);
     }
    int i=0,index; 
    node *curr=root;
    while(pf[i])
    {
        index=pf[i]-'a';
        if(curr->child[index]!=NULL)
         curr=curr->child[index];
        else
         return 0;
        i++; 
    }
    return curr->pc;
}

int main()
{
    // input list of words
    vector<string> words;
    words = { "apk", "app", "apple",
              "arp", "array" };
 
    // Given prefix to find
    string prefix = "ar";
 
    // Print the number of words with
    // given prefix
    cout << countWords(words, prefix);
    return 0;
}