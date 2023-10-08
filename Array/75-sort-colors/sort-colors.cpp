class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0 ;
        
        int index = 0 ;
        
        int right = nums.size() - 1 ;
        
        while(index <= right)
        {
            if(nums[index] == 0)
            {
                swap(nums[index],nums[left]);
                index ++ ;
                left ++ ;
            }
            else if(nums[index] == 2)
            {
                swap(nums[index],nums[right]);
                right --;
            }
            else
            {
                index ++ ;
            }
        }
    }
    
    //here we are using the two pointers approach 
    //we are not incrementing the index in the else if condition because
    //the number which is coming after being swapped is may be 0 , 1 or even 2 .
    //so we will again check whether it is 0,1,2 according to it execute the condtion
    // in the if condtion we are incrementing is 0 and 1 only 
    //agar 2 aayega toh else if waali condition lagegi
};