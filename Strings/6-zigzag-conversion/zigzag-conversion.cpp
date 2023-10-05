class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
        {
            return s;
        }
        //2D string banayene
        
        vector <string> zigzag(numRows);
        
        //i for iterating the original string
        
        int i = 0 , row = 0 ; 
        
        bool direction = 1 ;
        
        //1 for top to bottom 
        //0 for bottom to top 
        
        while(true)
        {
            if(direction)
            {
                while(row < numRows && i < s.size())
                {
                    zigzag[row++].push_back(s[i++]);
                }
                
                row = numRows - 2 ;
                
            }
            else
            {
                while(row >= 0 && i < s.size())
                {
                    zigzag[row--].push_back(s[i++]);
                }
                
                row = 1 ;
            }
            
            
            
            //jab saari rows ko traverse ek direction mei traverse kar le then direction change kar le rahe hai .
            
            if(i >= s.size()) break ;
            
            direction = !direction ;
            
            
            //for coming out of the infinite loop
        }
        
        string ans ="";
        
        
        // by default 2D array ko 1D array mei print karenge toh by default row wise printing hogi
        
        for(int i = 0 ; i < zigzag.size() ; i++)
        {
            ans += zigzag[i];
        }
        
        
        return ans ;
    }
};