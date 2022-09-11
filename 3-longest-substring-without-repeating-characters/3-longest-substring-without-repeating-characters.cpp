class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        int maxLen = 0;
        vector<int> mp(256, -1);      //Because string can have maximum of 256 different characters
        int left = 0, right = 0;
        while(right < n){
            if(mp[s[right]] != -1){
                left = max(mp[s[right]] + 1, left);     //jump
            }
            mp[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N) where N represents the size of HashSet where we are storing our elements



/* Solution 1: Brute force Approach
Approach: This approach consists of taking the two loops one for traversing the string and another loop – nested loop for finding different substrings and after that, we will check for all substrings one by one and check for each and every element if the element is not found then we will store that element in HashSet otherwise we will break from the loop and count it.

Time Complexity: O(N^2)
Space Complexity: O(N)
*/

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         if(n == 0){
//             return 0;
//         }
//         int maxLen = 0;
//         for(int i = 0; i < n; i++){    // outer loop for traversing the string
//             unordered_set<char> set;
//             // nested loop for getting different string starting with s[i]
//             for(int j = i; j < n; j++){   
//                 // if element if found so mark it as ans and break from the loop
//                 if(set.find(s[j]) != set.end()){ 
//                     maxLen = max(maxLen, j - i);
//                     break;
//                 }
//                 set.insert(s[j]);
//             }
//         }
//         return maxLen;
//     }
// };



/* Solution 2: Optimised  Approach 1
Approach: We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point of substring while ‘right’ will maintain the endpoint of the substring.’ right’ pointer will move forward and check for the duplicate occurrence of the current element if found then ‘left’ pointer will be shifted ahead so as to delete the duplicate elements. 

Time Complexity: O(2*N) (sometimes left and right both have to travel complete array)
Space Complexity: O(N) where N is the size of HashSet taken for storing the elements
*/

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         if(n == 0){
//             return 0;
//         }
//         int maxLen = 0;
//         unordered_set<char> set;
//         int l = 0;
//         for(int r = 0; r < n; r++){  
//             if(set.find(s[r]) != set.end()){
//                 while(l < r && set.find(s[r]) != set.end()){
//                     set.erase(s[l]);
//                     l++;
//                 }
//             }
//             set.insert(s[r]);
//             maxLen = max(maxLen, r - l + 1);
//         }
//         return maxLen;
//     }
// };