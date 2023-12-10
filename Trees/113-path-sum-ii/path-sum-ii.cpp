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
    
    void pathSumHelper(TreeNode* root, int targetSum , vector<vector<int>>& ans,vector<int>& subVec,int sum)
    {
        if(root == NULL)
        {
            return;
        }
        
        subVec.push_back(root -> val);
        
        sum += root -> val ;
        
        if(root -> left == NULL && root -> right == NULL)
        {
            if(sum == targetSum)
            {
                ans.push_back(subVec);
            }
        
        }
        
        pathSumHelper(root -> left , targetSum , ans , subVec , sum);
        
        pathSumHelper(root -> right , targetSum , ans , subVec , sum);
        
        subVec.pop_back();
        
        sum -= root -> val ;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans ;
        
        vector<int> subVec ;
        
        int sum = 0 ;
        
        pathSumHelper(root,targetSum,ans,subVec,sum);
        
        return ans ;
    }
};


//ERROR THAT I HAD MADE 
/*

pop_back() mei argument pass kar raha tha 

backtracking nhi kar raha tha 

*/

// APPROACH
/*
The approach used in this code is a recursive depth-first traversal of the binary tree. The `pathSumHelper` function is a recursive helper function that traverses the tree while maintaining a running sum of node values in the `sum` variable. It appends the current node value to the `subVec` vector, and when a leaf node is reached, it checks if the sum equals the `targetSum`. If true, it adds the current path (`subVec`) to the result vector `ans`. The recursion explores both the left and right subtrees. The `subVec.pop_back()` operation is used to backtrack after exploring the left and right subtrees, ensuring that the vector reflects the correct path at each step.

The `pathSum` function initializes the result vector `ans`, an empty path vector `subVec`, and the initial sum as 0. It then calls the recursive helper function to populate the `ans` vector with all paths that meet the specified target sum criteria.
*/

// THINGS YOU LEARNED
/*
This code demonstrates a classic application of recursive depth-first traversal in a binary tree to find all paths with a given sum. The backtracking mechanism, implemented through `subVec.pop_back()`, is essential for maintaining the correct state during the recursive exploration of paths. Additionally, the code effectively handles base cases for empty trees and identifies leaf nodes to determine when a valid path has been found.
*/

// CORNER CASES
/*
The code handles the case where the input binary tree is empty (`root == NULL`). This is essential to prevent dereferencing a null pointer and ensures that the function returns an empty result vector in such cases. It also correctly identifies leaf nodes using the condition `root->left == NULL && root->right == NULL`, indicating the end of a path. One consideration for corner cases is whether the values in the tree can be negative, as this might affect the sum comparison in the leaf nodes.
*/

// TIME COMPLEXITY - O(N)
/*
The time complexity is O(N), where N is the number of nodes in the binary tree. The code visits each node once, and the recursive calls ensure that every node is explored in the worst case.
*/

// SPACE COMPLEXITY - O(H)
/*
The space complexity is O(H), where H is the height of the binary tree. This is due to the recursion depth in the call stack. In the worst case, where the tree is skewed, the space complexity is O(N), where N is the number of nodes.
*/
