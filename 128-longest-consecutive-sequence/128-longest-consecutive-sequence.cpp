class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num : nums){
            s.insert(num);
        }
        
        int longestStreak = 0;
        for(auto num : nums){
            if(!s.count(num-1)){     //number lesser than num exists or not
                int currentNum = num;
                int currentStreak = 1;
                while(s.count(currentNum+1)){   //checking if next number exists or not
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};

/*
Pushing element in set + Iteration do over array + For while loop iteration
TC - O(N) + O(N) + O(N)    
SC - O(N)
*/




//OR (Brute Force)

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size() == 0){
//             return 0;
//         }
//         sort(nums.begin(), nums.end());
//         int count = 1, cnt = 1;
//         for(int i = 1; i < nums.size(); i++){
//             if(nums[i] != nums[i-1]){
//                 if(nums[i] == nums[i-1]+1){
//                     cnt++;
//                 }
//                 else{
//                     count = max(count,cnt);
//                     cnt = 1;
//                 }
//             }
//         }
        
//         return max(count,cnt);
//     }
// };

//TC - O(N logN) + O(N)


