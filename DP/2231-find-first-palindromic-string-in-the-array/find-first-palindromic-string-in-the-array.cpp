class Solution {
public:
    bool check(string s)
    {
        int start=0;
        int end=s.length()-1;
        while(start<end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) 
    {
        for(int i=0;i<words.size();i++)
        {
            if(check(words[i]))
                return words[i];
        }
        return "";
    }
};