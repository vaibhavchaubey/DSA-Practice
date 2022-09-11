class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        unordered_set<int> s;
        for(auto num : nums){
            s.insert(num);
        }
        
        int longestStreak = 1; 
        for(auto num : nums){
            if(!s.count(num-1)){        //number lesser than num exists or not
                int currentNum = num;
                int currentStreak = 1;
                while(s.count(currentNum + 1)){    //checking if next consecutive number exists or not
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak,currentStreak);
            }
        }    
        
        return longestStreak;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)



//OR
/* Solution 1: (Brute force)  (Sorting)
Time Complexity: O(NlogN)
Space Complexity: O(1)
*/

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
        // if(nums.size() == 0){
        //     return 0;
        // }
//         sort(nums.begin(), nums.end());
//         int longestStreak = 1; 
//         int prev = nums[0];
//         int currentStreak = 1;

//         for(int i = 1; i < nums.size(); i++){
//             if(nums[i] == prev+1){
//                 currentStreak++;
//             }
//             else if(nums[i] != prev){
//                 currentStreak = 1;
//             }
//             prev = nums[i];
//             longestStreak = max(longestStreak,currentStreak);
//         }
        
//         return longestStreak;
//     }
// };