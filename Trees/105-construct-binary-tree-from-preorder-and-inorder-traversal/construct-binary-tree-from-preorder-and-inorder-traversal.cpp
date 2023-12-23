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
    
    map<int,int> mpp ;
    
    void mapping(vector<int> inorder,int size)
    {
        for(int i = 0 ; i < size ; i++)
        {
            mpp[inorder[i]] = i ;
        }
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder,vector<int>& inorder,int& preIndex,int size,int inorderStart,int inorderEnd)
    {
        if(preIndex >= size || inorderStart > inorderEnd)
        {
            return NULL;
        }
        
        int element = preorder[preIndex] ;
        preIndex++;
        
        int position = mpp[element];
        
        TreeNode* root = new TreeNode(element);
        
        root -> left = buildTreeHelper(preorder,inorder,preIndex,size,inorderStart,position - 1);
        
        root -> right = buildTreeHelper(preorder,inorder,preIndex,size,position + 1,inorderEnd);
        
        
        return root ;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0 ;
        int size = inorder.size();
        int inorderStart = 0 ;
        int inorderEnd = size - 1 ;
        
        mapping(inorder,size);
        
        TreeNode* result = buildTreeHelper(preorder,inorder,preIndex,size,inorderStart,inorderEnd);
        
        return result ;
    } 
};

// APPROACH
/*
The approach used in this code is to recursively build the binary tree using the preorder traversal and the mapping of elements' positions in the inorder traversal.
1. The mapping function is used to store the positions of elements in the inorder traversal.
2. The buildTreeHelper function is a recursive function that constructs the tree by dividing the problem into smaller subproblems.
3. For each node in the preorder traversal, the root is created, and the left and right subtrees are constructed recursively.
4. The position of the current element in the inorder traversal is used to determine the elements in the left and right subtrees.
5. The process continues until the entire tree is constructed.

*/

// THINGS YOU LEARNED
/*
1. The mapping of elements in the inorder traversal is crucial for efficiently determining the left and right subtrees during the construction of the binary tree.
2. Recursive traversal of the preorder sequence is used to build the tree incrementally.
3. The index of the current element in the preorder sequence helps keep track of the progress in constructing the tree.

*/

// CORNER CASES
/*
1. The base cases for the recursive function include checking if the preIndex exceeds the size of the traversal arrays or if the inorderStart surpasses inorderEnd. In such cases, a null node is returned.
2. Handling empty input arrays should be considered.

*/

// TIME COMPLEXITY - O(N)
/*
The time complexity of the algorithm is O(N), where N is the number of nodes in the binary tree. This is because each node is processed exactly once in both the preorder and inorder traversals.

*/

// SPACE COMPLEXITY - O(N)
/*
The space complexity is O(N), where N is the number of nodes in the binary tree. This is due to the space used by the mapping of elements in the inorder traversal and the recursive call stack.

*/
