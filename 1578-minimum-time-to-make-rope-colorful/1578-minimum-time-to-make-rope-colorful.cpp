class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0;
        int i = 0, j = 0;
        
        while(i < neededTime.size() && j < neededTime.size()){
            int currTotal = 0, currMax = 0;
            // Find all the balloons having the same color as the 
            // balloon indexed at i, record the total removal time 
            // and the maximum removal time.
            
            while(j < neededTime.size() && colors[i] == colors[j]){
                currTotal += neededTime[j];
                currMax = max(currMax, neededTime[j]);
                j++;
            }
            totalTime += currTotal - currMax;
            i = j;
        }
        
        return totalTime;
    }
};