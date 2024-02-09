class Solution {
public:

#if 0 

    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        
        vector<int> result ;

        int n = nums.size();

        vector<int> temp ;

        solve(0,nums,result,temp,-1);

        return result ;
    }

    void solve(int index,vector<int>& nums,vector<int>& result,vector<int>& temp,int prev)
    {
        if(index >= nums.size())
        {
            if(temp.size() > result.size())
            {
                result = temp ;
            }
            return ;
        }

        if(prev == (-1) || nums[index] % prev == 0)
        {
            temp.push_back(nums[index]);
            solve(index + 1,nums,result,temp,nums[index]);   //nums[prev]
             //jab koi data structure by reference pass kiye ho 
            //toh recursion mei ye duty hai
            //ki return to parent function aane pe undo kar de 
            temp.pop_back();
        }

        solve(index + 1,nums,result,temp,prev);
    }

#endif

   vector<int> largestDivisibleSubset(vector<int>& nums)  {
    // Sort the input vector in ascending order
    sort(nums.begin(), nums.end());

    // Initialize a vector t with size equal to the size of nums, all elements are initialized to 1
    int n = nums.size();
    vector<int> t(n, 1);

    // Initialize a vector prev_index with size equal to the size of nums, all elements are initialized to -1
    vector<int> prev_index(n, -1);

    // Initialize variables to keep track of the last chosen index and the maximum length of the subset
    int last_chosen_index = 0;
    int maxL = 1;

    // Loop over each element in nums
    for (int i = 0; i < n; i++) {
        // Loop over each element before the current element
        for (int j = 0; j < i; j++) {
            // Check if nums[i] is divisible by nums[j]
            if (nums[i] % nums[j] == 0) {
                // Update the length of the subset ending at index i if necessary
                if (t[i] < t[j] + 1) {
                    t[i] = t[j] + 1;
                    prev_index[i] = j;
                }

                // Update the maximum length and the last chosen index if necessary
                if (t[i] > maxL) {
                    maxL = t[i];
                    last_chosen_index = i;
                }
            }
        }
    }

    // Reconstruct the largest divisible subset using the previous indices
    vector<int> result;
    while (last_chosen_index >= 0) {
        result.push_back(nums[last_chosen_index]);
        last_chosen_index = prev_index[last_chosen_index];
    }

    // Return the largest divisible subset
    return result;
}

};