class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int freq[n + 1];
        for(int i = 0; i < n + 1; i++){
            freq[i] = 0;
        }
        
        for(int i = 0; i < n; i++){
            if(freq[nums[i]] == 0){
                freq[nums[i]]++;
            }
            else{
                return nums[i];
            }
        }
        return -1;
    }
};

//Time Complexity:O(N)
//Space Complexity:O(N)


//OR
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for(int i = 0; i < n - 1; i++){
//             if(nums[i] == nums[i + 1]){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };

//Time Complexity:O(NlogN + N)
//Space Complexity:O(1)