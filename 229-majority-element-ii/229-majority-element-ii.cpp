class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == num1){
                count1++;
            }
            else if(nums[i] == num2){
                count2++;
            }
            else if(count1 == 0){
                num1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        count1 = count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == num1){
                count1++;
            }
            else if(nums[i] == num2){
                count2++;
            }
        }
        
        if(count1 > n/3){
            ans.push_back(num1);
        }
        if(count2 > n/3){
            ans.push_back(num2);
        }
        
        return ans;
    }
};

//Extended Boyer Moore’s Voting Algorithm
//Time Complexity: O(N)
//Space Complexity: O(1)



//OR

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;
//         unordered_map<int,int> mp;
//         for(int i = 0; i < n; i++){
//             mp[nums[i]]++;
//         }

//         for(auto it : mp){
//             if(it.second > n/3){
//                 ans.push_back(it.first);
//             }
//         }
        
//         return ans;
//     }
// };

// Time Complexity: O(N)-> Frequency array(We can use freq array if elements are in range to use) or O(NlogN) -> HashMap 
// Space Complexity: O(N)



//OR

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;
//         vector<bool> visited(n, false);
//         for(int i = 0; i < n; i++){
//             if (visited[i] == true){
//                 continue;
//             }
//             int cnt = 1;
//             for(int j = i+1; j < n; j++){
//                 if(nums[i] == nums[j]){
//                     visited[j] = true;
//                     cnt++;
//                 }
//             }
//             if(cnt > n/3){
//                 ans.push_back(nums[i]);
//             }
//         }
        
//         return ans;
//     }
// };

//Time Complexity: O(N*N)
//Space Complexity:  O(N)



