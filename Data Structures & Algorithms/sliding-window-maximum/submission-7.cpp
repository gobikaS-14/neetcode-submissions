class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
        int n = nums.size();
        deque<int> dq; // stores indices
        vector<int> result;

        // Step 1: process first k elements
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // first window max
        result.push_back(nums[dq.front()]);

        // Step 2: process remaining elements
        for (int i = k; i < n; i++) {

            // remove out-of-window indices
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // front is max
            result.push_back(nums[dq.front()]);
        }

        return result;
    }
};
    

