/*
Approach -> Using Recursion, 
Time Complexity -> O(logN),
Space Complexity -> O(logN)
power function is optimised version of pow,  by breaking into the part of power and base so that calculations can be done in O(logN)
*/

class Solution {
public:
    // double pow(double base, long long power){    // FUNCTION WITHOUT USING RECURSION
    //     double ans = 1;
    //     while(power > 0){
    //         if(power % 2 == 1){
    //             ans = ans*base;
    //             power--;
    //         }else{
    //             base = base*base;
    //             power = power/2;
    //         }
    //     }
    //     return ans;
    // }

    double pow(double base, long long power){           // power function using recursion
        if(power == 0) return 1;

        double half = pow(base, power/2);
        if(power % 2 == 0){
            return half * half;
        }else{
            return base*half*half;
        }
    }

    double myPow(double x, int n) {
    //    long long N = abs(n);         // this will give error bcz n is limited range
        long long N = n;
        if(n < 0){
            N = -N;
        }
        double ans = pow(x,N);
        if(n < 0){
            return 1/ans;
        }else{
            return ans;
        }
    }
};