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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        
        while(d1 != d2){
            if(d1 == NULL){
                d1 = headB;
            }
            else{
                d1 = d1->next;
            }
            
            if(d2 == NULL){
                d2 = headA;
            }
            else{
                d2 = d2->next;
            }
        }
        return d1;
    }
};


//OR

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
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int l1 = length(headA);
//         int l2 = length(headB);
        
//         int d = 0;
//         ListNode* ptr1;
//         ListNode* ptr2;
//         if(l1 > l2){
//             d = l1-l2;
//             ptr1 = headA;
//             ptr2 = headB;
//         }
//         else{
//             d = l2-l1;
//             ptr1 = headB;
//             ptr2 = headA;
//         }
//         while(d){
//             ptr1 = ptr1->next;
//             if(ptr1 == NULL){
//                 return NULL;
//             }
//             d--;
//         }
//         while(ptr1 != NULL && ptr2 != NULL){
//             if(ptr1 == ptr2){
//                 return ptr1;
//             }
//             ptr1 = ptr1->next;
//             ptr2 = ptr2->next;
//         }
//         return NULL;
//     }
// };



// OR

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> s;
//         while(headA != NULL){
//             s.insert(headA);
//             headA = headA->next;
//         }
//         while(headB != NULL){
//             if(s.find(headB) != s.end()){
//                 return headB;
//             }
//             headB = headB->next;
//         }
//         return NULL;
//     }
// };