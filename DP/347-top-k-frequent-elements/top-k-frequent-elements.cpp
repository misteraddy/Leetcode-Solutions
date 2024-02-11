#if 0

class compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second; // Fix the comparison logic
    }
};

//custom comparator banana nhi padtaa agar hum log first element mei count ko rakhte toh

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ans;

        unordered_map<int, int> mpp;

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        for (int i = 0; i < nums.size(); i++) {
            int element = nums[i];
            mpp[element]++;
        }

        //but this is not space optimised as we are using the n size heap 

        //optimised will be the case when we create the heap of k size 

        for (auto i : mpp) {
            pair<int, int> element;
            element.first = i.first;
            element.second = i.second;
            pq.push(element);
        }

        for (int i = 0; i < k; i++) {
            pair<int, int> element = pq.top();
            pq.pop();
            ans.push_back(element.first); // Push the element instead of the pair
        }

        return ans; // Return the result vector
    }
};

#endif

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int,int> mpp ;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;

        for(auto num : nums)
        {
            mpp[num]++;
        }

        for(auto [p,q] : mpp)
        {
            pq.push({q,p});  

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> ans ;

        while(!pq.empty())
        {
            pair<int,int> p = pq.top() ; pq.pop() ;

            ans.push_back(p.second);
        }

        return ans ;
    }
};


/*

error ::  for(auto it = mpp.begin() ; it != mpp.end() ; it++)
            {
                pq.push({it.second,it.first});  


error ::  for(auto [p,q] : mpp)
            {
                pq.push({q,p}); 
he error in the provided code is in the declaration of the priority queue.
 In the line priority_queue<pair<int,int>,vector<pair<int,int>>,greater<int>> pq ;
 , greater<int> is incorrectly used as the comparator,
  but it should be greater<pair<int,int>> because the priority queue contains pairs of integers.


*/
