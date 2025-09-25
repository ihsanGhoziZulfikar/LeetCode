/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
public:
    TreeNode* res;
    int p_val;
    int q_val;

    int preorder(TreeNode* node){
        if(!node)return 0;

        int found=0;

        if(node->val == p_val){
            found=1;
        }
        if(node->val == q_val){
            found=1;
        }
        int pre_res = found + preorder(node->left) + preorder(node->right);
        if(!res && pre_res==2){
            res = node;
        }
        return pre_res;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        p_val = p->val;
        q_val = q->val;
        preorder(root);
        return res;
    }
};


// class Solution {
// public:
//     vector<TreeNode*>p_anc;
//     vector<TreeNode*>q_anc;
//     int p_val;
//     int q_val;
//     // bool p_found;
//     // bool q_found;


//     void preorder(TreeNode* node, bool p_found, bool q_found){
//         if(!node)return;
//         if(p_found){
//             p_anc.push_back(node);
//         }
//         if(q_found){
//             q_anc.push_back(node);
//         }
//         if(node->val == p_val){
//             p_found=true;
//             p_anc.push_back(node);
//         }
//         if(node->val == q_val){
//             q_found=true;
//             q_anc.push_back(node);
//         }
//         preorder(node->left, p_found, q_found);
//         preorder(node->right, p_found, q_found);
//     }

//     static bool sortbyval(TreeNode* a, TreeNode* b){
//         return a->val > b->val;
//     }

//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         // vector<TreeNode*> v;
//         // p_found=false;
//         // q_found=false;
//         p_val = p->val;
//         q_val = q->val;
//         preorder(root, false, false);

//             for(int i=0;i<p_anc.size();i++){
//                 cout << p_anc[i]->val << endl;
//             }
//         reverse(p_anc.begin(), p_anc.end());
//         reverse(q_anc.begin(), q_anc.end());
//         cout << "aa\n";
//             for(int i=0;i<p_anc.size();i++){
//                 cout << p_anc[i]->val << endl;
//             }
//         int i=0;
//         // cout << p_anc.size() << " " << q_anc.size();
//         while(i<p_anc.size() && i<q_anc.size()){
//             if(p_anc[i]!=q_anc[i]){
//                 cout << "aaa " << i;
//                 return p_anc[i-1];
//             }
//             // cout << p_anc[i]->val << " " << q_anc[i]->val << endl;
//             i++;
//         }
//         cout << "bbb";
        
//         return p_anc[i-1<0?0:i-1];
//     }
// };

    // void preorder(TreeNode* node, vector<TreeNode*> anc){
    //     if(!node)return;
    //     anc.push_back(node);
    //     if(node->val == p_val){
    //         // for(int i=0;i<anc.size();i++){
    //         //     cout << anc[i] << endl;
    //         // }
    //         p_anc = anc;
    //     }
    //     if(node->val == q_val){
    //         // for(int i=0;i<anc.size();i++){
    //         //     cout << anc[i] << endl;
    //         // }
    //         q_anc = anc;
    //     }
    //     preorder(node->left, anc);
    //     preorder(node->right, anc);
    // }