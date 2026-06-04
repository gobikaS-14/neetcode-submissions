//optimal
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
            else
                low = mid + 1;//how answer is in low####3
                
        }
        return low;
    }
};
