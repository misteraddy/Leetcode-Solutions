class Solution {
public:
    
    bool isPrime(int num)
    {
        if (num <= 1)
            return false;
        
        // for 0 and 1 false will be returned 
        
        for(int i = 2 ; i <= sqrt(num) ; i++)
        {
            if(num % i == 0)  // checking if i is the divisor
            {
                return false ;
            }
        }
        
        return true ;   // if no divisor found then it is prime
    }
    
    int countPrimes(int n) {
        
        if (n <= 2)
            return 0;
        
        vector <bool> primes(n, true);
        
        int count = 0 ;
        
        int sqrtN = sqrt(n);
        
        for(int i = 2 ; i <= sqrtN ; i++)
        {
            // if the number is prime
            if(primes[i])
            {
                //then its multiple will not be prime
                //so make them false
                
                
//The loop starts with j set to i * i, which is the square of the current prime number. This is because any smaller multiple of i less than i * i would have already been marked as non-prime by the time we reach this point in the outer loop.
                
                
                // when we are incrementing j by i then
                // then it goes to all the range between i*i to n -1 
                
                for(int j = i * i; j < n; j += i) 
                {
                    primes[j] = false;
                }
            }
        }
        
        for(int i = 2 ; i < n ; i++)
        {
            if(primes[i])
            {
                count++;
            }
        }
        
        return count ;
    }
};
