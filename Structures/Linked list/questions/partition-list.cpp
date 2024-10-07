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
        ListNode *lst1 = new ListNode(-1), *lst2 = new ListNode(-1), *ptr1 = lst1, *ptr2 = lst2, *ptr = head;
        while(ptr != NULL){
            ListNode *temp = new ListNode(ptr->val);
            if(ptr->val < x){
                ptr1->next = temp;
                ptr1 = temp;
            }else{
                ptr2->next = temp;
                ptr2 = temp;
            }
            ptr = ptr-> next;
        }
        ptr1->next = lst2->next;
        return lst1->next;
    }
};