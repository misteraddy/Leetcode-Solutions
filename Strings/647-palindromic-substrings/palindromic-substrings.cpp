class Solution {
public:
    
    int expand(string s,int i ,int j)
    {
        int count = 0 ;
        while(i >= 0 && i < s.length() && s[i] == s[j])
        {
            count ++ ;
            i--;
//             i = i - 1 issilye kyunki right to left jayega 
            j++;
//             aur ye left to right jayega 
//             ye iss liye kar rahe kyunki isse har case cover ho jayegaa i++ j-- karne pe har case cover nhi hoga
        }
        
        return count ;
//         count is the number of substring .
    }
    
    int countSubstrings(string s) {
        
        int total = 0 ;
        
        for(int i = 0 ; i < s.length() ; i++)
        {
            int j = i ;
//             the other pointer in case of odd mei i and j pointer are at the same place.
//             kynnki ek case aisaa hai jisme i aur j same place pe honge .
            int oddAns = expand(s,i,j);
//             number of substring in case of odd .
            
            j = i + 1 ;
//             the value of other pointer in case of even j pointer 1 jyadaa 
            int evenAns = expand(s,i,j);
//             number of subsring in case of even 
            
            total = oddAns + evenAns + total ;
//             it gives the total number of substrings 
        }
        
        return total;
    }
};