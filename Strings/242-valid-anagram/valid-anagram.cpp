class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int mapping[300] = {0};
        
        
        //uss string ka ek frequency table bana rahe 
        //frequency table mei har character kitni baar repeat hua voh batate hai 
        for(int i = 0 ; i < s.length() ; i++)
        {
            //the s[i] is a character it will be explicity typecasted to integer
            mapping[s[i]]++ ;
            //characters value get incremented by one
        }
        
        
        //decrememt karte rahenge values ko 
        //agar strings anagram hai toh unki character ki mapping same hogi
        //aur mapping mei joh values store hai voh bhi same hongi 
        for(int j = 0 ; j < t.length() ; j++)
        {
            mapping[t[j]]-- ;
        }
        
        
        // then checking all the elements of the mapping array
        // if the strings are anagram then no mapping value will be left at the end
        for(int k = 0 ; k < 300 ; k++)
        {
            if(mapping[k] != 0)
            {
                return false ;
            }
        }
        
        return true ;
    }
};