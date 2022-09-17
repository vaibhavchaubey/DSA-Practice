class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int ans = 0;
        int i = n-1, j = m-1;
        while(i>=0 && j>=0){
            if(players[i] <= trainers[j]){
                ans++;
                i--;
                j--;
            }
            else if(players[i] > trainers[j]){
                i--;
            }
        }
        return ans;       
    }
};