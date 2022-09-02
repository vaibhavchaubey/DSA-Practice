class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(n < 0){
            nn = -1 * nn;
        }
        while(nn){
            if(nn % 2 == 1){
                ans = ans * x;
                nn = nn - 1;
            }
            else{
                x = x * x;
                nn = nn/2;
            }
        }
        if(n < 0){
            return (double)(1.0) / (double)(ans);
        }
        return ans;
    }
};

//Time Complexity: O(logN) 
//Space Complexity: O(1)















