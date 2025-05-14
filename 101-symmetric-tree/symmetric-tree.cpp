/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2 || root1->val!=root2->val){
            // cout << root1->val << " - " << root2->val << endl;
            return false;
        }

        bool left = isSameTree(root1->left, root2->right);
        bool right = isSameTree(root1->right, root2->left);
        return (left && right);
    }

    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, root->right);
    }
};