/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* copy = new Node(0);
        Node* copyNode = copy;
        map<int,Node*> m;
        map<Node*,Node*> mc;

        Node* node = head;
        while(node){
            copyNode->next = new Node(node->val);

            copyNode = copyNode->next;
            // m[copyNode->val] = copyNode;
            mc[node] = copyNode;
            
            node = node->next;
        }

        copy = copy->next;
        copyNode = copy;
        node = head;
        while(node){
            if(node->random){
                // copyNode->random = m[node->random->val];
                copyNode->random = mc[node->random];
            }
            node = node->next;
            copyNode = copyNode->next;
        }


        // for (const auto& pair : m) {
        //     cout << "Key: " << pair.first << ", Value: " << pair.second->val << endl;
        // }
        // copyNode = node;
        // while(copyNode){
        //     if(copyNode->random){
        //         copyNode->random = m[copyNode->random->val]
        //     }
        // }

        return copy;
    }
};