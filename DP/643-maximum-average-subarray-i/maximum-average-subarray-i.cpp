class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();
        
        double sum = 0 ;

        double curr_avg = 0 ;

        for(int i = 0 ; i < k ; i++) {

             sum += nums[i];
        }

        curr_avg = sum / k ;

        double max_avg = curr_avg ;

        int i = 0 ;

        int j = k ;

        while(j < n) {

            sum += nums[j] ;
            sum -= nums[i] ;

            curr_avg = sum / k ;

            max_avg = max(max_avg,curr_avg) ;

            i++;
            j++;
        }

        return max_avg ;
    }
};