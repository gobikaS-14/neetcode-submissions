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
    void reorderList(ListNode* head) {

        //Step1-Find MID
        ListNode* slow= head;
        ListNode* fast= head;
        //odd && even
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next; //1 step
            fast=fast->next->next; // 2 steps
        } //slow=mid    

        //Step2-Reverse the second half
        ListNode* prev= NULL;
        ListNode* nextnode= NULL;
        ListNode* curr= slow->next;

        while(curr!=NULL){
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }

        //Step3- Merge Alternatively
        ListNode* first= head;
        ListNode* second= prev;
        slow->next=NULL;// cut into 2 LL

        while(second!=NULL){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;

            first->next=second;
            second->next=temp1;
            
            first=temp1;
            second=temp2;
        }

       
    }
};