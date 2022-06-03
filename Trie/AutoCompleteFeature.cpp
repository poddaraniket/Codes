//O(No. of words * Max word length)=insertion time

#include<bits/stdc++.h>

using namespace std;


struct node{
    char c;
    int ends;
    string word;
    node *child[26];
};

struct node *getNode(char s)
{
    node *newNode=new node;
    newNode->c=s;
    newNode->ends=0;
    newNode->word="";
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
        curr=curr->child[index];
        i++;
     }
    curr->ends+=1;
    curr->word=s;
}

void print(node *root)
{
    if(root->ends>0){
     cout<<root->word<<endl;
     root->ends-=1;
    }
    for(int i=0;i<26;i++)
     {
        if(root->child[i]!=NULL)
         print(root->child[i]);
     }
}

int printAutoSuggestions(node *root,string pf)
{
    node *curr=root;
    int index,i=0;
    while(pf[i])
     {
        index=pf[i]-'a';
        if(curr->child[index]!=NULL)
         curr=curr->child[index];
        i++; 
     }
    bool none=false; 
    for(int i=0;i<26;i++)
     {
        if(curr->child[index]!=NULL)
         none=true;
     }
    print(curr); 
    return none==true?-1:0; 
}

int main()
{
    // input list of words
    insert("hello"); 
	insert("dog"); 
	insert( "hell"); 
	insert( "cat"); 
	insert( "a"); 
	insert( "hel"); 
	insert( "help"); 
	insert( "helps"); 
	insert( "helping");
 
    // Given prefix to find
    string prefix = "hel";
 
    int comp = printAutoSuggestions(root, "hel"); 

	if (comp == -1) 
		cout << "No other strings found with this prefix\n"; 

	else if (comp == 0) 
		cout << "No string found with this prefix\n"; 
    return 0;
}