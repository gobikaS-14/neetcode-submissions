class Solution {
public:
    int trap(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        int lmax=0,rmax=0;
        int tot=0;
        while(l<r){
        //if leftmax is lesser than or equal rightmax
        if(arr[l]<=arr[r] ){
            //rain trapped
            if(arr[l]<lmax) tot+=lmax-arr[l];
            else lmax=arr[l];
            l++;
        }
        //if rmax is lesser than lmax
        else{
            //rain trapped
            if(arr[r]<rmax) tot+=rmax-arr[r];
            else rmax=arr[r];
            r--;
        }
        }
        return tot;

    }
};
/*🧠 STEP 1: Read the question and identify the REAL task

“Trapping Rain Water” means:

For each index, water can be trapped if there are taller bars on BOTH sides.

So mentally convert:

height = [..]

into:

“Each index i needs left boundary + right boundary”

🧠 STEP 2: Write the brute force idea in your head

Ask:

👉 “How would I solve this directly?”

For each index i:

find max on left
find max on right
compute water

So you naturally get:

water[i] = min(leftMax[i], rightMax[i]) - height[i]
⚠️ STEP 3: Identify the problem with brute force

Now ask:

👉 “What is expensive here?”

Answer:

repeatedly finding leftMax → O(n)
repeatedly finding rightMax → O(n)

So total:

O(n²)

🧠 STEP 4: Key insight shift

Now the interview trick:

👉 “Can I reuse information instead of recomputing?”

So instead of recalculating leftMax/rightMax every time:

We try:

maintain them while scanning

🧠 STEP 5: Real breakthrough question

Now ask THIS (important):

👉 “Can I compute water for an index WITHOUT knowing full leftMax and rightMax in advance?”

Answer:

YES — if I know the limiting side

🧨 STEP 6: Key observation (MOST IMPORTANT)

Water depends on:

min(leftMax, rightMax)

So:

👉 The smaller side is the only one that matters

If I know:

left side is smaller → I don’t care about full right side
right side is smaller → I don’t care about full left side
🚀 STEP 7: Idea of two pointers is born

So instead of scanning per index:

We do:

l = 0
r = n-1

We try to “close in” from both sides.

🧠 STEP 8: Critical greedy decision

Now ask:

👉 “Which side should I process first?”

Answer:

We ALWAYS process the smaller side because:

smaller side is the bottleneck for water

So:

if (height[l] <= height[r]) process l
else process r
🧠 STEP 9: Why this works (core intuition)

Because:

water at an index is limited by the smaller boundary
once we know the smaller boundary, we can finalize it immediately

So we “lock” that index safely.

🔥 FINAL MENTAL MODEL (VERY IMPORTANT)

Instead of thinking:

❌ “compute water for every index”

Think:

✔ “keep eliminating the weaker boundary and finalize it immediately”

🧩 STEP 10: What you should say in interview

If interviewer asks “how did you get this idea?”

Say:

I first thought of computing leftMax and rightMax for each index, but that is O(n²).
Then I realized water depends on the smaller boundary.
So instead of fixing every index, I can use two pointers and always process the side with the smaller boundary, because that side determines the water level.
This lets me compute results in one pass.
essing the limiting side.
*/