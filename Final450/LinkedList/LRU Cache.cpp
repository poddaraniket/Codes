#include <bits/stdc++.h>
using namespace std;
 
class LRUCache{
     
    public:
    class node
    {
        public:
        int key;
        int value;
        node * prev;
        node * next;
         
        node(int _key,int _value)
        {
            key = _key;
            value = _value;
        }
    };
     
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    map<int, node *> m;
     
    // Constructor for initializing the
    // cache capacity with the given value.
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
     
    // add always in front 
    void addnode(node * temp)
    {
        node *dummy=head->next;
        head->next=temp;
        temp->prev=head;
        temp->next=dummy;
        dummy->prev=temp;
    }
     
    void deletenode(node * temp)
    {
       node *dummyprev=temp->prev;
       node *dummynxt=temp->next;
       dummyprev->next=dummynxt;
       dummynxt->prev=dummyprev;
       //free(temp);
    }
     
    // This method works in O(1)
    int get(int key)
    {
       // Key Present    
       if(m.find(key)!=m.end())
        {
            node * temp=m[key];
            //m.erase(key);
            int val=temp->value;
            deletenode(temp);
            addnode(temp);
           // m[key]=head->next;
             cout << "Got the value : " << val
                << " for the key: " << key << "\n";
            return val;
        }
        cout << "Did not get any value for the key: "
             << key << "\n";
       return -1;
    }
     
    // This method works in O(1)
    void set(int key, int value)
    {
         cout << "Going to set the (key, value) : ("
             << key << ", " << value << ")" << "\n";
        if(m.find(key)!=m.end())
         {
            node *temp=m[key];
            m.erase(temp->key);
            deletenode(temp);
            temp->value=value;
         }
        if(m.size()==cap)
         {
            node *temp=tail->prev;
            m.erase(temp->key);
            deletenode(temp);
         }
        node* newNode = new node(key, value);
        addnode(newNode);
        m[key]=head->next;
    }
};

int main()
{
    cout << "Going to test the LRU  "
         << "Cache Implementation\n";
          
    LRUCache * cache = new LRUCache(2);
 
    // It will store a key (1) with value
    // 10 in the cache.
    cache->set(1, 10);
 
    // It will store a key (1) with value 10 in the
    // cache.
    cache->set(2, 20);
    cout << "Value for the key: 1 is "
         << cache->get(1) << "\n"; // returns 10
 
    // Evicts key 2 and store a key (3) with
    // value 30 in the cache.
    cache->set(3, 30);
 
    cout << "Value for the key: 2 is "
         << cache->get(2) << "\n"; // returns -1 (not found)
 
    // Evicts key 1 and store a key (4) with
    // value 40 in the cache.
    cache->set(4, 40);
    cout << "Value for the key: 1 is "
         << cache->get(1) << "\n"; // returns -1 (not found)
    cout << "Value for the key: 3 is "
         << cache->get(3) << "\n"; // returns 30
    cout << "Value for the key: 4 is "
         << cache->get(4) << "\n"; // return 40
 
    return 0;
}
 