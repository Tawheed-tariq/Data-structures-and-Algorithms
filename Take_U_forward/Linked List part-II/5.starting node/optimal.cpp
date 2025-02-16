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
        ListNode *checkCycle(ListNode *head){
            if(!head || !head->next)
                return NULL;
            ListNode *slow = head, *fast = head->next;
            while(slow != NULL && fast != NULL){
                slow = slow->next;
                fast = fast->next;
                if(fast)
                    fast = fast->next;
                if(fast == slow)
                    return slow->next;
            }
            return NULL;
        }
        ListNode *detectCycle(ListNode *head) {
            ListNode *temp = checkCycle(head);
            ListNode *slow = head;
            if(temp == NULL)
                return NULL;
            while(slow != temp){
                slow = slow->next;
                temp = temp->next;
            }
            return slow;
        }
    };