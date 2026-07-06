class Solution {
public:
    bool match(string &s, string &p, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;

        if (i >= 0 && j < 0)
            return false;

        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = match(s, p, i - 1, j - 1, dp);

        else if (p[j] == '*')
            return dp[i][j] = (match(s, p, i - 1, j, dp) ||
                               match(s, p, i, j - 1, dp));

        else
            return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return match(s, p, s.length() - 1, p.length() - 1, dp);
    }
};