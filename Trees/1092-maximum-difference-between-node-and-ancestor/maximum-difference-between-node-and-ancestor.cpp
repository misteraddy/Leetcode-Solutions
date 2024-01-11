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

    int maxDiffHelper(TreeNode* root,int minV,int maxV)
    {
        if(root == NULL)
        {
            return abs(minV - maxV);
        }

        minV = min(minV,root -> val);

        maxV = max(maxV,root -> val);

        int l = maxDiffHelper(root -> left,minV,maxV);

        int r = maxDiffHelper(root -> right,minV,maxV);

        return max(l,r);
    }

    
    int maxAncestorDiff(TreeNode* root) {
        return maxDiffHelper(root,root -> val,root -> val);
    }
};