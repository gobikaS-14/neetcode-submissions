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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

        ListNode*head3=new ListNode(0);
        ListNode *temp=head3;

        ListNode* t1=head1;
        ListNode* t2=head2;
        while(t1!=NULL && t2!=NULL){
            if(t1->val < t2->val){
                temp->next=t1;
                t1=t1->next;
            }
            else{
                temp->next=t2;
                t2=t2->next;
            }
            temp=temp->next;
        }
        if(t1==NULL)    temp->next=t2;
        if(t2==NULL)    temp->next=t1;
        return head3->next;
    }
};
