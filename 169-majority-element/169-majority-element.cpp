class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > n/2){
                return nums[i];
            }
        }
        return -1;
    }
};

//Time Complexity: O(N)-> Frequency array or O(N log N) -> HashMap 
//Space Complexity: O(N)


