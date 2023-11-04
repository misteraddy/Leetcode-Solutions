class Solution {
public:
    
    // BRUTE FORCE APPROACH IS BY SOLVING FIRST FINDING ALL THE PERMUTATION POSSIBLE THEN
    //CHECKING FOR EACH ITERATION WHETHER THE CONDITION IS SATISFIED OR NOT 
    //BUT THE TIME COMPLEXITY FOR FINDING OUT THE ALL THE PERMUTATIONS IS
    //     O(N!)   WHICH IS VERY VERY BAD.
    
    void countArrangementHelper(int& n,vector<int>& perm,int& count,int currNum)
    {
        //Base Case When all the elements from 1 to n are placed and checked
        //index == n 
        //ye issiliye nhi kyunki n ko bhi place karne k baad check karna hai naa
        //n + 1 means all the elements are placed and checked.
        
        if(currNum == n + 1)
        {
            ++ count ;
            return ;
        }
        
        
        //har recursive step mei loop i = 1 se shuru ho rhaa 
        
        for(int i = 1 ; i <= n ; i++)
        {
            if(perm[i] == 0 && (i % currNum == 0 || currNum % i == 0))
            {
                perm[i] = currNum;
                
                //index = index + 1 ;
                
                countArrangementHelper(n,perm,count,currNum + 1);
                
                //backtracking hone 
                
                //index = index - 1 ;
                
                perm[i] = 0 ;
                
            }
        }
 
    }
    
    int countArrangement(int n) {
        
        int count = 0 ;
        
        
        //saare index joh vector k hai voh 0 se initialise hote hai . agar specify
        //nhi kiya gya hai toh
        
        vector <int> perm(n + 1);
        
        countArrangementHelper(n,perm,count,1);
        
        return count ;
    }
};