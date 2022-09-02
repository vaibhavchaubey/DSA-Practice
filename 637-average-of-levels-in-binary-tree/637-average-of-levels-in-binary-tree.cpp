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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        if(root == NULL){
            return v;
        }
        double sum = 0;
        double cnt  = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node){
                sum += node->val;
                cnt++;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            else if(!q.empty()){
                q.push(NULL);
                double avg = sum/cnt;
                v.push_back(avg);
                sum = 0;
                cnt = 0;                
            }   
        }       
        
        //It is again done for last level because in that case 
        //else if loop will not run as queue becomes empty
        
        double avg = sum/cnt;          
        v.push_back(avg);
        return v;        
    }
};


