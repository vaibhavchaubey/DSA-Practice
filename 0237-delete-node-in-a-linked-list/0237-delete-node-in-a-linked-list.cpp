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
        // Since we know input node is not last node, so nextNode will not be null
        //we copy the next node’s value in the deleted node. Then, link node to next of next node.
        //also delete the next node so to escape memory leak
        
        ListNode* temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete temp;
    }
};
