// Brute Force
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    bool mergedSomething = true;

    while (mergedSomething) {
        mergedSomething = false;

        for (int i = 0; i < intervals.size(); i++) {
            for (int j = i + 1; j < intervals.size(); j++) {

                int start1 = intervals[i][0];
                int end1 = intervals[i][1];
                int start2 = intervals[j][0];
                int end2 = intervals[j][1];

                // Overlap check
                if (end1 >= start2 && end2 >= start1) {

                    // Merge them
                    int newStart = min(start1, start2);
                    int newEnd = max(end1, end2);

                    // Replace interval i with merged interval
                    intervals[i] = {newStart, newEnd};

                    // Remove interval j
                    intervals.erase(intervals.begin() + j);

                    mergedSomething = true;
                    break;   // restart check because size changed
                }
            }
            if (mergedSomething) break;
        }
    }
    return intervals;
}

    
};
