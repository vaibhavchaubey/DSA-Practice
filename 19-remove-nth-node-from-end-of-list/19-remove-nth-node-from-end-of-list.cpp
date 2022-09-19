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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        if(fast == NULL){
            ListNode*node=head;
            head=head->next;
            delete node;
            return head;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* todelete = slow->next;
        slow->next= slow->next->next;
        delete todelete;
        
        return head;
    }
};


//OR

// class Solution {
// public:
//     int length(ListNode* head){
//         int l=0;
//         ListNode* temp = head;
//         while (temp!=NULL){
//             l++;
//             temp = temp->next;
//         }
//         return l;
//     }
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if(head == NULL){
//             return head;
//         }
//         int l = length(head);
//         int pos = l-n+1;
//         if(l==1 || pos==1){
//             return head->next;
//         }

//         ListNode* temp = head;
//         int count = 1;
//         while(count!=pos-1){
//             temp = temp->next;
//             count++;
//         }
//         ListNode* todelete = temp->next;
//         temp->next = temp->next->next;
//         delete todelete;
        
//         return head;
//     }
// };