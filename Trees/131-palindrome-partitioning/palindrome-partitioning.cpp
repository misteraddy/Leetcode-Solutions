class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;

        vector<string> temp;

        findpartition(s, ans, 0, temp);
        
        return ans;
    }

    void findpartition(string s, vector<vector<string>>& ans, int start, vector<string>& temp)
    {
        if (start == s.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < s.size(); i++)
        {
            if (isPalindrome(s, start, i))
            {
                temp.push_back(s.substr(start, i - start + 1));
                findpartition(s, ans, i + 1, temp);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }

        return true;
    }
};
