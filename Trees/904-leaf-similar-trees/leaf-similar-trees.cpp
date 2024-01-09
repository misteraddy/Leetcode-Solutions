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
    
    void findLeafNodes(TreeNode* root, string &ans)
    {
        if(root == NULL)
        {
            return;
        }
        
        findLeafNodes(root->left, ans);
        
        if(root->left == NULL && root->right == NULL)
        {
            ans = ans + " " + to_string(root->val);
        }
        
        findLeafNodes(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        string leaf1 = "";
        findLeafNodes(root1, leaf1);
        
        string leaf2 = "";
        findLeafNodes(root2, leaf2);
        
        return leaf1 == leaf2;
    }
};