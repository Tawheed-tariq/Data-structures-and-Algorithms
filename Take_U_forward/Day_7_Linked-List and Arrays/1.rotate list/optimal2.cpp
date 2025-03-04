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
        pair<ListNode*, int> length(ListNode* head){
            ListNode *ptr = head;
            int count = 1;
            while(ptr->next != NULL){
                ptr = ptr->next;
                count++;
            }
            return {ptr, count};
        }
    
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == NULL || head->next == NULL || k == 0)
                return head;
            ListNode *ptr = head, *nxt = NULL;
            pair<ListNode*, int> temp = length(head);
            ListNode *lst = temp.first;
            int len = temp.second;
            k = len - k%len;
            while(k > 0){
                nxt = ptr->next;
                lst->next = ptr;
                ptr->next = NULL;
                ptr = nxt;
                lst= lst->next;
                k--;
            }
            return ptr;
        }
    };