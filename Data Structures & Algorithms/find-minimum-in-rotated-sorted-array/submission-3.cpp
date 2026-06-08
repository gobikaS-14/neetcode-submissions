
/*
class Solution {
public:
    int findMin(vector<int> &arr) {
        int n=arr.size();
        int i;
        for(i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                break;
            }
        }
        if(i==n-1) return arr[0];
        return arr[i+1];
    }
};
*/

//https://youtu.be/bkJeA7LnJww

/*
👉 If nums[mid] > nums[right]

It means:

mid is in the left (bigger) sorted part
so the minimum is to the right

So we do:

left = mid + 1;
👉 Else (nums[mid] <= nums[right])

It means:

mid is in the right sorted part (or could be the minimum itself)
so minimum is at mid or left side

So we do:

right = mid;*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is greater than high,
            // minimum is in right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Otherwise, minimum is in left half (including mid)
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};