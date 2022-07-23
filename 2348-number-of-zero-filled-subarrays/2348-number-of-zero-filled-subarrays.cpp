class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<long long> count;
        long long cnt = 0;
        for(long long i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                cnt++;
            }
            else{
                if(cnt != 0){
                    count.push_back(cnt);
                }
                cnt = 0;
            }
        }
        count.push_back(cnt);
        long long ans = 0;
        for(auto i : count){
            ans += (i*(i+1))/2;
        }
        
        return ans;
    }
};