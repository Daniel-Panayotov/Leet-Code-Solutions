int climbStairs(int n) {
    if (n == 1) return 1;

    int curr = 1, prev = 1;
    int tmp = 0;
    for (int i = 1; i < n; i++) {
        tmp = curr;
        curr += prev;
        prev = tmp;
        tmp = curr;
    }

    return tmp;
}
