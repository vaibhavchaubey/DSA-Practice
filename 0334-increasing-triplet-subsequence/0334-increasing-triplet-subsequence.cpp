class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1 = INT_MAX, num2 = INT_MAX;
        for(auto x : nums){
            if(x <= num1){
                num1 = x;     // num1 is min seen so far (it's a candidate for 1st element)
            }
            else if(x <= num2){  // here when x > num1, i.e. x might be either num1 or num2
                num2 = x;
            }
            else{            // here when we have num1 < num2 already and x > num2
                return true;
            }
        }
        return false;
    }
};