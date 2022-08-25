class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(auto i : magazine){
            mp[i]++;
        }
        for(auto j : ransomNote){
            mp[j]--;
            if(mp[j] < 0){
                return false;
            }
        }
        return true;
    }
};