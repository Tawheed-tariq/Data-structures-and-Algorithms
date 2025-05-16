/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            unordered_map<Node *, Node *> deep_copy;
    
            Node *curr = head;
            while(curr != NULL){
                deep_copy[curr] = new Node(curr->val);
                curr = curr->next;
            }
    
            curr = head;
            while(curr != NULL){
                deep_copy[curr]->next = deep_copy[curr->next];
                deep_copy[curr]->random = deep_copy[curr->random];
                curr = curr->next;
            }
    
            return deep_copy[head];
        }
    };