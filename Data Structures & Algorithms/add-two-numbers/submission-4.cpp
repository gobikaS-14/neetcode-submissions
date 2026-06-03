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

/*detailed version
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode*t1=head1;
        ListNode*t2=head2;
        int sum=t1->val+t2->val;
        int carry=sum / 10;//tens place
        int ans=sum % 10;//ones place
        ListNode*head3=new ListNode(ans);
        ListNode* prev=head3;

        t1=t1->next;
        t2=t2->next;

        while(t1!=NULL || t2!=NULL){
            //After some iterations, t2 becomes NULL first (because the second list is shorter).
            //But t2 is NULL, so accessing t2->val causes a segmentation fault.
            int val1 = (t1 != NULL) ? t1->val : 0;
            int val2 = (t2 != NULL) ? t2->val : 0;
            sum= val1+val2+carry;
            carry=sum / 10; //new carry
            ans=sum % 10;
            ListNode*t3= new ListNode(ans);
            prev->next=t3;
            prev=prev->next;
            
            if(t1 != NULL)
                t1 = t1->next;

            if(t2 != NULL)
                t2 = t2->next;
        }
        if(carry!=0){
            ListNode*t3= new ListNode(carry);
            prev->next=t3;
        }
        return head3;
    }
};
*/

//simplified one
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode*t1=head1;
        ListNode*t2=head2;

        ListNode* head3=new ListNode(0);
        ListNode* prev=head3;
        int carry=0;
        while(t1!=NULL || t2!=NULL || carry!=0) {//loop continues even if both lists are finished, as long as a carry exists.

            int val1 = (t1 != NULL) ? t1->val : 0;
            int val2 = (t2 != NULL) ? t2->val : 0;

            int sum= val1+val2+carry;
            carry=sum / 10; //new carry
            int ans=sum % 10;

            prev->next= new ListNode(ans);
            prev=prev->next;

            if(t1 != NULL)
                t1 = t1->next;
            if(t2 != NULL)
                t2 = t2->next;
            }
        return head3->next;
    }
};

