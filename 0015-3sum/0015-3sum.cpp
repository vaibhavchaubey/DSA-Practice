class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int lo = i+1, hi = nums.size()-1;
            while(lo < hi){
                int current = nums[i] + nums[lo] + nums[hi];
                if(current == 0){
                    ans.push_back(vector<int>{nums[i],nums[lo],nums[hi]});
                    while (lo+1 < hi && nums[lo] == nums[lo + 1]) lo++;
                    while (lo < hi-1 && nums[hi] == nums[hi - 1]) hi--;
                    lo++; hi--;
                }
                else if(current < 0){
                    lo++;
                }
                else{
                    hi--;
                }
            }
        }
        return ans;
    }
};