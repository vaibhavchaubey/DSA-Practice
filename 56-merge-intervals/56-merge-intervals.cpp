class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> tempIntervals = intervals[0];
        
        for(auto it : intervals){
            if(it[0] <= tempIntervals[1]){
                tempIntervals[1] = max(tempIntervals[1], it[1]);
            }
            else{
                ans.push_back(tempIntervals);
                tempIntervals = it;
            }
        }
        ans.push_back(tempIntervals);
        
        return ans;
    }
};

//Time Complexity: O(NlogN)+O(N)
//Space Complexity: O(N)