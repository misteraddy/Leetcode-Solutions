class Solution {
    public List<Integer> majorityElement(int[] nums) {

        int n = nums.length ;

        List<Integer> ans = new ArrayList<>();
        
        int e1 = 0 , e2 = 0 ;

        int cnt1 = 0 , cnt2 = 0 ;

        for(int i = 0 ; i < nums.length ; i++)
        {

            if(cnt1 == 0 && nums[i] != e2)
            {
                e1 = nums[i];
                cnt1 = 1 ;
            } else if(cnt2 == 0 && nums[i] != e1)
            {
                e2 = nums[i];
                cnt2 = 1 ;
            } else if(nums[i] == e1)
            {
                cnt1++;
            } else if(nums[i] == e2)
            {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0 ; cnt2 = 0 ;

        for(int i = 0 ; i < nums.length ; i++)
        {
            if(nums[i] == e1)
            {
                cnt1++;
            }

            if(nums[i] == e2)
            {
                cnt2++;
            }
        }

        int mini = (int)(n / 3) + 1 ;

        if(e1 == e2)
        {
            if(cnt1 >= mini)
            {
                ans.add(e1);
            }

        } else {

            if(cnt1 >= mini)
            {
                ans.add(e1);
            }

            if(cnt2 >= mini)
            {
                ans.add(e2);
            }
        }

        return ans ;
    }
}