class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int n = nums.size();
        vector<int> arr(n+1,0);
        for(int i = 0; i < n; i++){
            arr[nums[i]]++;
        }
        for(int i = 1; i <= n; i++){
            if(arr[i] == 2){
                ans[0] = i;
            }
            else if(arr[i] == 0){
                ans[1] = i;
            }
        }
        return ans;
    }
};