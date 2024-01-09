class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans ;

        vector<int> temp(nums.begin(),nums.end()) ;

        findpermute(nums,ans,0,temp);

        return ans;
    }

    void findpermute(vector<int>& nums,vector<vector<int>>& ans,int start,vector<int>& temp)
    {
        if(start >= nums.size())
        {
            ans.push_back(temp);
            return ;
        }

        for(int i = start ; i < nums.size() ; i++)
        {
            swap(temp[start],temp[i]);
            findpermute(nums,ans,start + 1,temp);
            swap(temp[start],temp[i]);
        }
    }
};