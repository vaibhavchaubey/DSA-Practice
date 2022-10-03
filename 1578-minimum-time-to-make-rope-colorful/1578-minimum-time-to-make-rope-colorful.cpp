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
            
            // Once we reach the end of the current group, add the cost of 
            // this group to total_time, and reset two pointers.
            totalTime += currTotal - currMax;
            i = j;
        }
        
        return totalTime;
    }
};

//Approach 1: Two pointers


//OR


//Approach 2: Advanced 1-Pass

// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) {
//         int totalTime = 0, currMaxTime = 0;
        
//         for(int i = 0; i < colors.size(); i++){
//             // If this balloon is the first balloon of a new group
//             // set the currMaxTime as 0.
//             if(i > 0 && colors[i] != colors[i-1]){
//                 currMaxTime = 0;
//             }
            
//             // Increment totalTime by the smaller one.
//             // Update currMaxTime as the larger one.
            
//             totalTime += min(currMaxTime, neededTime[i]);
//             currMaxTime = max(currMaxTime, neededTime[i]);
//         }
        
//         return totalTime;
//     }
// };
