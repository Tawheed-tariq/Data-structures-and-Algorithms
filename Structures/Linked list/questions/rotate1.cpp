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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode *ptr = head;
        int len = 1;
        // find the length of list
        while(ptr->next){
            len++;
            ptr = ptr->next;
        }
        
        // If k is greater than the length of the list, compute k % len to avoid unnecessary full rotations.
        if(k%len == 0)
            return head;
        k = len - (k%len); //this will give us the position from which we have to rotate the list
        ptr->next = head;
        while(k--)
            ptr = ptr->next;
        
        ListNode *newHead = ptr -> next;
        ptr->next = nullptr;

        return newHead;
    }
};