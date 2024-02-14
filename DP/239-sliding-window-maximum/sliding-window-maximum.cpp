class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans ;

        priority_queue<pair<int,int>> maxheap ;
        
        for(int i = 0 ; i <= k - 1 ; i++)  // <= nhi pehle < kar rahe the 
        {
            maxheap.push({nums[i],i});
        }

        ans.push_back(maxheap.top().first);

        for(int i = k ; i < nums.size() ; i++)
        {
            maxheap.push({nums[i],i});

            while(!maxheap.empty() && maxheap.top().second <= i - k) // also not checking 
            //ki pehle se empty toh nhi hai 
            {
                maxheap.pop();
            }

            ans.push_back(maxheap.top().first);
        }

        return ans;
    }
};
