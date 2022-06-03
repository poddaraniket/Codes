// it is like binary tree just that in binary tree we have two childrens here we have n childs
//there instead of taking right and eft we tok child[n] showing that we have n child

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    char data;
    TrieNode *child[26];
    bool isLeaf;
    TrieNode(char data)
     {
        this->data=data; 
        for(int i=0;i<26;i++)
         this->child[i]=NULL;
     }
};

void insert(TrieNode *root,string sent)
{
    int index;
    TrieNode *temp=root;
    for(int i=0;i<sent.length();i++)
     {
        index=sent[i]-'a'; 
        if(temp->child[index]==NULL)
         temp->child[index]=new TrieNode(sent[i]);
        temp=temp->child[index]; 
     }
    temp->isLeaf=true; 
}

bool search(TrieNode *root,string sent)
{
    TrieNode *temp=root;
    for(int i=0;i<sent.length();i++)
     {
        int index=sent[i]-'a'; 
        if(temp->child[index]==NULL)
         return false;
        temp=temp->child[index]; 
     }
    return (temp!=NULL && temp->isLeaf); 
}

//if that word exist its "isLeaf" will be true just simiply make it false to deny the presence of such word

void del(TrieNode *root,string sent)
{
    TrieNode *temp=root;
    for(int i=0;i<sent.length();i++)
     {
        int index=sent[i]-'a'; 
        if(temp->child[index]==NULL)
         break;
        temp=temp->child[index]; 
     }
    if(temp!=NULL && temp->isLeaf)
     temp->isLeaf=false;
}

int main() {
	// your code goes here
	string keys[] = {"the", "a", "there","answer", "any", "by","bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]);
    TrieNode *root=new TrieNode('/0');
    for(int i=0;i<n;i++)
     {
        insert(root,keys[i]); 
     }
    cout<<search(root,"the")<<endl;
    del(root,"the");
    cout<<search(root,"the")<<endl;
    cout<<search(root,"a")<<endl;
    del(root,"a");
    cout<<search(root,"a")<<endl;
	return 0;
}
