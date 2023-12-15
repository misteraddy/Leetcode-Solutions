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
    
    vector<TreeNode*> dup;  // 'ans' is now 'dup'
    
    unordered_map<string, int> freq;  // 'mpp' is now 'freq'
    
    string ser(TreeNode* root) {  // 'preorder' is now 'ser' for serialization
        if (!root) return "N";
        
        string curr = to_string(root->val);
        string left = ser(root->left);
        string right = ser(root->right);
        
        string serializedSubtree = curr + "," + left + "," + right ;
        
        if (freq.find(serializedSubtree) != freq.end()) {
            if (freq[serializedSubtree] == 1) {
                dup.push_back(root);
            }
            
            freq[serializedSubtree]++;
        } else {
            freq[serializedSubtree] = 1 ;
        }
        
        return serializedSubtree;
    }
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        ser(root);
        return dup ;
    }
};




// APPROACH
/*
The approach used in this program is to perform a preorder traversal of the binary tree.
For each subtree encountered during the traversal, the structure of the subtree is serialized into a string.
The serialized string is then used as a key in an unordered map to keep track of the frequency of each subtree.
If a serialized string is encountered more than once, it means there is a duplicate subtree.
The duplicates are identified and stored in the 'ans' vector.
*/

// THINGS YOU LEARNED
/*
1. Using preorder traversal for binary trees.
2. Serializing the structure of subtrees into strings.
3. Utilizing an unordered map to keep track of subtree frequencies.
4. Identifying and storing duplicate subtrees in a vector.
5. isme hum log encoding concept sikh rahe hai .

*/

// CORNER CASES
/*
The program handles the case when the tree is empty (root is NULL).
It also considers the case when a subtree has a value of "N" if it is NULL.
*/

// TIME COMPLEXITY - O(N)
/*
The time complexity of the program is O(N), where N is the number of nodes in the binary tree.
This is because each node is visited once during the preorder traversal.
*/

// SPACE COMPLEXITY - O(N)
/*
The space complexity of the program is O(N), where N is the number of nodes in the binary tree.
This is due to the storage of serialized strings in the unordered map.
In the worst case, all nodes of the tree need to be stored in the map.
*/

//ERROR THAT I HAD MADE
/*

iss tarah solve kar raha tha ye bhi ho sahi thaa lekin it was not giving the expected output 

example : [[2],[4]];

vapas create karne ki kosis kar rhaa tha tree ko joh bewkofi hai. firr usko bhej rhaa tha . 

humko original node ko hi bhejnaa tha vector k andar .

class Solution {
public:
    TreeNode* createSubtree(const string& str) {
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(str[0] - '0');
        q.push(root);

        for (int i = 1; i < str.size(); i++) {
            TreeNode* newNode = new TreeNode(str[i] - '0');
            TreeNode* parent = q.front();

            if (!parent->left) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
                q.pop();
            }

            q.push(newNode);
        }

        return root;
    }

    void map_creator(string& temp_str) {
        if (mpp.find(temp_str) != mpp.end()) {
            mpp[temp_str]++;
        } else {
            mpp[temp_str] = 1;
        }
    }

    void findDuplicateSubtreesHelper(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        string temp_str = to_string(root->val);

        findDuplicateSubtreesHelper(root->left);
        findDuplicateSubtreesHelper(root->right);

        map_creator(temp_str);
    }

    void inorderTraversal(TreeNode* root) {
        findDuplicateSubtreesHelper(root);
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;

        inorderTraversal(root);

        for (auto it = mpp.begin(); it != mpp.end(); it++) {
            if (it->second > 1) {
                TreeNode* Subtree = createSubtree(it->first);
                ans.push_back(Subtree);
            }
        }

        return ans;
    }

private:
    unordered_map<string, int> mpp;
};

*/
