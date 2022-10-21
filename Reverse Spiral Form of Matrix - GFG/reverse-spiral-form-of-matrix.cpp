//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        int r = a.size();
        int c = a[0].size();
        vector<int> ans;
        int row_start = 0, row_end = r-1, column_start = 0, column_end = c-1;
        while(row_start <= row_end && column_start <= column_end){  
            //for row start
            for(int col = column_start; col <= column_end; col++){
                ans.push_back(a[row_start][col]);
            }
            row_start++;
            
            //for column end
            for(int row = row_start; row <= row_end; row++){
                ans.push_back(a[row][column_end]);
            }
            column_end--;
            
            //for row end
            if(row_start <= row_end){
                for(int col = column_end; col >= column_start; col--){
                ans.push_back(a[row_end][col]);
                }
                row_end--;
            }
            
            //for column start
            if(column_start <= column_end){
                for(int row = row_end; row >= row_start; row--){
                ans.push_back(a[row][column_start]);
                }
                column_start++;
            }
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends