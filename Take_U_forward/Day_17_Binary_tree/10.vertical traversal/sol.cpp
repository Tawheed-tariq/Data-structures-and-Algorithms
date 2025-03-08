/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            //create map<vertical,map<level,node->val>>>
            map<int,map<int,multiset<int>>>nodes;
            
            //create a queue<pair<Node,pair<vertical,level>>>
            queue<pair<TreeNode*,pair<int,int>>>q;
    
            //push root to queue
            q.push({root,{0,0}});
    
            while(!q.empty()){
                auto p=q.front();
                q.pop();
    
                TreeNode*node=p.first; //insert the value of the node
                int x=p.second.first; //insert the vaetical 
                int y=p.second.second;//insert the level
                
                //insert nodes[vertical][level]=node->val
                nodes[x][y].insert(node->val);
    
                if(node->left){
                    q.push({node->left,{x-1,y+1}});
                }
                if(node->right){
                    q.push({node->right,{x+1,y+1}});
                }
            }
    
            vector<vector<int>>ans;
    
            for(auto p:nodes){  //visit all the map elements
                vector<int>col; 
                for(auto q:p.second){
                  col.insert(col.end(),q.second.begin(),q.second.end());
                }
                ans.push_back(col);
            }
            return ans;
        }
    };