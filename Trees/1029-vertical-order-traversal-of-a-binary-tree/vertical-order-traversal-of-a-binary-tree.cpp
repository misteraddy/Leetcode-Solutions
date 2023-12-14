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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        //kyunki return type hi aisa hai 
        
        queue<pair<TreeNode*,pair<int,int>>>q;    
        
        //Node, {row,col}
        
        //isme bst with the coordinate system . har node k kuch coordinates hai
        //associated with it .
                
        //performing the lvl order traversal 
        
        q.push({root,{0,0}});
        
        map<int , map<int, multiset<int>>>mp;   // [col -> {row : [x,y,z....]}]  
        
        while(!q.empty())
        {
            auto front = q.front() ;q.pop();
            
            TreeNode*& node = front.first;
            
            //node ko nikala humne queue se
            
            auto coordinate = front.second;
            
            int& row = coordinate.first;
            int& col = coordinate.second;
            
            //coordinate ko bhi extract kar liya uss corresponding node se
            
            mp[col][row].insert(node -> val);
            
            //example pushing 3 
            //before -> 
            //after ->
            
            if(node -> left != NULL)
            {
                q.push({node -> left,{row + 1, col - 1}});
            }
            
            if(node -> right != NULL)
            {
                q.push({node -> right, {row + 1, col + 1}});
            }
        }
        
        
        //store final vertical order into ans vector 
        
        for(auto it:mp){
            
            auto& colMap = it.second;
            
            //initialise the vector of vector of vectors
            
            vector<int>vLine;
            
            for(auto colMapIt : colMap )
            {
                
                //multiset ko access kar rahe 
                
                auto& mset = colMapIt.second;
                
                //the vLine is a vector jisme hum log ek shortcut tareeke se 
                //elements ko copy kar rahe without using the loop
                
                vLine.insert(vLine.end(), mset.begin(), mset.end()) ;
            }
            
            ans.push_back(vLine) ;
            
        }

        return ans ;
        
        
    }
};

 //APPROACH
        /*
        The approach involves performing a level-order traversal on the binary tree while maintaining coordinates (row, col) for each node. The coordinates help in arranging nodes in a virtual 2D space, where columns represent vertical positions. A map is used to store nodes based on their columns and rows, and a multiset is employed to keep nodes sorted within each column and row.
        */


        //THINGS YOU LEARNED
        /*
        - The level-order traversal ka use hota hai vertical aur top bottom view ko 
        dekhne k liye
        
        - map issilye use kar rahe kyunki ye sort kar de raha hai joh entry kar rhae according to the key value
        
        
        - Multiset is utilized to maintain the order of nodes within each column             and row.
        */
        
        //CORNER CASES 
        /*
        - The code handles the case where the input tree is empty (root is NULL).
        - The order of insertion into the multiset ensures that nodes at the same             position are sorted.
        */
        
        //TIME COMPLEXITY - O(N log N)
        /*
        - N represents the number of nodes in the binary tree.
        - The log N factor arises from the insertion operation into the multiset.
        */
        
        //SPACE COMPLEXITY - O(N)
        /*
        - The space complexity is determined by the space needed to store nodes in           the map and the queue.
        - In the worst case, all nodes need to be stored in the map, leading to               O(N) space complexity.
        */