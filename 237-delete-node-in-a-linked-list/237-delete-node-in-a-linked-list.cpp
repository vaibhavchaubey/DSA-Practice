/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
    //we copy the value of next varibale and move the pointer to next
    //also remove the node so to escape memory leak
        
       ListNode* temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete temp;
    }
};

