class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        //use the two pointer approach to solve the problem 
        //use the if condition to deal with the case when you get non alphabetic character
        
        
        // isalpha -> it is the predefined function used to check whether the given character is alphabetic or not .
        
        int i = 0 ;
        
        int j = s.size() - 1 ;
        
        while(i <= j)
        {
            
            if(isalpha(s[i]) && isalpha(s[j]))
               {
                   swap(s[i],s[j]);
                    i++;
                    j--;
               }
            else if(!isalpha(s[i]))
            {
                // when at the ith index non alphabetic character is present
                i++;
            }
            else
            {
                //when at the jth index non alphabetic character is present
                j--;
            }
        }
        
        return s ;
    }
};