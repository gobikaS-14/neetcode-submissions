/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;

        for(int i=0;i<n;i++){//move fast n times
            fast=fast->next;
        }
        if(fast == NULL){//only if deletion of head node(n=full length)
            return head->next;
        }

        while(fast->next!=NULL){// move fast and slow 1 step simultaneously until fast reaches end of ll
            slow=slow->next;
            fast=fast->next;
        }
        // slow must be at a node before the delete node
        slow->next=slow->next->next;
        return head;
        
    }
};
