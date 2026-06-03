//brute force yet to study optimal-here in teh solution tab
/*class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<pair<int, int>> arr;
        for (const auto& p : count) {
            arr.push_back(p);//p-pair
        }
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
    return a.second > b.second;   // sort by frequency DESC
});


        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].first);
        }
        return res;
    }
};*/

//optimal

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num: nums){
            map[num]++;
        }

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;

        for(auto&p:map){
            heap.push({p.second,p.first});
            if(heap.size()>k) heap.pop();
        }

        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(heap.top().second);
            heap.pop();

        }
        return res;
    }
};