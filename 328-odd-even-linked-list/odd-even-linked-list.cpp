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
    ListNode* oddEvenList(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* headEven = new ListNode(0);
        ListNode* node = head;
        ListNode* nodeEven = headEven;
        ListNode* prev;

        while(node && node->next){
            nodeEven->next = node->next;
            node->next = node->next->next;
            prev=node;
            node = node->next;
            nodeEven = nodeEven->next;
        }
        if(node){
            nodeEven->next = node->next;

            node->next = headEven->next;
        }else {
            prev->next = headEven->next;
        }
        return head;
    }
};