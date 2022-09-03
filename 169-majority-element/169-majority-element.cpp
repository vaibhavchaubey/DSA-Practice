class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];         //It always return the majority element
    }
};

//Time complexity : O(NlogN)
//Space complexity : O(1)