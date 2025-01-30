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
    int max_depth=0;
    void search_depth(int current, TreeNode* node){
        if(node->right){
            search_depth(current+1, node->right);
        }
        if(node->left){
            search_depth(current+1, node->left);
        }
        if(current>max_depth){
            max_depth=current;
        }
    }

    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        search_depth(1, root);
        return max_depth;
    }
};