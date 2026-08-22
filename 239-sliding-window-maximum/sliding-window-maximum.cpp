class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        // Process first window
        for (int index = 0; index < k; index++) {
            
            while (!dq.empty() && nums[dq.back()] < nums[index]) {
                dq.pop_back();
            }

            dq.push_back(index);
        }

        // Answer for first window
        ans.push_back(nums[dq.front()]);

        // Process remaining windows
        for (int i = k; i < nums.size(); i++) {

            // Remove element which is outside the window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Maximum element of current window
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};