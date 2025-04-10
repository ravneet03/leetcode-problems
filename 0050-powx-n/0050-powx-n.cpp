class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n < 0) {
            x = 1 / x;
            if (n == INT_MIN) { 
                n += 1; 
                return x * myPow(x, -n);
            }
            n = -n;
        }

        double half = myPow(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }
};
