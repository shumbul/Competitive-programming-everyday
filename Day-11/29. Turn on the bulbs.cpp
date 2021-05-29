// Link - https://www.interviewbit.com/test/abb1acef38/
// Author - Shumbul Arifa

int Solution::solve(int n) {
    if (n == 0)
        return 0;
    int ans;
    if (n % 6 == 1)
        ans = (n / 6 + 1) * 2 - 1;
    else if (n % 6 == 0)
        ans = n / 6 * 2;
    else
        ans = (n / 6 + 1) * 2;
    return ans;
}