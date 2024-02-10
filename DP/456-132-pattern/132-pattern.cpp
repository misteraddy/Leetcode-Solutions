class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        stack<int> st ;
        
        int n = nums.size();

        //opposite direction loop issiliye chal raha
        //index wali condition ko fulfil karne k liye 

        int num3 = INT_MIN ;  //most suitable because 0 aur -1 bhi value aa rahi hai nums mei

        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(nums[i] < num3)
            {
                return true ;  //num2 is the largest element 
                //aur jab tak num2 nhi nikalaa tab tak num3 ki value nhi pata chali hogi
                //aur num3 hamesha num2 se chota hi rahega 
            }

            while(!st.empty() && nums[st.top()] < nums[i])
            {
                num3 = nums[st.top()];
                st.pop();
            }

            st.push(i);
        }

        //agar ek bhi baar true nhi aaya toh matlab uss pattern mei number exist hi nhi karte
        //sorting nhi karr rahe kyunki usse order change ho jaataa

        return false ;
    }
};