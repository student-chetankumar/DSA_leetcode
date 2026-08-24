class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        
        int s = 0, e = nums.size() - 1;
        int count = 0;

        while (s < e) {

            // If both sides are already correct
            if (nums[s] != 0) {
                s++;
            }
            else if (nums[e] == 0) {
                e--;
            }
            // Wrong element at left and correct element at right
            else {
                swap(nums[s], nums[e]);
                count++;
                s++;
                e--;
            }
        }

        return count;
    }
};