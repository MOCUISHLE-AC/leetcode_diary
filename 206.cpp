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
    ListNode* reverseList_head=NULL;//反转链表头节点
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* index= head;
        //递归
        while(index!=NULL){
            if(index==head){
                reverseList_head=new ListNode(index->val);
            }
            else{
                ListNode* temp=new ListNode(index->val,reverseList_head);
                this->reverseList_head=temp;
            }
            index=index->next;
        }
        return reverseList_head;
    }
};