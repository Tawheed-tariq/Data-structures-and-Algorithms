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
    void reorderList(ListNode* head) {
        vector<ListNode *> arr;
        ListNode *ptr = head;
        while(ptr != NULL){
            arr.push_back(ptr);
            ptr = ptr->next;
        }

        vector<ListNode *> res;
        int i = 0, j = arr.size() - 1;
        while(i <= j){
            if(i ==j){
                res.push_back(arr[i]);
                break;
            }
            res.push_back(arr[i]);
            res.push_back(arr[j]);

            i++;
            j--;
        }

        head->next = NULL;
        ptr = head;

        for(int i = 1; i < res.size(); i++){
            ListNode *curr = new ListNode(res[i]->val);
            ptr->next = curr;
            ptr = curr;
        }

    }
};