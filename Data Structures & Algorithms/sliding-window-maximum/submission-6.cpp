/*brute force
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<=n-k;i++){
            int maxi=INT_MIN;
            for(int j=i;j<i+k;j++){
                if(nums[j]>maxi) maxi=nums[j];
            }
            res.push_back(maxi);
        }
        return res;
    }
};
*/



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;   // stores indices

        for (int i = 0; i < n; i++) {
           // Every time we move the window one step right, the window “ends” at i.
            
            if(!dq.empty()&& dq.front()==i-k)   dq.pop_front();

            while(!dq.empty() && nums[dq.back()]<=nums[i])  dq.pop_back();

            dq.push_back(i);

            if(i>=k-1)  ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
