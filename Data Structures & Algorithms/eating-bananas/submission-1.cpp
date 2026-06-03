class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int n = p.size();
        int bana = 0;

        while (true) {
            bana++;          // try next speed
            long long hr = 0; // reset hours for this speed

            for (int i = 0; i < n; i++) {
                hr += ceil((double)p[i] / bana);

            }

            if (hr <= h) {
                return bana; // minimum speed found
            }
        }
    }
};
