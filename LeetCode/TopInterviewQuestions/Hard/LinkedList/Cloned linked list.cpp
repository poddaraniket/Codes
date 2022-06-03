//O(N)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        // copied the new pointers in the list itself
        Node *temp=head;
        while(temp!=NULL){
            Node *newNode=new Node(temp->val);
            Node *later=temp->next;
            temp->next=newNode;
            newNode->next=later;
            temp=later;
        }
        // set the arb pointers
        temp=head;
        while(temp!=NULL){
            if(temp->next){
              temp->next->random=(temp->random!=NULL)?temp->random->next : temp->random;  
            }
            temp=(temp->next) ? temp->next->next : temp->next;
        }
        
        //detatch the lists to get the cloned one and the original one
        Node *original=head;
        Node *cloned=head->next;
        Node *ans=cloned;
        while(original && cloned){
            original->next = (original->next) ? original->next->next : original->next;
            cloned->next = (cloned->next) ? cloned->next->next : cloned->next;
            original=original->next;
            cloned=cloned->next;
        }
        return ans;
    }
};