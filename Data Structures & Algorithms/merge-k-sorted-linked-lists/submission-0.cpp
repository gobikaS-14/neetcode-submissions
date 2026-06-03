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
    ListNode* mergeKLists(vector<ListNode*>& L) {
        ListNode* res=new ListNode(0);
        ListNode* prev=res;
        while(true){
            int minInd=-1;
            for(int i=0;i<L.size();i++){
                if(L[i]!=NULL){
                 if(minInd==-1||L[i]->val < L[minInd]->val )    minInd=i;
                }
                }
            if(minInd==-1) break;
            //add smallest to the res LL
            prev->next=L[minInd];
            prev=prev->next;
            L[minInd]= L[minInd]->next; //move the smallest pointer
        }
        return res->next;
    }
};
