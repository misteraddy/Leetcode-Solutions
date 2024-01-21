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

    map<pair<int,int>,vector<TreeNode*>>dp ;

    vector<TreeNode*> solve(int start,int end)
    {
        if(start > end)
        {
            return {NULL};
        }

        if(start == end)
        {
            TreeNode* root = new TreeNode(end) ;
            return dp[{start,end}] = {root} ;
        }

        if(dp.find({start,end}) != dp.end())
        {
            return dp[{start,end}];
        }

        vector<TreeNode*> ans ;

        for(int i = start ; i <= end ; i++)
        {
            vector<TreeNode*> left = solve(start,i - 1);

            vector<TreeNode*> right = solve(i + 1,end);

            for(TreeNode* leftRoot : left)
            {
                for(TreeNode* rightRoot : right)
                {
                    TreeNode* root = new TreeNode(i);

                    root -> left = leftRoot;
                    root -> right = rightRoot;
                    ans.push_back(root);
                }
            }

            dp[{start,end}] = ans ;
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {

        return solve(1,n);  //yaha maine 0 daala tha 
    }
};