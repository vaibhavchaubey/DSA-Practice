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
    int length(ListNode* head){
        int l = 0;
        ListNode* temp = head;
        while(temp != NULL){
            l++;
            temp = temp->next;
        }
        return l;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1){
            return head;
        } 
        
        int l = length(head);
        
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        
        ListNode* prevptr = dummyNode;
        ListNode* currptr;
        ListNode* nextptr;
        
        while(l >= k){
            currptr = prevptr->next;
            nextptr = currptr->next;
            for(int i = 1; i < k; i++){
                currptr->next = nextptr->next;
                nextptr->next = prevptr->next;
                prevptr->next = nextptr;
                nextptr = currptr->next;                
            }
            prevptr = currptr;
            l -= k;
        }
        
        return dummyNode->next;
    }
};