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
        if(k==0 || !head)return head;
        ListNode *node = head;
        ListNode *prev = nullptr;
        ListNode *end = head;
        int len=0;
        while(node){
            len++;
            node = node->next;
        }
        k%=len;

        node = head;
        while(k--){
            end = end->next;
        }
        while(end->next){
            end = end->next;
            node = node->next;
        }
        end->next = head;
        prev = node->next;
        node->next = nullptr;
        return prev;
    }
};