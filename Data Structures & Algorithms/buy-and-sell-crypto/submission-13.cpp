class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();

        int maxFuture = arr[n - 1]; // best selling price seen from the right
        int maxProfit = 0;

        for (int buy = n - 2; buy >= 0; buy--) {
            maxProfit = max(maxProfit, maxFuture - arr[buy]);
            maxFuture = max(maxFuture, arr[buy]);
        }

        return maxProfit;
    }
};
/*At each index i:

You are asking:

“If I buy today, what is the best future sell price?”*/