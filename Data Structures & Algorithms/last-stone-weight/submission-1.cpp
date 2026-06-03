//brute force
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
// use stones.size(), not n as size varies after each iteration
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
             // Take last two elements (largest two)
            int max1= stones.back();
            stones.pop_back();//removes the last element(max1)
            int max2= stones.back();
            stones.pop_back();//remove    

            // Ifmax1==max2 both destroyed(0) → do nothing
            if(max1!=max2) stones.push_back(max1-max2);
            }
            //to handle output :0
        return stones.empty()? 0 : stones[0];

    }
};
