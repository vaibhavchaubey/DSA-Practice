class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for(auto num : nums){
            if(count == 0){
                candidate = num;
            }
            if(num == candidate){
                count++;
            }
            else{
                count--;
            }
        }
        
        return candidate;
    }
};

//Moore’s Voting Algorithm
//Time Complexity: O(N)
//Space Complexity: O(1)



//OR

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> mp;
//         for(int i = 0; i < n; i++){
//             mp[nums[i]]++;
//             if(mp[nums[i]] > n/2){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };

// Time Complexity: O(N)-> Frequency array(We can use freq array if elements are in range to use) or O(NlogN) -> HashMap 
// Space Complexity: O(N)



//OR

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         return nums[n/2];         //It always return the majority element
//     }
// };

// Time complexity : O(NlogN)
// Space complexity : O(1)




// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             int cnt = 1;
//             for(int j = i+1; j < n; j++){
//                 if(nums[i] == nums[j]){
//                     cnt++;
//                 }
//             }
//             if(cnt > n/2){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };

// Time Complexity: O(N*N) 
// Space Complexity: O(1) 


