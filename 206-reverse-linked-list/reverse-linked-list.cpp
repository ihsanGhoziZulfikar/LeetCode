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
    ListNode* rev(ListNode* node){
        ListNode *prev=nullptr, *next;
        while(node){
            next = node->next;
            node->next = prev;

            prev = node;
            node = next;
            // cout << prev->val << endl;
        }
        return prev;
    }
    ListNode* reverseList(ListNode* head) {
        head = rev(head);
        return head;
    }
};