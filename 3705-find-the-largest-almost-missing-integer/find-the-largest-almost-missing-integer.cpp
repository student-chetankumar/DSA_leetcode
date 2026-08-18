class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(51, 0);

        for (int i = 0; i <= n - k; i++) {
            vector<int> freq(51, 0);

            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            for (int x = 0; x <= 50; x++) {
                if (freq[x] > 0) {
                    count[x]++;
                }
            }
        }

        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1) {
                return x;
            }
        }

        return -1;
    }
};