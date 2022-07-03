class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        
        if(nums.size() <=  2){
            return nums.size();
        }
        
        int count = 0;
        for( int i = 1; i < nums.size()-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1] || nums[i] < nums[i-1] && nums[i] < nums[i+1]){
                count++;
            }
        }
        
        return count+2;
    }
};