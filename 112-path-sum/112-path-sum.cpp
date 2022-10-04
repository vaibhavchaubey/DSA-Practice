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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        if(root->val == targetSum && root->left == NULL && root->right == NULL){
            return true;
        }
        return hasPathSum(root->left,targetSum - root->val) ||                                  hasPathSum(root->right,targetSum - root->val);
    }
};

//OR

// if(root == NULL){
//             return false;
//         }
//         sum += root->val;
//         if(root->left == NULL && root->right == NULL){
//             return sum == targetSum;
//         }
//         return (pathSum(root->left,targetSum) || pathSum(root->right,targetSum));
//     }
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         return pathSum(root,targetSum,0);
//     }
// };