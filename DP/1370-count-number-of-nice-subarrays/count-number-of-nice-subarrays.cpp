class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int ans = 0 ;

        int oddCount = 0 ;
        
        int start = 0 ;
        int end = 0 ;
        int prevCount = 0 ;

        int n = nums.size();

        while(end < n) {

            if(nums[end] & 1) {
                oddCount++;
                prevCount = 0 ;
            } 

            while(oddCount == k) {

                prevCount += 1 ;

               if(nums[start] & 1) {
                  oddCount--;
               }

               start ++;
            }

            ans += prevCount ;
            end++;
        }

        return ans ;
    }
};