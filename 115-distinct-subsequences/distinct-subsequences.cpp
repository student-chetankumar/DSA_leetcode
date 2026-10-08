class Solution {
public:

    long long solve(string &s, string &t, int i, int j,
                    vector<vector<long long>> &dp) {

        // t is completely formed
        if (j == t.length())
            return 1;

        // s finished but t is not
        if (i == s.length())
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (s[i] == t[j]) {

            // Take + Skip
            dp[i][j] = solve(s, t, i + 1, j + 1, dp)
                     + solve(s, t, i + 1, j, dp);
        }

        // Characters don't match
        else {

            // Skip s[i]
            dp[i][j] = solve(s, t, i + 1, j, dp);
        }

        return dp[i][j];
    }

    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();

        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return solve(s, t, 0, 0, dp);
    }
};