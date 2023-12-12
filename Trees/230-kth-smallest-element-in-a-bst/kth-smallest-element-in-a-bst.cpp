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
    int kthSmallest(TreeNode* root, int& k) {
        
        if(root == NULL)
        {
            return -1;
        }
        
        int leftAns = kthSmallest(root -> left , k);
        
        if(leftAns != (-1))
        {
            return leftAns;
        }
        
        k--;
        
        if(k == 0)
        {
            return root -> val ;
        }
        
        int rightAns = kthSmallest(root -> right , k);
        
        return rightAns ;
        
    }
};

//ERROR THAT I HAD MADE
/*

agar leftSide k subarray se return hoga toh agar -1 naa hua toh root node tha nhi pahuch payega 

issiliye kyunki ek case hum solve kar rahe baaki recursion sambhaal rha hai .

toh answer return hote hote aayega first call k pass.


if(leftAns != (-1))
        {
            return leftAns;
        }


agar kuch nhi mila toh  right return ho jayegaa

*/



//APPROACH
/*
The approach used in this code is a recursive in-order traversal of the binary search tree (BST).
The function recursively explores the left subtree until it reaches the smallest element.
As it backtracks, it decrements the value of 'k' at each step until 'k' becomes zero, at which point it returns the current node's value as the kth smallest element.

*/

//THINGS YOU LEARNED
/*
1. The code employs a recursive in-order traversal to find the kth smallest element in the BST.

2. It backtracks while decrementing 'k' until 'k' becomes zero, indicating the kth smallest element is found.

3.this question also tells me that every question in the binary tree can be solved by the following 4 ways

- prorder traversal
-inorder traversal
- post order traversal
-level order traversal
*/

//CORNER CASES
/*
1. The code handles the case where the root of the BST is null, returning -1 to indicate an invalid result.
*/

//TIME COMPLEXITY - O(N)
/*
The time complexity is O(N), where N is the number of nodes in the binary search tree. In the worst case, the algorithm may need to visit all nodes in the tree.
*/

//SPACE COMPLEXITY - O(H)
/*
The space complexity is O(H), where H is the height of the binary search tree. The recursive calls use the call stack, and in the worst case, the space required is proportional to the height of the tree.
*/
