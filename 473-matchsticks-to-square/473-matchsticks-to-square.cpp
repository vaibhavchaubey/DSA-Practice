class Solution {
public:
    int len;
    bool calc(vector<int>& matchsticks, int l1, int l2, int l3, int l4, int idx){
        if(idx == matchsticks.size()){
            return l1 == len && l2 == l3 && l3 == l4 && l4 == len;    //if all lenghts are equal and no sticks are left then return true;
        }
        
        int cur = matchsticks[idx];      //take the current sticks in all four sides one by one 
        
        if(l1 + cur <= len && calc(matchsticks,l1+cur,l2,l3,l4,idx+1)) return true;
        if(l2 + cur <= len && calc(matchsticks,l1,l2+cur,l3,l4,idx+1)) return true;
        if(l3 + cur <= len && calc(matchsticks,l1,l2,l3+cur,l4,idx+1)) return true;
        if(l4 + cur <= len && calc(matchsticks,l1,l2,l3,l4+cur,idx+1)) return true;
        
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int total = 0;
        for(auto it : matchsticks){
            total += it;
        }
        if(total % 4 != 0){          //checking if sum of all sticks is divisible by 4 or not
            return false;
        }
        len = total/4;              //length of each side will be total /4 because we need to take all sticks
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());    //to avoid edge cases where a very long stick is present at end
        
        return calc(matchsticks,0,0,0,0,0);
    }
};