class Solution {
    public int longestConsecutive(int[] nums) {

        int no = 0 ;

        int long_large = 0 ;

        Set<Integer> s = new HashSet<>();
        
        for(int i = 0 ; i < nums.length ; i++)
        {
            s.add(nums[i]);
        }

        for(int i = 0 ; i < nums.length ; i++)
        {
            if(!s.contains(nums[i] - 1))
            {
                no = nums[i];

                while(s.contains(no))
                {
                    no++;
                }

                if(long_large < no - nums[i])
                {
                    long_large = no - nums[i];
                }
                
            }
        }

        return long_large;
    }
}