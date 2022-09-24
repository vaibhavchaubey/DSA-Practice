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
    void getPath(TreeNode* root,int targetSum,vector<vector<int>>&ans,vector<int>v){
        if(root == NULL){
            return;
        }
        v.push_back(root->val);
        if(root->val == targetSum && root->left == NULL && root->right == NULL){
            ans.push_back(v);
            return;
        }
        getPath(root->left, targetSum - root->val, ans, v);
        getPath(root->right, targetSum - root->val, ans, v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        getPath(root,targetSum,ans,v);
            
        return ans;
    }
};