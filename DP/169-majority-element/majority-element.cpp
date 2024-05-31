class Solution {
public:

    // this is the better approach 

    int majorityElement(vector<int>& nums) {

        int N = nums.size();

        map<int,int> mp ; //the insertion in the map takes logn times and we are doing this in N times so N*logn

        for(int element = 0 ; element < N ; element++)
        {
            mp[nums[element]]++;
        }

        for(auto it : mp)
        {
            if(it.second > (N / 2))
            {
                return it.first ;
            }
        }

        return -1 ;
        
    }
};