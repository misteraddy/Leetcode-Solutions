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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        int currentLevel = 1;

        vector<int> currentLevelValues;
        vector<vector<int>> result;

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();

                if (currentNode->left != nullptr) {
                    nodeQueue.push(currentNode->left);
                }

                if (currentNode->right != nullptr) {
                    nodeQueue.push(currentNode->right);
                }

                currentLevelValues.push_back(currentNode->val);
            }

            // Zigzag order: reverse every second level
            if (currentLevel % 2 == 0) {
                reverse(currentLevelValues.begin(), currentLevelValues.end());
            }

            result.push_back(currentLevelValues);
            currentLevelValues.clear();
            currentLevel++;
        }

        return result;
    }
};

//ERROR THAT I HAD MADE
/*

when root will be empty ye case consider nhi kiya 

hum deque bana k pop_front aur pop_back kar rhe the according to the level number . aur NULL push kar de rahe the level k endpoint ko samjhne k liye.

uski vajah se aise answer aa rha tha

[[3],[],[20,9],[],[15,7],[]]

*/

//APPROACH
/*
Initialization:

Create an empty queue (nodeQueue).
Push the root node into the queue if it exists; otherwise, return an empty result.
Traversal:

Use a loop to traverse each level of the tree.
For each level, process all nodes in the current level.
Enqueue the children of the current node (if they exist) into the queue.
Level Order Traversal:

Use a loop to process nodes at the current level.
Dequeue a node from the front of the queue.
Enqueue its left and right children (if they exist) into the queue.
Zigzag Order:

Keep track of the current level number (currentLevel) to determine whether to reverse the order of node values in the current level.
Reverse the order of values in every second level to achieve the zigzag order.
Result Accumulation:

Store the values of the current level in a vector (currentLevelValues).
Push the vector into the result vector (result) after processing each level.
Return Result:

Return the final result vector containing zigzag level order traversal.

*/

//THINGS YOU LEARNED 
/*
// int frontElement = q.front() ; q.pop() ;

the root node has the level 1 

the clear is used to make the vector empty .

*/

//TIME COMPLEXITY - O(N)

//SPACE COMPLEXITY - O(N)
            
