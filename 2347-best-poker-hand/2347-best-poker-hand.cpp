class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        string ans = "";
        bool isFlush = true;
        for(int i = 0; i < suits.size()-1; i++){
            if(suits[i] != suits[i+1]){
                isFlush = false;
            }
        }
        
        if(isFlush == true){
            ans = "Flush";
            return ans;
        }
        
        int arr[14];
        for(int i = 0; i <= 13; i++){
            arr[i] = 0;
        }
        
        for(int i = 0; i < ranks.size(); i++){
            arr[ranks[i]]++;
        }
        
        bool isPair = false;
        for(int i = 1; i < 14; i++){
            if(arr[i] >= 3){
                ans = "Three of a Kind";
                return ans;
            }
            else if(arr[i] == 2){
                isPair = true;
            }
        }
        
        if(isPair == true){
            ans = "Pair";
            return ans;
        }
        
        ans = "High Card";
        return ans;
    }
};