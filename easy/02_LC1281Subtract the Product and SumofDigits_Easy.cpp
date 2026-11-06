class Solution {
public:
    int subtractProductAndSum(int n) {
        int digit_sum = 0;
        int digit_product = 1;
        
        while (n > 0) {
            int digit = n % 10;
            digit_sum += digit;
            digit_product *= digit;
            n /= 10;
        }
        
        return digit_product - digit_sum;
    }
};
