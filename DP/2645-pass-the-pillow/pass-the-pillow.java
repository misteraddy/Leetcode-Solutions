class Solution {
    public int passThePillow(int n, int time) {
        
        int rounds = time / (n - 1);

        int timeLeft = time % (n - 1);

        if((rounds & 1) == 1)
        {
            return n - timeLeft ;
        }
        else
        {
            return timeLeft + 1 ;
        }
    }
}