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
        ListNode *reverseList(ListNode *head, ListNode *end){
            ListNode *curr = head, *prev = nullptr, *nxt = nullptr;
            while(curr != end){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            return prev;
        }
        
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode *ptr = head;
            int count = 0;
    
            while(ptr && count < k){
                ptr = ptr->next;
                count++;
            }
            if(count < k) return head;
    
            ListNode *new_head = reverseList(head, ptr);
    
            head->next = reverseKGroup(ptr, k);
    
            return new_head;
        }
    };