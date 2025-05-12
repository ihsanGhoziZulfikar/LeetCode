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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> m;
        ListNode *node = head;
        ListNode *prev = nullptr;

        while(node){
            if(m[node->val]){
                m[node->val] = 2;
            }else{
                m[node->val] = 1;
            }
            node = node->next;
        }

        node = head;
        while(node){
            // cout << node->val << " - " << m[node->val] << endl;
            if(m[node->val] == 2){
                // cout << "node 2\n";
                while(node && m[node->val] == 2){
                    // cout << "while\n";
                    node = node->next;
                }
                if(!prev){
                    // cout << "not prev\n";
                    head = node;
                }else{
                    // cout << "prev\n";
                    prev->next = node;
                }
            }else{
                prev = node;
                node = node->next;
            }
        }

        return head;
    }
};


// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if(!head) return head;

//         map<int,int> m;
//         // m[head->val] = 1;
//         ListNode *node = head;
//         ListNode *prev = nullptr;

//         while(node){
//             int value = node->val;
//             if(m[value]){
//                 while(node && node->val == value){
//                     node = node->next;
//                 }

//                 if(!prev){
//                     head = node;
//                 }else{
//                     prev->next = node;
//                 }
//             }else{
//                 m[value] = 1;
//                 prev = node;
//                 node = node->next;
//             }
//         }
//         return head;
//     }
// };

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if(!head) return head;

//         map<int,int> m;
//         m[head->val] = 1;
//         ListNode *node = head->next;
//         ListNode *prev = head;

//         while(node){
//             if(m[node->val]){
//                 prev->next = node->next;
//                 node = prev->next;
//             }else{
//                 m[node->val] = 1;
//                 prev = node;
//                 node = node->next;
//             }
//         }
//         return head;
//     }
// };