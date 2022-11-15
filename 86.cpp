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
    ListNode* partition(ListNode* head, int x) {
        //leetcode中需要注意指针初始化，否则结果会十分诡异
        ListNode* big_flag=NULL;//index最小的，val>x
        ListNode* result=NULL;
        ListNode* index=head;
        ListNode* result_head=NULL;
        //第一次遇见index->val>x
        bool meet_time=true;
        while(index!=NULL){
            if(index->val<x){
                if(result_head==NULL){
                    result_head=new ListNode (index->val);
                    result=result_head;
                    index=index->next;
                }
                else{
                    result->next=new ListNode (index->val);
                    result=result->next;//null;
                    index=index->next;
                }
            }
            else{
                if(meet_time)
                {
                    big_flag=index;
                    meet_time=false;
                }
                index=index->next;  
            }
        }
        index=big_flag;
        //再次遍历
        while(index!=NULL){
            if(index->val<x){
                index=index->next;
            }
            else{
                if(result_head==NULL){
                    result_head=new ListNode (index->val);
                    result=result_head;
                    index=index->next;
                }
                else{
                    result->next=new ListNode (index->val);
                    result=result->next;//null;
                    index=index->next;
                }
            }
        }
        return result_head;
    }
};