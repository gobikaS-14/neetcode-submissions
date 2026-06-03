//brute force
/*
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n= arr.size();
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            int j=i;
            while(j<n){
                if(arr[j]<=arr[i]) j++;
                else{
                    res[i]=j-i;
                    break;
                }

            }
        }
        return res;
    }
};*/

//optimal
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n= arr.size();
        stack<int>s;
        vector<int>res(n,0);
        for(int i=0;i<n;i++){          
            while(!s.empty() && arr[s.top()]<arr[i]){
              int last=  s.top();
              s.pop();
              res[last]=i-last;
            }
            s.push(i);
        }

        return res;
    }
};
