/*
You are given a 0-indexed array of positive integers nums.

A subarray of nums is called incremovable if nums becomes strictly increasing on removing the subarray. For example, the subarray [3, 4] is an incremovable subarray of [5, 3, 4, 6, 7] because removing this subarray changes the array [5, 3, 4, 6, 7] to [5, 6, 7] which is strictly increasing.

Return the total number of incremovable subarrays of nums.

Note that an empty array is considered strictly increasing.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 10
Explanation: The 10 incremovable subarrays are: [1], [2], [3], [4], [1,2], [2,3], [3,4], [1,2,3], [2,3,4], and [1,2,3,4], because on removing any one of these subarrays nums becomes strictly increasing. Note that you cannot select an empty subarray.
*/


//brute approch
class Solution {
private:
   bool isIncreasingSubarray(vector<int>& nums, int start, int end){
    int prev = 0;

    for(int i=0;i<nums.size();i++){
        if(i <= end && i >= start){
            continue;
        }

        if(nums[i] <= prev) return false;

        prev=nums[i];
    }
    return true;
   }

public:
    int incremovableSubarrayCount(vector<int>& nums) {
    int cnt = 0;
    for(int i = 0; i < nums.size(); ++i){
        for(int j = i; j < nums.size(); ++j){
            
            if(isIncreasingSubarray(nums,i,j)) cnt++;
        }
    }
    return cnt;
}   
};
//TC = O(N3);
//TC = O(1);


class Solution {
    public long incremovableSubarrayCount(int[] nums) {
        int n = nums.length;
        if(n == 1) return 1;
        if(n == 2) {
            return 3;
        }
        
        long ans = 1; // removing all would be a solution

        // left increasing
        int left = 0;
        while(left < n-1 && nums[left] < nums[left+1]) {
            left++;
        }
        ans += left + 1l;
        
        // right increasing
        int right = n-1;
        while(right > 0 && nums[right-1] < nums[right]) {
            right--;
        }
        ans += n - right;
            
        // if all are increasing
        if(left >= right) {
            return ((n)*(n+1))/2l;
        }

        left = 0;
        // middle handling
        while(left < right && right < n) {
            if(nums[left] < nums[right]) {
                ans += right == n-1 ? 1l : (long)(n-right);
                if(left < n-1 && nums[left] < nums[left+1])
                    left++;
                else 
                    break;
            } else {
                right++;
            }
        }
        
        return ans;
    }
}
//TC = O(N);
//SC = O(1);

