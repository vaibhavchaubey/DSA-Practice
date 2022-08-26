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



//OR

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         vector<vector<int>> ans;
//         sort(intervals.begin(), intervals.end());

//         for(int i = 0; i < n; i++){
//             int start = intervals[i][0], end = intervals[i][1];
//             if(!ans.empty()){
//                 if(start <= ans.back()[1]){
//                     continue;
//                 }
//             }
//             for(int j = i+1; j < n; j++){
//                 if(intervals[j][0] <= end){
//                     end = max(end, intervals[j][1]);
//                 }
//             }
//             end = max(end, intervals[i][1]);
//             ans.push_back({start,end});
//         }
        
//         return ans;
//     }
// };

//Time Complexity: O(NlogN)+O(N*N)
//Space Complexity: O(N)
