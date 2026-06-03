class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;

        // XOR of all numbers from 0 to n
        for(int i = 0; i <= n; i++) {
            xor1 ^= i;
        }

        // XOR of all elements in array
        for(int num : nums) {
            xor2 ^= num;
        }

        // missing number
        return xor1 ^ xor2;
    }
};