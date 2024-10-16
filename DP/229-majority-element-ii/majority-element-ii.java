class Solution {
    public List<Integer> majorityElement(int[] nums) {
        
        Map<Integer,Integer> mp = new HashMap<>();

        List<Integer> ls = new ArrayList<>();

        int n = nums.length ;

        int mini = (int)(n / 3) + 1 ;

        for(int i = 0 ; i < n ; i++)
        {
            int value = mp.getOrDefault(nums[i],0);

            mp.put(nums[i],value + 1);

            if(mp.get(nums[i]) == mini)
            {
                ls.add(nums[i]);
            }

            if(ls.size() == 2) {
                break;
            }
        } 

        return ls ;
    }
}