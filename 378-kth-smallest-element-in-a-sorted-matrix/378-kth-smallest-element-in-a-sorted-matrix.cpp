class Solution {
public:
    int m,n;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size();
        int left = matrix[0][0], right = matrix[m-1][n-1], ans = -1;
        while( left <= right){
            int mid = (left+right)/2;
            if(countLessOrEqual(matrix,mid) >= k){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
    
    int countLessOrEqual(vector<vector<int>>& matrix, int x){
        int cnt = 0,  c = n-1;
        for(int r = 0; r < m; r++){
            while(c >= 0 && matrix[r][c] > x){
                c--;
            }
            cnt += (c+1);
        }
        return cnt;
    }
};

// Time: O((M+N) * logD), where M <= 300 is the number of rows, N <= 300 is the number of columns, D <= 2*10^9 is the difference between the maximum element and the minimum element in the matrix.
// Space: O(1).




//OR
////////////////////////////////////////////////////////////////////////////////////
/* Brute Force
Here we doesn't take the advantage that the matrix is already sorted by rows and by columns.
Time: O(M * N * logK)    or   O(N^2logk)    */

// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         priority_queue<int> pq;
//         for(int r = 0; r < matrix.size(); r++){
//             for(int c = 0; c < matrix[r].size(); c++){
//                 pq.push(matrix[r][c]);
                
//                 if(pq.size() > k){
//                     pq.pop();
//                 }
//             }
//         }
//         return pq.top();
//     }
// };