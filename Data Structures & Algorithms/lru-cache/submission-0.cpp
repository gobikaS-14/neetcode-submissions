// Node structure for doubly linked list
struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k,int v){
            key=k;
            val=v;
            prev=NULL;
            next=NULL;
        }
    };

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp; // key -> node(val)
    Node* head; // most recently used
    Node* tail; // least recently used

    void remove(Node* temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }

    void addtohead(Node * temp){
        temp->next=head->next;
        temp->prev=head;
        head->next->prev=temp;
        head->next=temp;
    }

public:
    LRUCache(int c) {//constructor
        capacity=c;
        head= new Node(0,0);// dummy head and tail
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* temp= mp[key];
            remove(temp);//most recently used -> move to head by removing from current pos
            addtohead(temp);
            return temp->val;
        }
        return -1;//not found
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){//if already exits ->update
            Node* temp= mp[key];
            temp->val=value;
            remove(temp);//most recently used -> move to head by removing from current pos
            addtohead(temp);
        }
        else{
            Node* temp=new Node(key,value);
            mp[key]=temp;
            addtohead(temp);//most recently used

            if(mp.size()>capacity){
                Node* lru = tail->prev; // least recently used
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
        }   
        
    }
};
