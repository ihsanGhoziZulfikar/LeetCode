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
    vector<double> avgLvl;
    vector<int> countLvl;
    void averageLevel(TreeNode *node, int level){
        if(!node) return;
        if(avgLvl.size() <= level){
            avgLvl.push_back(0);
            countLvl.push_back(0);
        }
        avgLvl[level]+=node->val;
        countLvl[level]++;
        averageLevel(node->right, level+1);
        averageLevel(node->left, level+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        averageLevel(root,0);
        for(int i=0;i<avgLvl.size();i++){
            avgLvl[i]/=countLvl[i];
        }

        return avgLvl;
    }
};