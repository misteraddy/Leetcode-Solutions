class Solution {

    public int missingNumber(int[] nums) {
        
        int xor1 = 0 ;

        int xor2 = 0 ;

        int n = nums.length ;

        for(int i = 0 ; i < n ; i++)
        {
            xor1 = xor1 ^ nums[i];
        }

        for(int i = 0 ; i <= n ; i++)
        {
            xor2 = xor2 ^ i ;
        }

        return xor2 ^ xor1 ;
    }

    
}