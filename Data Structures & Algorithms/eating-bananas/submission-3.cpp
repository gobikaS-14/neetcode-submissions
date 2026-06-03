/*class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int n = p.size();
        int bana = 0;  //bananas-per-hour

        while (true) {
            bana++;          // try next speed
            long long hr = 0; // reset hours for this speed

            for (int i = 0; i < n; i++) {
                hr += ceil((double)p[i] / bana);

            }

            if (hr <= h) {
                return bana; // minimum speed found-bananas-per-hour
            }
        }
    }
};*/


class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int low = 1;
        int high = *max_element(p.begin(), p.end());

        while (low < high) {
            int mid =(low + high )/ 2;
            long long hr = 0;

            for (int i = 0; i < p.size(); i++) {
                 hr += ceil((double)p[i] /mid); // ceil
            }

            if (hr <= h)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
