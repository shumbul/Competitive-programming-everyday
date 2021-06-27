// Link - https://leetcode.com/contest/weekly-contest-247/problems/number-of-wonderful-substrings/
// Author - Shumbul Arifa

// gives TLE for large inputs
// better approach - using Bit Masking
class Solution {
    long long solve(string s) {
        int n = s.length(), ans = 0;
        int ar[11];
        string t;
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                t = s.substr(i, i + len - 1);
                for (int i = 0; i < 11; i++) {
                    ar[i] = 0;
                }
                for (char c : t) {
                    ar[c - 'a']++;
                }
                int flag = 1;
                for (int i = 0; i < 11; i++) {
                    // cout << ar[i] << " ";
                    if (ar[i] % 2) {
                        if (flag == 0) {
                            flag = -1;
                            break;
                        }
                        flag = 0;
                    }
                }
                // if(flag)
                // cout << "\n" << t << " " << flag << "\n";
                cout << t << "\n";
                if (flag != -1)
                    ans++;
            }
        }
        return ans;
    }
public:
    long long wonderfulSubstrings(string word) {
        return solve(word);
    }
};


// TODO