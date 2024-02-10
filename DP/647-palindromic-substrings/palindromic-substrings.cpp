class Solution {
public:

    int expand(string s,int i,int j)
    {
        int count = 0 ;

        while(i >= 0 && j < s.size() && s[i] == s[j])
        {
            i--;
            j++;
            count++;
        }

        return count ;
    }

    int countSubstrings(string s) {

        int total = 0 ;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            int j = i ;

            int oddKaAns = expand(s,i,j);

            j = i + 1 ;

            int evenKaAns = expand(s,i,j);

            total = oddKaAns + evenKaAns + total ;
        }

        return total ;
    }
};


//redefinition in the same scope is not allowed line 24 and line 28