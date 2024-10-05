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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ans = new ListNode(-1);
        ListNode *ptr = ans, *curr = head, *prev = NULL;

        if(!head || !head->next)
            return head;

        while(curr){
            if(curr->next && curr->val == curr->next->val){
                while(curr->next && curr->val == curr->next->val){
                    prev = curr;
                    curr = curr->next;
                }
            }else{
                ListNode *node = new ListNode(curr->val);
                ptr->next = node;
                ptr = node;
            }
            prev = curr;
            curr = curr->next;
        }
        return ans->next;
    }
};