#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;
	
	Node(char x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

struct Node* insert(struct Node* root,char data)
{
    if(root==NULL){
        root= new Node(data);
        return root;
    }

    else if(root->data<data)
    root->right=insert(root->right,data);

    else if(root->data>data)
    root->left=insert(root->left,data);

  return root;
}







struct Node* insertString(struct Node* root,string s, int *j)
{

    if((*j)>=s.length())
    return NULL;

	          if(s[*j]=='(')
	          (*j)++;


	         if(s[*j]!='('&&s[*j]!=')'){
	             
	             char n=0;
	             n = s[*j];
             (*j)++;

	          root=insert(root,n);

	          //cout<<"root->data="<<root->data<<endl;

	         // (*j)++;

	          if(s[*j]==')'){
                root->left=NULL;
              root->right=NULL;
              //cout<<"root->data="<<root->data<<endl;
              //cout<<"root->left=NULL\n";
              //cout<<"root->right=NULL\n";
              return root;
	          }

	         }

             if(s[*j]=='(')
	          (*j)++;

	          if(s[*j]==')'){
	            //  cout<<"root->data="<<root->data<<endl;
              //cout<<"root->left=NULL\n";
	          root->left=NULL;
	          }
              else{
                //    cout<<"root->left->parent->data="<<root->data<<endl;
	          root->left=insertString(root->left,s,j);
              }

//cout<<"right\n";

              while(s[*j]==')')
	          (*j)++;

	          if(s[*j]=='(')
	          (*j)++;

	          if(s[*j]==')'){
      //        cout<<"root->data="<<root->data<<endl;
        //      cout<<"root->right=NULL\n";
	          root->right=NULL;
	          (*j)++;
	          }
	          else{
          //    cout<<"root->right->parent->data"<<root->data<<endl;
              root->right=insertString(root->right,s,j);
	          }
return root;
}

void print(struct Node* root)
{

    if(root==NULL)
        return;


    print (root->left);
    cout<<root->data<<endl;
    print(root->right);

}
bool dupSub(Node *root);

int main() {
	//code
	int i,j,k,T ,level;
	char s[500];

	   cin>>T;

	   for(i=0;i<T;i++)
	   {
	     // cin>>level;

	      cin>>s;

	      int j=0;

	      struct Node* root=NULL;

	      root=insertString(root,s,&j);
	   
        cout<<dupSub(root)<<endl;

	  

	   }




	return 0;
}

// } Driver Code Ends


/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/

bool match(Node *t,Node *t1)
{
    if(t==NULL && t1==NULL)
     return true;
    if(t==NULL || t1==NULL) 
     return false;
    if((t->data==t1->data) && match(t->left,t1->left) && match(t->right,t1->right)) 
     return true;
}

bool dupSub(Node *root)
{
     // map will store the data and the add of node so that if we get any same data we can send that region for comparison
     map<char,Node*> mp;
     queue<Node*> q;
     q.push(root);
     while(!q.empty())
     {
         Node *temp=q.front();
         q.pop();
         if(mp.find(temp->data)!=mp.end())
          {
             Node *temp1=mp[temp->data]; 
             if(!((!(temp1->right) && !(temp1->left)) || (!(temp->right) && !(temp->left))))
             {
               if(match(temp1,temp))
                return true;
             }
          }
         else
          {
            mp[temp->data]=temp;  
          }
         if(temp->left!=NULL)
          {
            q.push(temp->left);  
          }
         if(temp->right!=NULL)
          {
            q.push(temp->right);  
          }
     }
    return false; 
}