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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result=NULL;
        if(list1==NULL)
            return list2;
        else if(list2==NULL)
            return list1;
        ListNode* index1=list1;
        ListNode* index2=list2;
        ListNode* head;
        if(index1->val>index2->val){
                result=new ListNode(index2->val);
                index2=index2->next;
                head=result;
            }
        else{
                result=new ListNode(index1->val);
                index1=index1->next;
                head=result;
            }
        while(index1!=NULL&&index2!=NULL){
            if(index1->val>index2->val){
                result->next=new ListNode(index2->val);
                result=result->next;
                index2=index2->next;
            }
            else{
                result->next=new ListNode(index1->val);
                result=result->next;
                index1=index1->next;
            }
        }
        if(index1==NULL){
            result->next=index2;
        }
        else{
            result->next=index1;
        }
        return head;
    }
};