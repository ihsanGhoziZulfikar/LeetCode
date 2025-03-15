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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next){
            return head->next;
        }
        vector<ListNode*> v;
        ListNode* temp = head;
        int n=0;
        while(temp){
            n++;
            v.push_back(temp);
            temp=temp->next;
        }
        n=n/2-1;
        v[n]->next = v[n]->next->next;
        return head;
    }
};