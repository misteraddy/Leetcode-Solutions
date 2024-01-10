class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1.00000;

        if(n < 0)
        {
            x = 1 / x ;
        }

        n = abs(n);

        solve(x,n,ans);

        return ans ;
    }

    void solve(double x,int n,double& ans)
    {
        if(n == 0)
        {
            return;
        }

        if(n & 1)
        {
            ans = ans * x ;
        }

        x = x*x ;

        solve(x,n/2,ans);
    }
};