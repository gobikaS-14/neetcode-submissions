//Prefix minimum + best difference
/*Ask this:

“If I am standing at day j (sell day), what is the BEST buy before it?”
*/
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        int n=arr.size();

        for (int sell=1;sell<n;sell++) {
            minPrice = min(minPrice, arr[sell-1]);//buy=arr[sell-1]
            maxProfit = max(maxProfit, arr[sell]- minPrice);
        }

        return maxProfit;
    }
};