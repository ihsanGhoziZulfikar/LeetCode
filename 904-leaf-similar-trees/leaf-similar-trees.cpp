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
    stack<int> st;
    void bfs(TreeNode *node, bool first){
        if(!node) return;
        if(!node->left && !node->right){
            if(first){
                st.push(node->val);
            }else{
                if(!st.empty() && st.top() == node->val){
                    st.pop();
                }else{
                    st.push(201);
                }
            }
            
        }else{
            if(first){
                bfs(node->left, first);
                bfs(node->right, first);

            }else{
                
                bfs(node->right, first);
                bfs(node->left, first);
            }
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        TreeNode *node1 = root1;
        bfs(root1, true);
        bfs(root2, false);
        if(st.empty()){
            return true;
        }else{
            // while(!st.empty()){
            //     cout << st.top() << endl;
            //     st.pop();
            // }
            return false;
        }
    }
};