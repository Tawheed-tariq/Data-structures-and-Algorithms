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
    int length(ListNode *head){
        int count  = 0;
        ListNode *ptr = head;
        while(ptr != nullptr){
            ptr = ptr->next;
            count++;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = length(head);
        int avgLen = len / k, extraLen = len % k;
        vector<ListNode*> res;

        ListNode *prevHead= head;
        while(k--){
            int partLen = avgLen;
            if(extraLen > 0) partLen++;
            partLen--;
            ListNode *newHead = prevHead, *ptr = newHead;
            while(newHead && partLen--){
                newHead = newHead->next;
            }

            if(newHead){
                prevHead = newHead->next;
                newHead->next = nullptr;
            }

            res.push_back(ptr);
            extraLen--;
        }
        return res;
    }
};