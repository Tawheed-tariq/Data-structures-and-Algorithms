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
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0;
        ListNode* front = nullptr;
        ListNode* end = nullptr;
        ListNode* curr = head;

        // Traverse the list to find the k-th node from the start
        while (curr != nullptr) {
            count++;

            // Set the end pointer to the head after we reach the k-th node
            if (count == k) {
                front = curr;
                end = head;
            }

            // Move the end pointer to find the k-th node from the end
            if (count > k) {
                end = end->next;
            }

            curr = curr->next;
        }

        // Swap the values of the front and end nodes
        swapValues(front, end);

        return head;
    }

private:
    void swapValues(ListNode* node1, ListNode* node2) {
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
};
