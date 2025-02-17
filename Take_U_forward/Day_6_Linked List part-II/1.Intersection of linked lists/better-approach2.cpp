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
        int findLength(ListNode *head){
            int count = 0;
            while(head != nullptr){
                count++;
                head = head->next;
            }
            return count;
        }
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            int l1 = findLength(headA), l2 = findLength(headB);
            ListNode *ptr1 = headA, *ptr2 = headB;
            if(l1 > l2){
                for(int i = 0; i < l1 - l2; i++){
                    ptr1 = ptr1->next;
                }
                
            }else{
                for(int i = 0; i < l2 - l1; i++){
                    ptr2 = ptr2->next;
                }
                
            }
            while(ptr2 != nullptr){
                if(ptr1 == ptr2)
                    return ptr1;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return NULL;
        }
    };