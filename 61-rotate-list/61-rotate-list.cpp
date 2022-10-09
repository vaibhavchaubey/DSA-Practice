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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        ListNode* temp = head;
        int l = 1;
        while(temp->next != NULL){
            l++;
            temp = temp->next;
        }
        temp->next = head;            //link last node to first node
        k = k % l;                   //If k > l
        int end = l-k;              //to get end of the list
        while(end--){
            temp = temp->next;
        }
        head = temp->next;        //breaking last node link and pointing to NULL
        temp->next = NULL;
        
        return head;    
    }
};


// OR

// class Solution {
// public:
//     int length(ListNode* head){
//         ListNode* temp = head;
//         int l = 0;
//         while(temp != NULL){
//             l++;
//             temp = temp->next;
//         }
//         return l;
//     }
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL || k == 0){
//             return head;
//         }
//         ListNode* newHead = NULL;
//         ListNode* newTail = NULL;
//         ListNode* temp = head;
        
//         int l = length(head);
//         k = k % l;                  //If k > l
        
//         if(k == 1){
//             while(temp->next->next != NULL){
//                 temp = temp->next;
//             }
//             temp->next->next = head;
//             newHead = temp->next;
//             temp->next = NULL;
//             return newHead;
//         }
        
//         int count = 1;
//         while(temp->next != NULL){
//             if(count == l-k){
//                 newTail = temp;
//             }
//             if(count == l-k+1){
//                 newHead = temp;
//             }
//             temp = temp->next;
//             count++;
//         }
//         newTail->next = NULL;
//         temp->next = head;
//         return newHead;
//     }
// };


// OR Brute Force     (It will give TLE)

// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
//         for(int i = 0; i < k; i++){
//             ListNode* temp = head;
//             while(temp->next->next != NULL){
//                 temp = temp->next;
//             }
//             ListNode* end = temp->next;
//             temp->next = NULL;
//             end->next = head;
//             head = end;
//         }
//         return head;
//     }
// };