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
typedef long long int ll;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* addedNode = new ListNode();
        ListNode* node = addedNode;

        int prev = 0;
        
        while(l1 && l2){
            int val = l1->val + l2->val + prev;
            if(val>9) prev = 1;
            else prev = 0;
            val%=10;
            node->next = new ListNode(val);
            l1 = l1->next;
            l2 = l2->next;
            node = node->next;
            cout << node->val << endl;
        }
        while(l1){
            int val = l1->val + prev;
            if(val>9) prev = 1;
            else prev = 0;
            val%=10;
            node->next = new ListNode(val);
            l1 = l1->next;
            node = node->next;
        }
        while(l2){
            int val = l2->val + prev;
            if(val>9) prev = 1;
            else prev = 0;
            val%=10;
            node->next = new ListNode(val);
            l2 = l2->next;
            node = node->next;
        }
        if(prev){
            node->next = new ListNode(prev);
        }

        return addedNode->next;
    }
};

