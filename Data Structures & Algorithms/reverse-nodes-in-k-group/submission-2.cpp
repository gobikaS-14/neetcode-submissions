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

/*Brute force
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        //1.Copying ll to array
        vector<int> arr;
        ListNode* temp=head;
        while(temp!=NULL){
            
            arr.push_back(temp->val);
            temp=temp->next;
        }
        
        //2.Reversing the array
        int n=arr.size();
        for(int i=0;i+k<=n;i+=k){
            reverse(arr.begin()+i, arr.begin()+i+k);
        }

        //3.Copying arr back to new ll
        ListNode* res= new ListNode(0);
        ListNode*prev=res;
        int i=0;
        while(i<n){
            ListNode* temp=new ListNode(arr[i]);
            prev->next=temp;
            prev=temp;
            i++;
        }

        return res->next;
    }
};
*/

//optimal


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        ListNode dummy(0);
        dummy.next = head;
        ListNode* group_prev = &dummy;

        while (true) {
            // Step 1: Find kth node
            ListNode* kth = group_prev;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break;  // Less than k nodes left

            ListNode* group_next = kth->next;

            // Step 2: Reverse group
            ListNode* prev = group_next;
            ListNode* curr = group_prev->next;
            while (curr != group_next) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // Step 3: Connect reversed group
            ListNode*temp=group_prev->next;
            group_prev->next=kth;
            group_prev=temp;
            
        }

        return dummy.next;
    }
};

