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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1){
            return head;
        } 
        
        ListNode* prevptr = NULL;
        ListNode* currptr = head;
        ListNode* nextptr;
        ListNode* check = currptr;
        int count = 1;
        
        while(check->next != NULL && count <= k){
            count++;
            check = check->next;
        }
        if(count < k){
            return head;
        }
        
        count = 0;
        while(currptr != NULL && count < k){
            nextptr = currptr->next;
            currptr->next = prevptr;
            
            prevptr = currptr;
            currptr = nextptr;
            count++;
        }
        
        if(nextptr != NULL){
            head->next = reverseKGroup(nextptr,k);
        }
        
        return prevptr;
    }
};