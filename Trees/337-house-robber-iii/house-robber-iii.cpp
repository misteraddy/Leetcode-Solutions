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
    int rob(TreeNode* root) {
        
        unordered_map<TreeNode*,int> dp ;

        int ans = solveUsingMemo(root,dp);

        return ans;
    }

    int solveUsingMemo(TreeNode* root,unordered_map<TreeNode*,int>& dp)
    {
        if(root == NULL)
        {
            return 0 ;
        }

        int robThisHouse = 0 ;

        int dontRobThisHouse = 0 ;

        robThisHouse += root -> val ;

        if(dp.find(root) != dp.end())
        {
            return dp[root];
        }

        if(root -> left != NULL)
        {
            robThisHouse += solveUsingMemo(root->left->left,dp) + solveUsingMemo(root->left->right,dp) ;
        }

        if(root -> right != NULL)
        {
            robThisHouse += solveUsingMemo(root->right->left,dp) + solveUsingMemo(root->right->right,dp) ;
        }

        dontRobThisHouse += solveUsingMemo(root -> left,dp) + solveUsingMemo(root -> right,dp);

        return dp[root] = max(robThisHouse,dontRobThisHouse);
    }
};

//bottom up dp is not possible