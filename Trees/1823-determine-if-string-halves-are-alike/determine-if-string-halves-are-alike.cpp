class Solution {
public:
    
    bool halvesAreAlike(string s) {
        int cntLeft = 0, cntRight = 0;
        
        for (int i = 0; i < s.length()/2; i++) {
            if (isVowel(s[i]))
                cntLeft++;
        }
        
        for (int i = s.length()/2; i < s.length(); i++) {
            if (isVowel(s[i]))
                cntRight++;
        }
        
        return cntLeft == cntRight;
    }

private:
    
    bool isVowel(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
};
