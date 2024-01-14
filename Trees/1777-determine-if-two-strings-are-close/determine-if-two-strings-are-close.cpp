class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if(word1.length() != word2.length())
        {
            return false;
        }
        
        vector<int> mw1(26,0) , mw2(26,0) ;

        for(char ch : word1)
        {
            mw1[ch - 'a']++;
        }

        for(char ch : word2)
        {
            mw2[ch - 'a']++;
        }

        for(int i = 0 ; i < 26 ; i++)
        {
            if((mw1[i] == 0 && mw2[i] != 0) || (mw1[i] != 0 && mw2[i] == 0))
            {
                return false;
            }
        }

        //checking if we can swap
        sort(mw1.begin(),mw1.end());
        sort(mw2.begin(),mw2.end());

        return mw1 == mw2 ;
    }
};