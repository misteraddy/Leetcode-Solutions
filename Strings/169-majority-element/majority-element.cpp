class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        // when we sort as the number of the majority element is more than n/2 then majority 
        //element will always come on the mid 
        
        return nums[(0 + nums.size() - 1) / 2] ;
    }
};


// example [3,4,4,4,4,1,2] so when we sort
// [1,2,3,4,4,4,4] we can observe that the mid element contain the majority element