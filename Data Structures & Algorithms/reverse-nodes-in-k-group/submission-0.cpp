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
    ListNode* reverseKGroup(ListNode* head, int k) {

        //1.Pushing ll to array
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

        //3.Pushing arr back to ll
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
