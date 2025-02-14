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
        void insertNode(ListNode* &tail, int data){
            ListNode* n = new ListNode(data);
            tail -> next = n;
            tail = n;
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int carry = 0;
            ListNode* ans = new ListNode(-1);
            ListNode* temp = ans;
            while(l1 != NULL && l2 != NULL){
                int sum = l1->val + l2->val;
    
                sum +=carry;
                insertNode(temp, sum%10);
                cout << temp->val << endl;
    
                carry = sum/10;
                l1 = l1->next;
                l2 = l2->next;
            }
            while(l1 != NULL){
                int sum = l1->val;
    
                sum +=carry;
                insertNode(temp, sum%10);
    
                carry = sum/10;
                l1 = l1->next;
            }
            while(l2 != NULL){
                int sum = l2->val;
                
                sum +=carry;
                insertNode(temp, sum%10);
    
                carry = sum/10;
                l2 = l2->next;
            }
            if(carry != 0)
                insertNode(temp, carry);
            return ans->next;
        }
    };