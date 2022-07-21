/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* leftPrev = dummy;
        ListNode* current = head;
        for(int i = 0; i < left-1; i++){
            leftPrev = current;
            current = current->next;
        }
        
        ListNode* prev = NULL;
        for(int i = 0; i < right-left+1; i++){
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        
        leftPrev->next->next = current;
        leftPrev->next = prev;
        
        return dummy->next;
    }
};