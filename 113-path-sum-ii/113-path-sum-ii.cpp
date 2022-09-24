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
    vector<vector<int>> paths;
    vector<int> path;
    
    void helper(TreeNode* root, int x){
        if(!root) return;
        path.push_back(root->val);
        if(!(root->left) and !root->right and x == root->val)
            paths.push_back(path);
        helper(root->left, x- root->val); 
        helper(root->right, x- root->val);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root, targetSum);
        return paths;
    }
};