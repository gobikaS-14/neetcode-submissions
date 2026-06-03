class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {

        int n = pos.size();

        // 🔹 FIX 1: keep position and speed together
        vector<pair<int,int>> cars;
        for(int i = 0; i < n; i++) {
            cars.push_back({pos[i], speed[i]});
        }

        // 🔹 FIX 2: sort by position
        sort(cars.begin(), cars.end());

        // 🔹 FIX 3: use double for time
        vector<double> time(n);
        for(int i = 0; i < n; i++) {
            time[i] = (double)(target - cars[i].first) / cars[i].second;
        }

        // 🔹 FIX 4: correct fleet counting logic
        int fleets = 0;
        double maxTime = 0;

        // traverse from last car
        for(int i = n - 1; i >= 0; i--) {
            if(time[i] > maxTime) {
                fleets++;
                maxTime = time[i];
            }
        }

        return fleets;
    }
};
