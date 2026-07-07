class Solution {
public:
    int longestValidParentheses(string s) {

        int left = 0, right = 0;
        int maxlen = 0;

        // Left to Right
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right)
                maxlen = max(maxlen, 2 * right);

            else if (right > left)
                left = right = 0;
        }

        left = right = 0;

        // Right to Left
        for (int i = s.length() - 1; i >= 0; i--) {

            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right)
                maxlen = max(maxlen, 2 * left);

            else if (left > right)
                left = right = 0;
        }

        return maxlen;
    }
};