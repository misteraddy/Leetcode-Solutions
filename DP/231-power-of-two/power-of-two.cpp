// reference https://leetcode.com/problems/power-of-two/solutions/1638704/c-easy-to-solve-all-interview-approaches-with-detailed-explanations


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return ((n&(n-1))==0);
    }
};