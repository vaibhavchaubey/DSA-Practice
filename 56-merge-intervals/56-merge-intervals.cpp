class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; i++){
            int start = intervals[i][0], end = intervals[i][1];
            if(!ans.empty()){
                if(start <= ans.back()[1]){
                    continue;
                }
            }
            for(int j = i+1; j < n; j++){
                if(intervals[j][0] <= end){
                    end = max(end, intervals[j][1]);
                }
            }
            end = max(end, intervals[i][1]);
            ans.push_back({start,end});
        }
        
        return ans;
    }
};