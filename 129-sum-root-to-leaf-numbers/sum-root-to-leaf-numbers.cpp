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
    int result;
    void dfs(TreeNode* node, int total) {
        if(!node)
            return;
        total *= 10;
        total += node->val;
        if(node->left){
            dfs(node->left, total);
        }
        if(node->right){
            dfs(node->right, total);
        }
        if(!node->left && !node->right){
            result += total;
        }
        
    }
    int sumNumbers(TreeNode* root) {
        result = 0;
        dfs(root, 0);
        return result;
    }
};