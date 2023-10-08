class Solution {
public:
    
    bool checkpalindrome(string s,int i , int j)
    {
       while(i <= j)
       {
            if(s[i] != s[j])
        {
            return false ;
        }
           else
           {
               i++;
                j--;
           }
        
         
          
       }
        
        return true ;
        
    }
    
    
    bool validPalindrome(string s) {
        int i = 0 ;
        int j = s.size() - 1 ;
        
        while(i <= j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                int ans1 = checkpalindrome(s,i+1,j);
                
                int ans2 = checkpalindrome(s,i,j-1);
                
                return ans1 || ans2 ;
            }
        }
        
        return true ;
    }
};