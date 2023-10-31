class Solution {
public:
    
    void permuteUniqueHelper(vector<int>&nums , vector<vector<int>>& ans,int start)
    {
        
        //this is the base case
        
        if(start == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        
        //yaha pe set bhi use kar sakte the but time complexity and space complexity increase ho jaati
        
        unordered_map<int ,bool> visited;
        
        //if keys is found thenit return the iterator pointing to the address of that element
        
        //if not found then the it will return the visited.end().
        
    
        
        for(int i = start ; i < nums.size() ; i++)
        {
            
            //if condition yeh bata rahi hai ki agar element not equal to end hai
            //toh iska matlab element is already present in the unordered map
            //so usko mai continue ka use karke skip kar dena
            
            if(visited.find(nums[i]) != visited.end())
            {
                continue;
            }
            
            //yaha tak aa gye matlab element nhi hai pehle se 
            //so element ko unordered map mei daal denge
            
            visited[nums[i]] = true;
            
            //swapping variation banane hetu
            
            swap(nums[start],nums[i]);
            permuteUniqueHelper(nums,ans,start+1);
            
            
            //backtracking ho rhaa.
            
            swap(nums[start],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        
        //the ans vector is passing by reference so memory bach rhai hai   
        
        vector < vector <int>> ans;
        permuteUniqueHelper(nums,ans,0);
        return ans;
    }
};