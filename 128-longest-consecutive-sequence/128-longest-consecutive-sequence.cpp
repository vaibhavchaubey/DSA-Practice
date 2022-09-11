class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int longestStreak = 1; 
        int prev = nums[0];
        int currentStreak = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == prev+1){
                currentStreak++;
            }
            else if(nums[i] != prev){
                currentStreak = 1;
            }
            prev = nums[i];
            longestStreak = max(longestStreak,currentStreak);
        }
        
        return longestStreak;
    }
};

//Time Complexity: O(NlogN) + O(N)
//Space Complexity: O(1)