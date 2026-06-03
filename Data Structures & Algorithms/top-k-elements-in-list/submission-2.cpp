class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        // Step 1: Count frequencies
        for(int x : nums)
            freq[x]++;

        // Step 2: Move map data into a vector of pairs
        vector<pair<int,int>> v; // (num, freq)
        for(auto &p : freq)
            v.push_back(p);

        // Step 3: Sort by frequency (descending)
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        // Step 4: Take top k
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(v[i].first);
        }

        return res;
    }
};
