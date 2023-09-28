class Solution {
public:
    string intToRoman(int num) {
        
        string ans ;
        
        //list of roman symbols that existed 
        //this contain the exceptions too like 4 , 9 , 40 ,90 , 400 , 900
        //we follow different pattern in these numbers so we included them 
        string romansymbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        //corresponding integers the integers and roman numbers at the same index are equivalent
        int number[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        for(int i = 0 ; i < 13 ; i++)
        {
            
            //we move from largest to smallest until the condition is satisfied
            while(num >= number[i])
            {
                //add the largest possible which is nearest to the number
                ans += romansymbols[i];
                num -= number[i]; 
                //also subtract it from num in order to get the next suitable symbol
            }
        }
        
        return ans ;
    }
};