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
        int l=0;
        ListNode* temp = head;
        while (temp!=NULL){
            l++;
            temp = temp->next;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        int l = length(head);
        int pos = l-n+1;
        if(l==1 || pos==1){
            return head->next;
        }

        ListNode* temp = head;
        int count = 1;
        while(count!=pos-1){
            temp = temp->next;
            count++;
        }
        ListNode* todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
        
        return head;
    }
};