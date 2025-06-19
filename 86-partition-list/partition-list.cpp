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
    ListNode* partition(ListNode* head, int x) {
        ListNode *greatHead = new ListNode();
        ListNode *greatNode = greatHead;
        ListNode *node = head;
        ListNode *prev = nullptr;
        
        while(node){
            ListNode *next = node->next;
            if(node->val >= x){
                if(prev){
                    prev->next = node->next;
                }else{
                    head = node->next;
                }

                node->next = nullptr;
                greatNode->next = node;
                greatNode = greatNode->next;
            }else{
                prev = node;
            }

            // prev = node;
            node = next;
        }
        // node = head;
        // greatNode = greatHead;
        // while(node){
        //     cout << node->val << endl;
        //     node = node->next;
        // }
        // cout << endl;
        // while(greatNode){
        //     cout << greatNode->val << endl;
        //     greatNode = greatNode->next;
        // }

        if(prev && greatHead->next){
            prev->next = greatHead->next;
        }else if(!prev && greatHead->next){
            head = greatHead->next;
        }
            
        return head;
    }
};