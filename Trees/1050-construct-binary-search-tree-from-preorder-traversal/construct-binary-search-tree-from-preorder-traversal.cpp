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
    map<int, int> mp;

    void mapping(vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
    }

    TreeNode* bstFromPreOrderHelper(vector<int>& inorder, vector<int>& preorder, int& preIndex, int size, int inorderStart, int inorderEnd) {
        // base case
        if (preIndex >= size || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = preorder[preIndex];
        preIndex++;

        int position = mp[element];

        TreeNode* root = new TreeNode(element);

        root->left = bstFromPreOrderHelper(inorder, preorder, preIndex, size, inorderStart, position - 1);
        root->right = bstFromPreOrderHelper(inorder, preorder, preIndex, size, position + 1, inorderEnd);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder; // copy the vector
        sort(inorder.begin(), inorder.end());

        int preIndex = 0;
        int size = inorder.size();
        int inorderStart = 0;
        int inorderEnd = size - 1;

        mapping(inorder);

        TreeNode* ansNode = bstFromPreOrderHelper(inorder, preorder, preIndex, size, inorderStart, inorderEnd);

        return ansNode;
    }
};

//ERROR THAT I MADE
/*

The sort function does not return a vector, and you need to create an inorder vector properly.

make a copy with the name inorder and sort it using the stl .

*/

// APPROACH
/*
   The code implements the construction of a binary search tree (BST) from a given preorder traversal. 
   The key insight is that in a BST, the values in the left subtree of any node are smaller than the node's value, 
   and the values in the right subtree are larger. The algorithm recursively builds the tree by selecting the 
   elements from the preorder traversal and determining their positions in the inorder traversal to identify 
   the left and right subtrees.
*/

// THINGS YOU LEARNED
/*
   1. Construction of a binary search tree from preorder traversal.
   2. Use of recursive algorithms for tree construction.
   3. Mapping elements in the inorder traversal to optimize the search for positions.
   4. Proper usage of data structures like vectors and maps.
   5. map gives the element in O(1);
   6. sort stl doesnt return anything it just updates the data structure whose iterator are being passed .
*/

// CORNER CASES
/*
   1. The code handles the base case where the preIndex exceeds the size of the traversal or when the inorder range is invalid.
   2. It accounts for the edge case of an empty preorder traversal.
*/

// TIME COMPLEXITY - O(N log N)
/*
   The time complexity is determined by the sorting operation on the inorder traversal, 
   which takes O(N log N) time, where N is the number of elements in the traversal.
   The recursive construction of the tree also contributes to the time complexity.
*/

// SPACE COMPLEXITY - O(N)
/*
   The space complexity is O(N) as it uses additional space for the inorder traversal, 
   the recursive call stack, and the map to store the positions of elements in the inorder traversal.
   N is the number of elements in the traversal.
*/
