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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *ptr = list1, *nxt = nullptr;
        int count = 1;
        while(count != a){
            ptr = ptr->next;
            count++;
        }

        nxt = ptr->next;
        ptr->next = list2;

        while(count != b){
            ListNode *temp = nxt;
            nxt = nxt->next;
            count++;
            delete temp;
        }

        while(ptr->next)
            ptr= ptr->next;
        
        ptr->next = nxt->next;

        return list1;
    }
};