/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    public:
        Node *dfs(Node *curr, unordered_map<Node* , Node*> &mp){
            vector<Node *> neighbour;
            mp[curr] = new Node(curr->val);
    
            for(auto x: curr->neighbors){
                if(mp.find(x) != mp.end())
                    neighbour.push_back(mp[x]);
                else
                    neighbour.push_back(dfs(x, mp));
            }
            mp[curr]->neighbors = neighbour;
            return mp[curr];
        }
        Node* cloneGraph(Node* node) {
            unordered_map<Node*, Node*> mp;
            if(node == NULL) return NULL;
    
            if(node->neighbors.size() == 0){
                Node* clone = new Node(node->val);
                return clone;
            }
            return dfs(node, mp);
        }
    };