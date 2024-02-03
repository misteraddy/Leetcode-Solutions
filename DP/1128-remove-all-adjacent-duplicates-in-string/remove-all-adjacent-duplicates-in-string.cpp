class Solution {
public:
    string removeDuplicates(string s) {
        
        string ans = "";

        for(int i = 0 ; i < s.size() ; i++)
        {
            char ch = s[i] ;
            if(ans.length() > 0 && ans.back() == ch)
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(ch);
            }
        }

        return ans ;
    }
};