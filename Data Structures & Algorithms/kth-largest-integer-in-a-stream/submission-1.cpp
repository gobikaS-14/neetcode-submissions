class KthLargest {
public:
    vector<int> nums;
    int k;
    priority_queue <int> pq;

    KthLargest(int k, vector<int>& nums) {
        //copy input nums,k into object's nums,k
        this->k=k;
        this->nums=nums;
        for(int x: nums){
            pq.push(x);
        }
    }
    
    int add(int val) {  
        pq.push(val);

      priority_queue<int> temp = pq;

        for (int i = 1; i < k; i++) {
            temp.pop();
        }

        return temp.top();
    }
};
