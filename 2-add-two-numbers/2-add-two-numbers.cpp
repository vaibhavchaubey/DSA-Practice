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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* curr = dummyNode;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;                           //if 9+9=18 it will give 1
            curr->next = new ListNode(sum % 10);     //if 9+9=18 it will give 8
            curr = curr->next;
        }

        return dummyNode->next;
    }
};


//OR

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummyHead = new ListNode(0);
//         ListNode* p = l1; 
//         ListNode* q = l2; 
//         ListNode* curr = dummyHead;
//         int carry = 0;
//         while(p!=NULL || q!=NULL){
//             int x = (p!=NULL) ? p->val : 0;
//             int y = (q!=NULL) ? q->val : 0;
//             int sum = carry + x + y;
//             carry = sum/10;                        //if 9+9=18 it will give 1        
//             curr->next = new ListNode(sum % 10);  //if 9+9=18 it will give 8
//             curr = curr->next;
//             if(p!=NULL)
//                 p = p->next;
//             if(q!=NULL)
//                 q = q->next;
//         }
//         if(carry > 0){
//             curr->next = new ListNode(carry);
//         }
//         return dummyHead->next;        
//     }
// };