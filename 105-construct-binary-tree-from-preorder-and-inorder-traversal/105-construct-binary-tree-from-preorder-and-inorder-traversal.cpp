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
    int idx = 0;
    TreeNode* constructBT(vector<int>& preorder, int start, int end, unordered_map<int, int>& mp){ 
        if(start > end){
            return NULL;
        }
        int curr = preorder[idx];
        idx++;
        TreeNode* node = new TreeNode(curr);
        if(start == end){
            return node;
        }
        int pos = mp[curr];
        node->left = constructBT(preorder, start, pos-1, mp);
        node->right = constructBT(preorder, pos+1, end, mp);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0, end = inorder.size()-1;
        unordered_map<int, int> mp;
        for(int i = start; i <= end; i++){
            mp[inorder[i]] = i;
        }
        
       TreeNode* root = constructBT(preorder, start, end, mp);
        
        return root;
    }
};

//TC - O(N)
//SC - O(N)




//OR       TC - O(N^2)

// class Solution {
// public:
//     int idx = 0;
//     int search(vector<int>& inorder, int start, int end, int curr){
//         for(int i = start; i <= end; i++){
//             if(inorder[i] == curr){
//                 return i;
//             }
//         }
//         return -1;
//     }
//     TreeNode* constructBT(vector<int>& preorder, vector<int>& inorder, int start, int end){
//         if(start > end){
//             return NULL;
//         }
//         int curr = preorder[idx];
//         idx++;
//         TreeNode* node = new TreeNode(curr);
//         if(start == end){
//             return node;
//         }
//         int pos = search(inorder, start, end, curr);
//         node->left = constructBT(preorder, inorder, start, pos-1);
//         node->right = constructBT(preorder, inorder, pos+1, end);
        
//         return node;
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        TreeNode* root = constructBT(preorder, inorder, 0, preorder.size()-1);
        
//         return root;
//     }
// };