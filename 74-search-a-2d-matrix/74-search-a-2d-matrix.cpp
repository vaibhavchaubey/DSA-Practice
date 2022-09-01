class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size(), M = matrix[0].size();
        int lo = 0, hi = N*M-1;
        while(lo <= hi){
            int mid = (lo + (hi - lo)/2);
            //We can get the element at middle index using matrix[middle/m][middle%m]
            if(matrix[mid/M][mid%M] == target){
                return true;
            }
            else if(matrix[mid/M][mid%M] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return false;
    }
};

//Time complexity: O(log(n*m))
//Space complexity: O(1)



// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int N = matrix.size(), M = matrix[0].size();
//         int r = 0, c = M-1;
//         while(r < N && c >= 0){
//             if(matrix[r][c] == target){
//                 return true;
//             }
//             else if(matrix[r][c] > target){
//                 c--;
//             }
//             else{
//                 r++;
//             }
//         }
//         return false;
//     }
// };



