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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode* result;
        if(l1->val < l2->val){
            result = l1;
            result->next = mergeTwoLists(l1->next,l2);
        }
        else{
            result = l2;
            result->next = mergeTwoLists(l1,l2->next);
        }
        
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        if(lists.size() == 0){
            return lists[0];
        }
        int interval = 1;
        while(interval < lists.size()){
            for(int i = 0; i < lists.size() - interval; i = i + interval*2){
                lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }
};