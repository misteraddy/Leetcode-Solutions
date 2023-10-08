
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the edge cases
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        
        if (divisor == 0) {
            return INT_MAX;
        }
        
        // Determine the sign of the result
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        // Convert both dividend and divisor to positive
        long long ldividend = abs(static_cast<long long>(dividend));
        long long ldivisor = abs(static_cast<long long>(divisor));
        
        long long result = 0;
        long long start = 0;
        long long end = ldividend;
        
        // Apply binary search
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            
            if (mid * ldivisor == ldividend) {
                return static_cast<int>(mid * sign);
            } else if (mid * ldivisor > ldividend) {
                end = mid - 1;
            } else {
                result = mid;
                start = mid + 1;
            }
        }
        
        result *= sign;
        
        if (result > INT_MAX) {
            return INT_MAX;
        }
        
        if (result < INT_MIN) {
            return INT_MIN;
        }
        
        return static_cast<int>(result);
    }
};
