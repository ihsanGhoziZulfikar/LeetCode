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
    int target;
    bool hasPath(TreeNode* node, int current){
        if(!node){
            if(current == target) return true;
            return false;
        }

        bool left = hasPath(node->left,current+node->val);
        bool right = hasPath(node->right,current+node->val);

        if(node->left && node->right){
            return left || right;
        }else if(node->left){
            return left;
        }else {
            return right;
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        target=targetSum;
        return hasPath(root,0);
    }
};