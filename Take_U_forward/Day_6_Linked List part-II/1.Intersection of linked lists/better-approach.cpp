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
            ListNode *ptr1 = headA, *ptr2 = headB;
            unordered_set<ListNode *> st;
            while(ptr1 != nullptr){
                st.insert(ptr1);
                ptr1 = ptr1->next;
            }
            while(ptr2 != nullptr){
                if(st.find(ptr2) != st.end())
                    return ptr2;
                ptr2 = ptr2->next;
            }
            return NULL;
        }
    };