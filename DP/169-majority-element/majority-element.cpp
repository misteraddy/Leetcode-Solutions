class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        
        int cnt = 0 ;

        int ele = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            if(cnt == 0)
            {
                ele = nums[i];
                cnt++;
            }
            else
            {
                if(ele == nums[i])
                {
                    cnt++;
                }
                else
                {
                    cnt--;
                }
            }
        }

        //yaha pe verification required nhi hai but jiss question mei verify bhi karna padtaa hai 
        //usme ye bhi karte hai 

        cnt = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            if(ele == nums[i])
            {
                cnt++;
            }
        }

        if(cnt < n / 2)
        {
            return -1 ;
        }


        return ele ;
    }
};