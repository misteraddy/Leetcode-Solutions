class Solution {
public:
    string removeDuplicateLetters(string s) {

        int n = s.size() ;
        
        string result ;

        vector<bool> taken(26,false);

        vector<int> lastIndex(26);

        for(int i = 0 ; i < n ; i++)
        {
            char ch = s[i];

            lastIndex[ch - 'a'] = i;
        }

        for(int i = 0 ; i < n ; i++)
        {
            char ch = s[i];

            int idx = ch - 'a';

            if(taken[idx] == true)
            {
                continue ;
            }

            //here got the error that && lastIndex[result.back()
            //fix :: lastIndex[result.back() - 'a'] 

            while(!result.empty() && result.back() > ch && lastIndex[result.back() - 'a'] > i)
            {
                taken[result.back() - 'a'] = false ;
                result.pop_back(); 
            }
            
            result.push_back(ch);
            taken[idx] = true ;
            
        }

        return result ;
    }
};