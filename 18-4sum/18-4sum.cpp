class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.empty()){
            return ans;
        }
        
        int n = nums.size(); 
        sort(nums.begin(), nums.end());       
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                long long int x = (long long int) target - 
                    (long long int) nums[i] - 
                    (long long int) nums[j];
                int l = j + 1;
                int r = n - 1;
                while(l < r){
                    int twoSum = nums[l] + nums[r];
                    if(twoSum < x) l++;
                    else if(twoSum > x) r--;
                    else{
                        vector<int> vec(4,0);
                        vec[0] = nums[i];
                        vec[1] = nums[j];
                        vec[2] = nums[l];
                        vec[3] = nums[r];
                        ans.push_back(vec);
                        
                        // Processing the duplicates of number 3
                        while(l < r && vec[2] == nums[l]) l++;
                        
                        // Processing the duplicates of number 4
                        while(l < r && vec[3] == nums[r]) r--;
                    }
                }
                // Processing the duplicates of number 2
                while(j + 1 < n && nums[j + 1] == nums[j]) j++;
            }
            // Processing the duplicates of number 1
            while(i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        
        return ans;
    }
};