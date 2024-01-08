class compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second; // Fix the comparison logic
    }
};

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
