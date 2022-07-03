class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2){
            return nums.size();
        }
        int prevDiff = nums[1] - nums[0];
        int count = prevDiff != 0 ? 2 : 1;
        
        //if prevDiff is negative than diff will be positive and vice versa
        for( int i = 2; i < nums.size(); i++){
            int diff = nums[i] - nums[i-1];
            if(diff > 0 && prevDiff <= 0 || diff < 0 && prevDiff >= 0){
                count++;
                prevDiff = diff;
            }
        }
        
        return count;
    }
};




//OR

// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         //Remove duplicate elements
//         for(int i = 0; i < nums.size()-1; i++){
//             if(nums[i] == nums[i+1]){
//                 nums.erase(nums.begin()+i);
//                 i--;
//             }
//         }
        
//         //if size is less than or equal to 2, return it's size
//         if(nums.size() <=  2){
//             return nums.size();
//         }
        
//         //Count the number of elements that have either smaller values before and after them or the elements that have greater values before and after them
//         int count = 0;
//         for( int i = 1; i < nums.size()-1; i++){
//             if(nums[i] > nums[i-1] && nums[i] > nums[i+1] || nums[i] < nums[i-1] && nums[i] < nums[i+1]){
//                 count++;
//             }
//         }
        
//         //Add 2 to count for adding first and last element to the result
//         return count+2;
//     }
// };