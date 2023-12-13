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
    
    int ans = 0 ;
    
    void pathSumFinder(TreeNode* root, long long int Sum)
    {
        if(root == NULL)
        {
            return ;
        }
        
        if(Sum == root -> val)
        {
            ans++;
            
            //return nhi karenge kyunki aage bhi root -> val aise ho sakti ki 8 persist kare example jaise 0 or 1 ,-1 etc;
        }
        
        //left subtree lage haath backtrack bhi ho jaa raha  return aane pe
        
        pathSumFinder(root -> left , Sum - root -> val );
        
        //right subtree
        
        pathSumFinder(root -> right, Sum - root -> val );
    }
    
    
    //root node ko choose karne k liye bhi hum log preorder traversal kar rahe 
    
    int pathSum(TreeNode* root, long long targetSum) {
        
        if(root != NULL)
        {
            //N
        pathSumFinder(root,targetSum);
        
        //L
        pathSum(root -> left,targetSum);
        
        //R
        pathSum(root -> right,targetSum);
        }
    
        return ans ;
    }
};

//ERROR THAT I HAD MADE
/*

joh value di gyi hai usse ched chaad nhi lekin hum function parameter ka 
data type int se long long toh kar hi sakte hai .Usme koi dikkat nhi hai.

jab targetSum tak pahuch jaa rahe the toh return maarr  de rahe the 
lekin aisaa karna sahi nhi hai .

isme main function mei har baar alag alag root rakh k possible paths whose
equal to the targetSum .har baar root ko preorder traversal ki madad se find kar rahe

*/

// APPROACH
/*
   The code uses a recursive approach to perform a depth-first search (DFS) on a binary tree to find paths
   that sum to a given target. It employs a helper function 'pathSumFinder' to traverse the tree and count
   the valid paths.
*/

// THINGS YOU LEARNED
/*
   1. The code utilizes a recursive DFS strategy to explore all possible paths in a binary tree.
   2. It uses a helper function to perform the path sum calculation and counting.
   3. The code maintains a global variable 'ans' to accumulate the count of valid paths.
*/

// CORNER CASES
/*
   1. The code handles the case when the root is NULL, as it returns immediately in such instances.
   2. It correctly counts the paths where the sum is equal to the current node's value.
   3. The code correctly performs backtracking during the recursive calls on the left and right subtrees.
*/

// TIME COMPLEXITY - O(N)
/*
   N represents the number of nodes in the binary tree. The code performs a DFS traversal, visiting each
   node once. Therefore, the time complexity is O(N).
*/

// SPACE COMPLEXITY - O(H)
/*
   H represents the height of the binary tree. The space complexity is determined by the maximum depth
   of the recursive call stack. In the worst case, for an unbalanced tree, the space complexity is O(H).
   However, for a balanced tree, the space complexity is O(log N).
*/
