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
        n--;
        ListNode *node = head;
        ListNode *nPrev = head;
        ListNode *prev = nullptr;

        while(node && n--){
            node = node->next;
        }
        while(node->next){
            prev = nPrev;
            node = node->next;
            nPrev = nPrev->next;
        }
        if(prev){
            prev->next = nPrev->next;
            return head;
        } else {
            return head->next;
        }
        
    }
};