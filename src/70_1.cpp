#include <cmath>

//overflows if x too high
unsigned long long factorial(int x) {
    unsigned long long y = 1;

    for (int i = x; i > 1; i--) y *= i;

    return y;
}

int climbStairs(double n) {
    int count = 0;
    for (int x = ceil(n / 2); x <= n; x++) {
        int n1 = n - x;
        int n2 = n - n1 * 2;

        if (n1 == 0 || n2 == 0) { count++; continue; }
        if (n1 == 1 || n2 == 1) { count += x; continue; }


        count += factorial(x) / (factorial(n1) * factorial(n2));
    }

    return count;
}
