class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {

        if(numExchange > numBottles)
        {
            return numBottles ;
        }
        
        int result = numBottles ;

        int temp = numBottles ;

        while(temp >= numExchange)
        {
            int againFilled = (temp / numExchange) ;

            result += againFilled ;

            temp = againFilled + (temp % numExchange) ;
        }

        return result ;
    }
}