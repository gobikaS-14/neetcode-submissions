//optimal
/*You use low < high here because:
🔥 We are not finding a specific index — we are converging to the minimum valid answer safely without overshooting.
❌ low <= high
“I must check every candidate one by one”
✅ low < high
“I am shrinking a range until it becomes a single answer”*/

class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int low = 1;
        int high = *max_element(p.begin(), p.end());

        while (low < high) {
            int mid =(low + high )/ 2;
            int hr = 0;

            for (int i = 0; i < p.size(); i++) {
                 hr += ceil((double)p[i] /mid); // ceil
            }

            if (hr <= h)
                high = mid;
            else   //try min speed possible
                low = mid + 1;//how answer is in low####3
                
        }
        return high;//(answer will be at low or high both points to same at last)
    }
};
