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
       
       ListNode *dummy= new ListNode(0);
       dummy->next=head;
       ListNode* grp_prev=dummy;

       while(true){
            //find the last address of the first k node(get limit to reverse)
            ListNode* kth =grp_prev;
            for(int i=0;i<k && kth!=NULL;i++){
                kth=kth->next;
            }
            if(kth==NULL) break;//less than k nodes keep as it is (no reversal)

            //reverse of k group of elements
            ListNode* grp_next=kth->next;
            ListNode* prev=grp_next;
            ListNode* curr=grp_prev->next;
            while(curr!=grp_next){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            //1.move dummy to point to new head after reversal
            ListNode* tmp= grp_prev->next;
            grp_prev->next=kth;
            grp_prev=tmp;
       }
       return dummy->next;
    }

};

