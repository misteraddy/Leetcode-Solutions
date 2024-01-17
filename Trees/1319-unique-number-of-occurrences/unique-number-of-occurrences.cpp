class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int,int> mpp ;

        map<int,int> hash ;

        for(auto num : arr)
        {
            mpp[num]++;
        }

        for(auto [key,value] : mpp)
        {
            hash[value]++;
        }

        for(auto i : hash)
        {
            if(i.second > 1)
            {
                return false;
            }
        }

        return true;
        
    }
};