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
    void traverse(TreeNode* root, int x, int y, map<int,multiset<pair<int,int>>> &m){
        if(root == NULL){
            return;
        }
        m[x].insert({y,root->val});   // OR m[x].insert(make_pair(y,root->data));      
        
        traverse(root->left,x-1,y+1,m);
        traverse(root->right,x+1,y+1,m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,multiset<pair<int,int>>> m;
        traverse(root,0,0,m);
        
        for(auto a : m){
            vector<int> v;
            for(auto b : a.second){
                v.push_back(b.second);
            }
            ans.push_back(v);
        }
        return ans; 
    }
};

// x = horizontal_Level
// y = vertical_Level 