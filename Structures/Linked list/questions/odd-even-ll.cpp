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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = new ListNode(-1), *oddptr = odd;
        ListNode *even = new ListNode(-1), *evenptr = even;
        ListNode *ptr = head;

        int count = 1;
        while(ptr != NULL){
            ListNode *ele = new ListNode(ptr->val);
            if(count % 2 == 0){
                evenptr->next = ele;
                evenptr = ele;
            }else{
                oddptr->next = ele;
                oddptr = ele;
            }
            ptr=ptr->next;
            count++;
        }
        oddptr->next = even->next;
        return odd->next;
    }
};