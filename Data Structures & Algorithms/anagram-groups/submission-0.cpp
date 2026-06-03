class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;

        for(string s:strs){
                vector<int> count(26,0);
                for(char c:s){
                    count[c-'a']++;
                }
                
                string key;
                for(int num:count){
                    key += to_string(num)+"#";
                }
                map[key].push_back(s);        
        }
        vector<vector<string>> res;
        for(auto& pair :map){
            res.push_back(pair.second);

        }
        return res;
    }
};
