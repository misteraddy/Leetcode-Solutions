class Solution {
public:
    
    // this is the function which tells whether the character is a vowel or not
    bool isVowel(char ch)
    {
        string vowel = "AEIOUaeiou";
        
        int index = vowel.find(ch);
        
        if (index != string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    string reverseVowels(string s) {
        int i = 0 ;
        int j = s.size() - 1 ;
        
        while (i <= j)
        {
            if (isVowel(s[i]) && isVowel(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (!isVowel(s[i]))
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return s ;
    }
};
