/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    map<int, Node*> m;
    void preorderRev(Node* node, int depth){
        if(!node) return;
        // cout << node->val;
        if(m[depth]){
            node->next = m[depth];
        }
        m[depth] = node;
        preorderRev(node->right, depth+1);
        preorderRev(node->left, depth+1);
    }

    Node* connect(Node* root) {
        preorderRev(root, 0);
        return root;
    }
};