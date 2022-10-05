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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val > list2->val) swap(list1,list2);
        ListNode* res = list1;
        while(list1 != NULL && list2 != NULL){
            ListNode* temp = NULL;
            while(list1 != NULL && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1,list2);
        }
        
        return res;
    }
};


//OR

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL) return list2;
//         if(list2 == NULL) return list1;
//         ListNode* p1 = list1;
//         ListNode* p2 = list2;
//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* p3 = dummyNode;
//         while(p1 != NULL && p2 != NULL){
//             if(p1->val < p2->val){
//                 p3->next = p1;
//                 p1 = p1->next;
//             }
//             else{
//                 p3->next = p2;
//                 p2 = p2->next;
//             }
//             p3 = p3->next;
//         }
//         if(p1 != NULL){
//             p3->next = p1;
//         }
//         else{
//             p3->next = p2;
//         }

//         return dummyNode->next;
//     }
// };