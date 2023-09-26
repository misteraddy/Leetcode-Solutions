class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
//         empty string declaration issi mei values ko push karenge aur check karte rahenge ki joh element aa raha hai voh rightmost element of the string k barabar toh nhi hai .
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(ans.length() > 0  && ans[ans.length() - 1] == s[i])
            {
                ans.pop_back();
//                 agar same hua toh pop kar diya uss element . equal adjacent pairs hat gye.
            }
            else
            {
                ans.push_back(s[i]);
//                 not same adjacent one then pushing into the string
            }
        }
        
        return ans ;
    }
};