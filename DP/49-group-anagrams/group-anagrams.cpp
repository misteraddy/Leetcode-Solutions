class Solution {
public:

    array<int,256> hash(string s)
    {
        array<int,256> hash = {0};

        for(int i = 0 ; i < s.size() ; i++)
        {
            hash[s[i]]++;
        }

        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<array<int,256>,vector<string>> mpp ;

        for(string sr : strs)
        {
            array<int,256> key = hash(sr);
            mpp[key].push_back(sr);
        }

        vector<vector<string>> ans ;

        for(auto it = mpp.begin() ; it != mpp.end() ; it++)
        {
            ans.push_back(it -> second);
        }

        return ans;
    }
};