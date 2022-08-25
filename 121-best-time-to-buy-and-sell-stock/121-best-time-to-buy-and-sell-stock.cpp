class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mxProfit = 0, minSoFar = INT_MAX;
        for(int i = 0; i < n; i++){
            minSoFar = min(minSoFar,prices[i]);
            mxProfit = max(mxProfit,prices[i]-minSoFar);
        }
        return mxProfit;
    }
};


//Time Complexity: O(N)
//Space Complexity: O(1)