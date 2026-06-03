// Brute Force-Dry Run in the notepad named merge intervals
/*class Solution {
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
}; */


//optimal approach

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        
        int n=inter.size();
        vector<vector<int>> res;
        /*This lambda func[] takes two intervals(parameters), named a and b,
         passed by reference,and will compare them without modifying them*/
        sort(inter.begin(),inter.end(),[](const vector<int> &a,const vector<int> &b){
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];    
        }
        );

        // Always push the first interval
        res.push_back(inter[0]);
        for(int i=0;i<n;i++){
           int  start2 = inter[i][0] ;
           int end1 = res.back()[1];
           int end2=inter[i][1];

            // no overlap->just add them into res
            if(start2> end1){
                res.push_back(inter[i]);
            }

            else{//overlap
                //merge
                res.back()[1]= max(end1,end2);
            }
        }
        return res;
    }
};

