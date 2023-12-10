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
    
    bool solve(TreeNode* root, int targetSum,int sum)
    {
        if(root == NULL)
        {
            return false;
        }
        
        sum += root -> val ;
        
        if(root -> left == NULL && root -> right == NULL)
        {
            if(targetSum == sum)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool leftAns = solve(root -> left,targetSum,sum);
        
        bool rightAns = solve(root -> right,targetSum,sum);
        
        return leftAns || rightAns ;
    }
    
    
    bool hasPathSum(TreeNode* root, int targetSum) {
                
        int sum = 0 ;
        
        return solve(root,targetSum,sum);
            
    }
};

// ERROR THAT I HAD MADE
/*

    targetSum mei hi subtract kar rhe the joh galat hai . always keep in mind while sovling the question joh values provided hai uske saath ched chaad nhi karna chahiye .

*/

// APPROACH
/*
The approach of the code is to perform a depth-first search (DFS) on the binary tree. The solve function recursively traverses the tree, maintaining a running sum of node values from the root to the current node. If a leaf node is reached, it checks whether the sum equals the targetSum. The hasPathSum function initializes the sum and calls the solve function, returning true if a path with the target sum is found.

Overall, this is a straightforward recursive DFS approach for checking the existence of a path with a given sum in a binary tree.
*/

// THINGS YOU LEARNED
/*
The code demonstrates the use of recursion and DFS to explore paths in a binary tree. It highlights the importance of properly managing the running sum during the traversal. Additionally, the code effectively handles base cases when a leaf node is reached.
*/

// CORNER CASES
/*
The code handles the case where the input binary tree is empty (root is NULL), and it correctly checks for leaf nodes to determine if a path with the target sum exists. However, one consideration is whether the values in the tree can be negative, as this might affect the sum comparison in the leaf nodes.
*/

// TIME COMPLEXITY - O(N)
/*
The time complexity is O(N), where N is the number of nodes in the binary tree. This is because the code performs a depth-first traversal, visiting each node once.
*/

// SPACE COMPLEXITY - O(H)
/*
The space complexity is O(H), where H is the height of the binary tree. This is due to the recursive nature of the algorithm, and the maximum space required in the function call stack is proportional to the height of the tree.
*/
