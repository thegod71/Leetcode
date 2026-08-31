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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=head->next; 
        int maxi=INT_MIN,mini=INT_MAX,first_one=INT_MAX,prev_one=-1;
        int len=0;
        while(nxt!=NULL){
            if(prev!=NULL){
                if((prev->val > curr-> val &&  nxt->val > curr->val ) ||
                (prev->val < curr-> val &&  nxt->val < curr->val )){
                    if(prev_one!=-1){
                        mini=min(mini,len-prev_one);
                        maxi=max(maxi,len-first_one);
                    }
                    prev_one=len;
                    first_one=min(first_one,prev_one);
                }    
            }
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
            len++;
        }  
       return maxi == INT_MIN ? vector<int>{-1, -1} : vector<int>{mini,maxi};
    }
};