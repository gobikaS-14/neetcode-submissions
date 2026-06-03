/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head1) {
        if(head1==NULL) return NULL;
        unordered_map<Node*,Node*> mp;

        Node*head2=new Node(head1->val);
        mp[head1]=head2;
        Node*temp1=head1->next;
        Node* prev2=head2;

        while(temp1!=NULL){
            Node*temp2=new Node(temp1->val);
            prev2->next=temp2;

            mp[temp1]=temp2;

            prev2=prev2->next;
            temp1=temp1->next;
            
        }
        Node* t1=head1;
        Node* t2=head2;
        while(t1!=NULL){
            if(t1->random!=NULL){
                t2->random=mp[t1->random];
            }
            t1=t1->next;
            t2=t2->next;
            }
return head2;
    }
};
