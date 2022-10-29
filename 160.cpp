/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL){
            return NULL;
        }
        else{
            ListNode* indexa=headA;
            ListNode* indexb=headB;
            while(indexa!=NULL){
                while(indexb!=NULL){
                    if(indexa == indexb)
                        return indexa;
                    else
                        indexb=indexb->next;
                }
                indexa=indexa->next;
                indexb=headB;
            }
            return NULL;
        }
    }
};