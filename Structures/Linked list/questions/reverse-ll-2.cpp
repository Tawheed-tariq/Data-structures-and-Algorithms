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
    pair<ListNode*, ListNode*> reverseLL(ListNode *ptr, int left, int right){
        ListNode *curr = ptr, *prev = NULL, *nxt = NULL;
        int count = left;
        while(count <= right){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        return make_pair(prev, nxt);
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next)
            return head;
        ListNode *ans = new ListNode(-1), *curr = head, *ptr = ans, *store = NULL;
        int count = 1;

        while(count != left){
            ptr->next = curr;
            ptr = curr;
            curr = curr->next;
            count++;
        }
        pair<ListNode*, ListNode*> res = reverseLL(curr, left, right);
        ptr->next = res.first; 
        ptr = res.first;
        while(ptr->next)
            ptr = ptr->next;
        ptr->next = res.second;
        return ans->next;
    }
};