class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int> smp(26,0) , tmp(26,0) ;

        int ans = 0 ;

        for(auto ch : s)
        {
            smp[ch - 'a']++;
        }

        for(auto ch : t)
        {
            tmp[ch - 'a']++;
        }

        for(int i = 0 ; i < 26 ; i++)
        {
            if(smp[i] > tmp[i])
            {
                ans += smp[i] - tmp[i];
            }
        }

        return ans ;
    }
};